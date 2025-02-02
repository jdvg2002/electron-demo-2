from OCC.Core.STEPControl import STEPControl_Reader
from OCC.Core.IFSelect import IFSelect_RetDone
from OCC.Core.BRepMesh import BRepMesh_IncrementalMesh
from OCC.Core.StlAPI import StlAPI_Writer
from OCC.Core.TopExp import TopExp_Explorer
from OCC.Core.BRep import BRep_Tool
from OCC.Core.GeomAdaptor import GeomAdaptor_Surface
from OCC.Core.GeomAbs import GeomAbs_Cylinder
from OCC.Core.TopAbs import TopAbs_FACE, TopAbs_FORWARD
from OCC.Core.TopLoc import TopLoc_Location
import tempfile
import os
import sys
import json
import base64
import numpy as np
from pygltflib import GLTF2, BufferFormat, BufferView, Accessor, Buffer, Mesh, Primitive, Node, Scene
import logging
import time

def convert_step_to_stl(file_path):
    try:
        # Import FreeCAD modules
        sys.path.append('/Applications/FreeCAD.app/Contents/Resources/lib')
        sys.path.append('/Applications/FreeCAD.app/Contents/Resources/lib/python3.11/site-packages')
        os.environ['PATH_TO_FREECAD_LIBDIR'] = '/Applications/FreeCAD.app/Contents/Resources/lib'
        import FreeCAD
        import Import
        from shape_analysis import is_flange, is_bend, is_pipe

        # Create new document and import STEP
        doc = FreeCAD.newDocument()
        Import.insert(file_path, doc.Name)
        
        # Get measurements for each component
        pipe_measurements = []  # Changed to array of component measurements
        components = []
        for obj in doc.RootObjects:
            if hasattr(obj, 'Group'):
                components.extend(obj.Group)
            else:
                components.append(obj)
        
        for obj in components:
            is_likely_flange, flange_chars = is_flange(obj.Shape)
            is_likely_bend, bend_chars = is_bend(obj.Shape)
            is_likely_pipe, pipe_chars = is_pipe(obj.Shape)
            
            component_measurements = {'Component': obj.Label}  # Start with component name
            
            if is_likely_flange:
                component_measurements.update({
                    'Main Diameter': max(flange_chars['main_diameters']),
                    'Bolt Hole Diameter': flange_chars['bolt_diameter'],
                    'Bolt Count': flange_chars['bolt_count']
                })
            elif is_likely_bend:
                component_measurements.update({
                    'Inner Diameter': bend_chars['pipe_diameter'],
                    'Wall Thickness': bend_chars['wall_thickness']
                })
                if bend_chars['bend_angle']:
                    component_measurements['Bend Angle'] = bend_chars['bend_angle']
                if bend_chars['bend_radius']:
                    component_measurements['Bend Radius'] = bend_chars['bend_radius']
            elif is_likely_pipe:
                component_measurements.update({
                    'Inner Diameter': pipe_chars['inner_diameter'],
                    'Outer Diameter': pipe_chars['outer_diameter'],
                    'Wall Thickness': pipe_chars['wall_thickness'],
                    'Length': pipe_chars['length']
                })
            else:
                bbox = obj.Shape.BoundBox
                component_measurements.update({
                    'Length': bbox.XLength,
                    'Width': bbox.YLength,
                    'Height': bbox.ZLength
                })
            
            pipe_measurements.append(component_measurements)

        # Create STL
        step_reader = STEPControl_Reader()
        status = step_reader.ReadFile(file_path)
        if status == IFSelect_RetDone:
            step_reader.TransferRoots()
            shape = step_reader.OneShape()
            
            # Create a combined STL from all shapes
            mesh = BRepMesh_IncrementalMesh(shape, 5.0)
            mesh.Perform()
            
            temp_stl = tempfile.NamedTemporaryFile(delete=False, suffix='.stl')
            stl_writer = StlAPI_Writer()
            stl_writer.Write(shape, temp_stl.name)
            
            # Read in binary mode
            with open(temp_stl.name, 'rb') as f:
                stl_data = f.read()
            
            os.unlink(temp_stl.name)
            
            # Convert binary data to base64 for JSON transport
            stl_base64 = base64.b64encode(stl_data).decode('utf-8')
            
            return json.dumps({
                'success': True,
                'stl_data': stl_base64,
                'pipe_measurements': pipe_measurements
            })
        
        return json.dumps({
            'success': False,
            'error': 'Failed to read STEP file'
        })
        
    except Exception as e:
        return json.dumps({
            'success': False,
            'error': str(e)
        })

def convert_step_to_gltf(file_path):
    start_time = time.time()
    metrics = {
        'timings': {},
        'sizes': {}
    }
    
    try:
        metrics['sizes']['input_file'] = os.path.getsize(file_path)
        logging.info(f"Starting STEP conversion for: {os.path.basename(file_path)} ({metrics['sizes']['input_file'] / 1024 / 1024:.2f} MB)")

        # Import FreeCAD modules
        import_start = time.time()
        sys.path.append('/Applications/FreeCAD.app/Contents/Resources/lib')
        sys.path.append('/Applications/FreeCAD.app/Contents/Resources/lib/python3.11/site-packages')
        os.environ['PATH_TO_FREECAD_LIBDIR'] = '/Applications/FreeCAD.app/Contents/Resources/lib'
        import FreeCAD
        import Import
        from shape_analysis import is_flange, is_bend, is_pipe
        metrics['timings']['import'] = time.time() - import_start

        # Rest of your existing code, just add timing checkpoints
        doc_start = time.time()
        doc = FreeCAD.newDocument()
        Import.insert(file_path, doc.Name)
        metrics['timings']['document_creation'] = time.time() - doc_start

        # Component analysis timing
        analysis_start = time.time()
        pipe_measurements = []
        components = []
        for obj in doc.RootObjects:
            if hasattr(obj, 'Group'):
                components.extend(obj.Group)
            else:
                components.append(obj)
        
        if not components:
            raise Exception("No components found in STEP file")

        for obj in components:
            if not hasattr(obj, 'Shape'):
                continue
                
            is_likely_flange, flange_chars = is_flange(obj.Shape)
            is_likely_bend, bend_chars = is_bend(obj.Shape)
            is_likely_pipe, pipe_chars = is_pipe(obj.Shape)
            
            component_measurements = {'Component': obj.Label}  # Start with component name
            
            if is_likely_flange and flange_chars:
                component_measurements.update({
                    'Main Diameter': max(flange_chars['main_diameters']) if flange_chars.get('main_diameters') else 0,
                    'Bolt Hole Diameter': flange_chars.get('bolt_diameter', 0),
                    'Bolt Count': flange_chars.get('bolt_count', 0)
                })
            elif is_likely_bend and bend_chars:
                component_measurements.update({
                    'Inner Diameter': bend_chars.get('pipe_diameter', 0),
                    'Wall Thickness': bend_chars.get('wall_thickness', 0)
                })
                if bend_chars.get('bend_angle'):
                    component_measurements['Bend Angle'] = bend_chars['bend_angle']
                if bend_chars.get('bend_radius'):
                    component_measurements['Bend Radius'] = bend_chars['bend_radius']
            elif is_likely_pipe and pipe_chars:
                component_measurements.update({
                    'Inner Diameter': pipe_chars.get('inner_diameter', 0),
                    'Outer Diameter': pipe_chars.get('outer_diameter', 0),
                    'Wall Thickness': pipe_chars.get('wall_thickness', 0),
                    'Length': pipe_chars.get('length', 0)
                })
            else:
                bbox = obj.Shape.BoundBox
                component_measurements.update({
                    'Length': bbox.XLength,
                    'Width': bbox.YLength,
                    'Height': bbox.ZLength
                })
            
            pipe_measurements.append(component_measurements)

        metrics['timings']['component_analysis'] = time.time() - analysis_start

        # Read STEP file for GLTF conversion
        step_reader = STEPControl_Reader()
        status = step_reader.ReadFile(file_path)
        
        if status != IFSelect_RetDone:
            raise Exception('Failed to read STEP file')
            
        step_reader.TransferRoots()
        shape = step_reader.OneShape()
        
        if not shape:
            raise Exception('No shape found in STEP file')

        # Create mesh
        mesh_start = time.time()
        mesh = BRepMesh_IncrementalMesh(shape, 5.0)
        mesh.Perform()
        metrics['timings']['mesh_creation'] = time.time() - mesh_start
        
        if not mesh.IsDone():
            raise Exception('Failed to create mesh')

        # Collect all vertices and triangles
        vertices = []
        triangles = []
        vertex_offset = 0
        
        explorer = TopExp_Explorer(shape, TopAbs_FACE)
        while explorer.More():
            face = explorer.Current()
            location = TopLoc_Location()
            facing = BRep_Tool.Triangulation(face, location)
            
            if facing is not None:
                # Get transformation matrix
                trsf = location.Transformation()
                
                # Add vertices with transformation applied
                for i in range(facing.NbNodes()):
                    node = facing.Node(i+1)
                    # Apply transformation to vertex
                    pnt = node.Transformed(trsf)
                    vertices.append((pnt.X(), pnt.Y(), pnt.Z()))
                
                # Get face orientation directly from the face
                face_orientation = face.Orientation()
                
                # Add triangles with correct orientation and offset
                local_triangles = []
                for tri in facing.Triangles():
                    if face_orientation == TopAbs_FORWARD:
                        local_triangles.append((
                            tri.Value(1) + vertex_offset - 1,
                            tri.Value(2) + vertex_offset - 1,
                            tri.Value(3) + vertex_offset - 1
                        ))
                    else:  # REVERSED orientation
                        local_triangles.append((
                            tri.Value(1) + vertex_offset - 1,
                            tri.Value(3) + vertex_offset - 1,
                            tri.Value(2) + vertex_offset - 1
                        ))
                triangles.extend(local_triangles)
                vertex_offset += facing.NbNodes()
            
            explorer.Next()
        
        # Convert to numpy arrays
        vertices = np.array(vertices, dtype=np.float32)
        triangles = np.array(triangles, dtype=np.uint32)
        
        # Create GLTF
        gltf = GLTF2()
        
        # Debug logging
        logging.info(f"Number of vertices: {len(vertices)}")
        logging.info(f"Number of triangles: {len(triangles)}")
        
        # Add buffer with vertex and index data
        vertex_data = vertices.tobytes()
        index_data = triangles.tobytes()
        buffer_data = vertex_data + index_data
        
        # Create buffer
        buffer = Buffer(
            byteLength=len(buffer_data),
            uri=None  # Required for binary
        )
        gltf.buffers.append(buffer)
        
        # Set the binary data
        gltf.set_binary_blob(buffer_data)
        
        # Add buffer views
        gltf.bufferViews.append(BufferView(
            buffer=0,
            byteOffset=0,
            byteLength=len(vertex_data),
            target=34962  # WebGL constant for ARRAY_BUFFER
        ))
        
        gltf.bufferViews.append(BufferView(
            buffer=0,
            byteOffset=len(vertex_data),
            byteLength=len(index_data),
            target=34963  # WebGL constant for ELEMENT_ARRAY_BUFFER
        ))
        
        # Add accessors
        gltf.accessors.append(Accessor(
            bufferView=0,
            componentType=5126,  # GL constant for FLOAT
            count=len(vertices),
            type="VEC3",
            max=vertices.max(axis=0).tolist(),
            min=vertices.min(axis=0).tolist()
        ))
        
        gltf.accessors.append(Accessor(
            bufferView=1,
            componentType=5125,  # GL constant for UNSIGNED_INT
            count=len(triangles) * 3,
            type="SCALAR"
        ))
        
        # Add mesh
        gltf.meshes.append(Mesh(
            primitives=[
                Primitive(
                    attributes={"POSITION": 0},
                    indices=1
                )
            ]
        ))
        
        # Add node and scene
        gltf.nodes.append(Node(mesh=0))
        gltf.scenes.append(Scene(nodes=[0]))
        gltf.scene = 0
        
        # Save as GLB
        gltf_start = time.time()
        temp_glb = tempfile.NamedTemporaryFile(delete=False, suffix='.glb')
        gltf.save_binary(temp_glb.name)
        
        metrics['sizes']['output_file'] = os.path.getsize(temp_glb.name)
        metrics['timings']['gltf_conversion'] = time.time() - gltf_start

        with open(temp_glb.name, 'rb') as f:
            glb_data = f.read()
        
        os.unlink(temp_glb.name)
        glb_base64 = base64.b64encode(glb_data).decode('utf-8')
        
        total_time = time.time() - start_time
        
        # Only log metrics that exist
        logging.info("Performance Metrics:")
        logging.info(f"Input STEP size: {metrics['sizes'].get('input_file', 0) / 1024 / 1024:.2f} MB")
        logging.info(f"Output GLB size: {metrics['sizes'].get('output_file', 0) / 1024 / 1024:.2f} MB")
        for key, value in metrics['timings'].items():
            logging.info(f"{key.replace('_', ' ').title()}: {value:.2f}s")
        logging.info(f"Total time: {total_time:.2f}s")

        return json.dumps({
            'success': True,
            'gltf_data': glb_base64,
            'pipe_measurements': pipe_measurements,
            'performance_metrics': {
                'timings': metrics['timings'],
                'sizes': metrics['sizes'],
                'total_time': total_time
            }
        })

    except Exception as e:
        import traceback
        logging.error(f"Error in convert_step_to_gltf: {str(e)}\n{traceback.format_exc()}")
        return json.dumps({
            'success': False,
            'error': str(e)
        })

if __name__ == '__main__':
    import logging
    logging.basicConfig(level=logging.INFO)
    
    if len(sys.argv) != 2:
        print(json.dumps({
            'success': False,
            'error': 'Missing file path argument'
        }))
        sys.exit(1)
    
    print(convert_step_to_gltf(sys.argv[1])) 