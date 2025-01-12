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

def convert_step_to_stl(file_path):
    try:
        # Read STEP file
        step_reader = STEPControl_Reader()
        status = step_reader.ReadFile(file_path)
        
        if status == IFSelect_RetDone:
            step_reader.TransferRoots()
            shape = step_reader.OneShape()
            
            # Get cylindrical measurements
            diameters = set()
            explorer = TopExp_Explorer(shape, TopAbs_FACE)
            while explorer.More():
                face = explorer.Current()
                surface = BRep_Tool.Surface(face)
                adaptor = GeomAdaptor_Surface(surface)
                
                if adaptor.GetType() == GeomAbs_Cylinder:
                    cylinder = adaptor.Cylinder()
                    diameter = round(cylinder.Radius() * 2, 2)
                    diameters.add(diameter)
                
                explorer.Next()
            
            diameters = sorted(diameters)
            pipe_measurements = {}
            if len(diameters) >= 2:
                pipe_measurements = {
                    'inner_diameter': diameters[0],
                    'outer_diameter': diameters[-1],
                    'wall_thickness': (diameters[-1] - diameters[0])/2
                }
            
            # Create mesh
            mesh = BRepMesh_IncrementalMesh(shape, 0.1)
            mesh.Perform()
            
            # Convert to STL
            temp_stl = tempfile.NamedTemporaryFile(delete=False, suffix='.stl')
            stl_writer = StlAPI_Writer()
            stl_writer.Write(shape, temp_stl.name)
            
            # Read STL file content
            with open(temp_stl.name, 'r') as f:
                stl_data = f.read()
            
            # Clean up temporary file
            os.unlink(temp_stl.name)
            
            return json.dumps({
                'success': True,
                'stl_data': stl_data,
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