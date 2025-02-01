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
        print("Starting STEP file processing...")
        
        # Import FreeCAD modules
        sys.path.append('/Applications/FreeCAD.app/Contents/Resources/lib')
        sys.path.append('/Applications/FreeCAD.app/Contents/Resources/lib/python3.11/site-packages')
        os.environ['PATH_TO_FREECAD_LIBDIR'] = '/Applications/FreeCAD.app/Contents/Resources/lib'
        import FreeCAD
        import Import
        from shape_analysis import is_flange, is_bend, is_pipe

        print("Importing STEP file...")
        doc = FreeCAD.newDocument()
        Import.insert(file_path, doc.Name)
        
        print("Processing components...")
        components = []
        for obj in doc.RootObjects:
            if hasattr(obj, 'Group'):
                components.extend(obj.Group)
            else:
                components.append(obj)
        
        pipe_measurements = []
        total_components = len(components)
        
        for i, obj in enumerate(components):
            print(f"Processing component {i+1} of {total_components}")
            component_measurements = {'Component': obj.Label}
            pipe_measurements.append(component_measurements)
        
        print("Creating STL mesh...")
        step_reader = STEPControl_Reader()
        status = step_reader.ReadFile(file_path)
        
        if status == IFSelect_RetDone:
            step_reader.TransferRoots()
            shape = step_reader.OneShape()
            
            print("Generating mesh...")
            mesh = BRepMesh_IncrementalMesh(shape, 0.1)
            mesh.Perform()
            
            print("Writing STL file...")
            temp_stl = tempfile.NamedTemporaryFile(delete=False, suffix='.stl')
            stl_writer = StlAPI_Writer()
            stl_writer.Write(shape, temp_stl.name)
            
            print("Reading STL data...")
            with open(temp_stl.name, 'rb') as f:
                stl_data = f.read()
            
            os.unlink(temp_stl.name)
            
            print("Converting to base64...")
            stl_base64 = base64.b64encode(stl_data).decode('utf-8')
            
            # Final result as JSON
            print(json.dumps({
                'success': True,
                'stl_data': stl_base64,
                'pipe_measurements': pipe_measurements
            }))
            return
            
        print(json.dumps({
            'success': False,
            'error': 'Failed to read STEP file'
        }))
        
    except Exception as e:
        print(json.dumps({
            'success': False,
            'error': str(e)
        }))

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print(json.dumps({
            'success': False,
            'error': 'Missing file path argument'
        }))
        sys.exit(1)
    
    print(convert_step_to_stl(sys.argv[1])) 