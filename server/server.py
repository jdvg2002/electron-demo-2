from OCC.Core.STEPControl import STEPControl_Reader
from OCC.Core.IFSelect import IFSelect_RetDone
from OCC.Core.BRepMesh import BRepMesh_IncrementalMesh
from OCC.Core.StlAPI import StlAPI_Writer
from OCC.Core.TopExp import TopExp_Explorer
from OCC.Core.BRep import BRep_Tool
from OCC.Core.GeomAdaptor import GeomAdaptor_Surface
from OCC.Core.GeomAbs import GeomAbs_Cylinder
from OCC.Core.TopAbs import TopAbs_FACE
import tempfile
import os
import sys
import json
import base64

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

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print(json.dumps({
            'success': False,
            'error': 'Missing file path argument'
        }))
        sys.exit(1)
    
    print(convert_step_to_stl(sys.argv[1])) 