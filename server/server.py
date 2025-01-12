from flask import Flask, request, jsonify
from flask_cors import CORS
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

app = Flask(__name__)
CORS(app)

@app.route('/health')
def health_check():
    return jsonify({'status': 'healthy'})

@app.route('/convert', methods=['POST'])
def convert_step():
    if 'file' not in request.files:
        return jsonify({'error': 'No file provided'}), 400
    
    file = request.files['file']
    if not file.filename.lower().endswith(('.step', '.stp')):
        return jsonify({'error': 'Invalid file format'}), 400

    # Save uploaded file temporarily
    temp_step = tempfile.NamedTemporaryFile(delete=False, suffix='.step')
    file.save(temp_step.name)
    
    try:
        # Read STEP file
        step_reader = STEPControl_Reader()
        status = step_reader.ReadFile(temp_step.name)
        
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
            
            # Read STL file and return its content
            with open(temp_stl.name, 'rb') as f:
                stl_data = f.read()
            
            # Clean up temporary files
            os.unlink(temp_step.name)
            os.unlink(temp_stl.name)
            
            return jsonify({
                'success': True,
                'stl_data': stl_data.decode('utf-8'),
                'pipe_measurements': pipe_measurements
            })
        
        return jsonify({'error': 'Failed to read STEP file'}), 400
        
    except Exception as e:
        return jsonify({'error': str(e)}), 500

if __name__ == '__main__':
    try:
        print("Starting server on port 5001...")
        app.run(host='0.0.0.0', port=5001, debug=True)
    except OSError as e:
        if "Address already in use" in str(e):
            print("Port 5001 is already in use. Trying to kill existing process...")
            os.system("kill -9 $(lsof -t -i:5001)")
            print("Retrying server start...")
            app.run(host='0.0.0.0', port=5001, debug=True)
        else:
            print(f"Error starting server: {e}", file=sys.stderr)
            sys.exit(1) 