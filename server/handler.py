import os
import logging
import traceback
import sys
import platform
from Variable import Variable
from Mesh import Mesh, MeshType
from Calculation import Calculation, CalculationType
from Distribution import Distribution, DistributionType

logging.basicConfig(level=logging.INFO)

def write_dakota_input(filename, variables: list[Variable], calculation: Calculation):
    try:
        # Get the absolute path to the calculation script
        script_name = f"{calculation.calculation_type.name.lower()}.py"
        script_path = os.path.abspath(os.path.join(os.path.dirname(__file__), script_name))
        
        if not os.path.exists(script_path):
            raise FileNotFoundError(f"Calculation script not found at: {script_path}")

        with open(filename, "w") as f:
            f.write("environment\n")
            f.write("  tabular_data\n")
            f.write('    tabular_data_file = "dakota_output.dat"\n\n')
            
            f.write("method\n")
            f.write("  sampling\n")
            f.write("    sample_type random\n")
            f.write("    samples = 100\n")
            f.write("    seed = 1234\n\n")
            
            f.write("model\n")
            f.write("  single\n\n")
            
            f.write("interface\n")
            f.write("  fork\n")
            f.write('    parameters_file = "params.in"\n')
            f.write('    results_file = "results.out"\n')
            f.write(f'    analysis_driver = "python {script_path}"\n\n')
            
            f.write("variables\n")
            num_vars = len(variables)
            f.write(f"  normal_uncertain = {num_vars}\n")
            
            means = []
            stdevs = []
            descs = []
            for var in variables:
                means.append(str(var.value))
                stdevs.append(str(var.uncertainty))
                descs.append(var.name)
            
            f.write("    means = " + " ".join(means) + "\n")
            f.write("    std_deviations = " + " ".join(stdevs) + "\n")
            f.write("    descriptors = " + " ".join(f'"{d}"' for d in descs) + "\n\n")
            
            f.write("responses\n")
            f.write("  response_functions = 1\n")
            f.write("    no_gradients\n")
            f.write("    no_hessians\n")
            
    except Exception as e:
        logging.error(f"Failed to write Dakota input file: {str(e)}")
        logging.error(f"Traceback: {traceback.format_exc()}")
        raise

def run_dakota_analysis(variables: list[Variable], mesh=Mesh(mesh_type=MeshType.PIPE), calculation=Calculation(calculation_type=CalculationType.FLOW_STRESS)):
    current_dir = os.getcwd()
    project_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    
    try:
        logging.info(f"Current working directory: {current_dir}")
        logging.info(f"Project root directory: {project_root}")
        
        # Create dakota directory if it doesn't exist
        dakota_dir = os.path.join(project_root, "dakota")
        os.makedirs(dakota_dir, exist_ok=True)
        
        # Determine platform and set Dakota executable path
        if os.name == 'nt':  # Windows
            dakota_platform = "dakota-6.21.0-public-windows.Windows.x86_64-cli"
            dakota_exe = "dakota.exe"
        elif sys.platform == 'darwin':  # macOS
            if platform.machine() == 'arm64':
                dakota_platform = "dakota-6.21.0-public-darwin.Darwin.arm64-cli"
            else:
                dakota_platform = "dakota-6.19.0-public-darwin.Darwin.x86_64-cli"
            dakota_exe = "dakota"
            
            logging.info(f"Detected macOS platform: {platform.machine()}")
            logging.info(f"Selected Dakota platform: {dakota_platform}")
            
            # Clear quarantine attributes and set permissions on macOS
            dakota_install_dir = os.path.join(dakota_dir, dakota_platform)
            dakota_bin_dir = os.path.join(dakota_install_dir, "bin")
            dakota_path = os.path.join(dakota_bin_dir, dakota_exe)
            
            logging.info(f"Dakota install directory: {dakota_install_dir}")
            logging.info(f"Dakota binary directory: {dakota_bin_dir}")
            logging.info(f"Dakota executable path: {dakota_path}")
            
            if os.path.exists(dakota_install_dir):
                # Clear quarantine
                os.system(f'xattr -cr "{dakota_install_dir}"')
                logging.info("Cleared quarantine attributes")
                
                # Set executable permissions
                if os.path.exists(dakota_path):
                    os.system(f'chmod +x "{dakota_path}"')
                    logging.info(f"Set executable permissions on {dakota_path}")
                    
                    # Verify permissions
                    if os.access(dakota_path, os.X_OK):
                        logging.info("Dakota executable has correct permissions")
                    else:
                        logging.error("Dakota executable does not have execute permission")
                else:
                    logging.error(f"Dakota executable not found at: {dakota_path}")
            else:
                logging.error(f"Dakota install directory does not exist: {dakota_install_dir}")
        else:  # Linux
            # Try to detect RHEL version
            rhel_version = None
            try:
                with open('/etc/redhat-release', 'r') as f:
                    release_info = f.read().lower()
                    if 'release 7' in release_info:
                        rhel_version = 7
                    elif 'release 8' in release_info:
                        rhel_version = 8
            except:
                pass
            
            # Default to RHEL 8 if we can't determine version or not RHEL
            if rhel_version == 7:
                dakota_platform = "dakota-6.19.0-public-rhel7.Linux.x86_64-cli"
            else:
                dakota_platform = "dakota-6.21.0-public-rhel8.Linux.x86_64-cli"
            dakota_exe = "dakota"
            
            # Set executable permissions on Linux
            dakota_install_dir = os.path.join(dakota_dir, dakota_platform, "bin")
            if os.path.exists(dakota_install_dir):
                os.system(f'chmod +x "{os.path.join(dakota_install_dir, dakota_exe)}"')
            
        dakota_path = os.path.join(dakota_dir, dakota_platform, "bin", dakota_exe)
        logging.info(f"Full Dakota executable path: {os.path.abspath(dakota_path)}")
        logging.info(f"Path exists: {os.path.exists(dakota_path)}")
        
        if not os.path.exists(dakota_path):
            raise FileNotFoundError(f"Dakota executable not found at: {dakota_path}")
            
        if not os.access(dakota_path, os.X_OK):
            raise PermissionError(f"Dakota executable does not have execute permission: {dakota_path}")
        
        # Write Dakota input file with calculation type
        dakota_input = os.path.join(dakota_dir, "dakota_input.in")
        write_dakota_input(dakota_input, variables, calculation)
        
        # Change to dakota directory
        os.chdir(dakota_dir)
        
        # Run Dakota with platform-specific executable
        dakota_command = f'"{dakota_path}" -i dakota_input.in -o dakota_output.out'
        logging.info(f"Executing Dakota command: {dakota_command}")
        result = os.system(dakota_command)
        logging.info(f"Dakota execution result code: {result}")
        
        if result != 0:
            # Check if output file exists and contains error information
            output_file = os.path.join(dakota_dir, "dakota_output.out")
            error_msg = f"Dakota execution failed with return code: {result}"
            if os.path.exists(output_file):
                with open(output_file, 'r') as f:
                    error_msg += f"\nDakota output:\n{f.read()}"
            raise RuntimeError(error_msg)
            
        os.chdir(current_dir)
        
        return os.path.join(dakota_dir, "dakota_output.dat")
        
    except Exception as e:
        raise
    finally:
        if os.getcwd() != current_dir:
            os.chdir(current_dir)

def analysis_setup(variables: list[Variable], mesh=Mesh(mesh_type=MeshType.PIPE), calculation=None):
    try:
        if mesh.mesh_type.name.lower() != "pipe":
            raise ValueError("Currently only pipe mesh type is supported")
            
        if calculation.calculation_type.name.lower() not in ["flow_stress", "fatigue_crack_init"]:
            raise ValueError("Currently only flow_stress and fatigue_crack_init calculations are supported")
            
        if variables is None:
            raise ValueError("Must provide variables")

        output_file = run_dakota_analysis(variables, mesh, calculation)
        
        # Read and parse the Dakota output file
        results = []
        with open(output_file, 'r') as f:
            # Skip the header line
            next(f)
            for line in f:
                values = line.split()
                if calculation.calculation_type.name.lower() == "fatigue_crack_init":
                    result_dict = {
                        'eval_id': int(values[0]),
                        'stress_range_scaling': float(values[2])
                    }
                else:  # flow_stress
                    result_dict = {
                        'eval_id': int(values[0]),
                        'T': float(values[2]),
                        'sigma_f': float(values[3]),
                        'response_fn_1': float(values[5])
                    }
                results.append(result_dict)
        
        return results
        
    except Exception as e:
        raise

def main(preprocessed_data=None, calculation_type=None):
    try:
        if preprocessed_data:
            # Extract variables from preprocessed data
            variables = []
            for dist in preprocessed_data['data']['files'][0]['distributions'].values():
                variables.append(
                    Variable(
                        name=dist['name'].split(' ')[0],
                        value=dist['mean'],
                        distribution=Distribution(DistributionType.NORMAL),
                        uncertainty=dist['stdDev']
                    )
                )
        
            # Map analysis types to calculation types
            calculation_type_mapping = {
                'pipe_failure': 'FLOW_STRESS',
                'fatigue_crack_init': 'FATIGUE_CRACK_INIT'
            }
            
            # Get the correct calculation type from the mapping
            calc_type = calculation_type_mapping.get(calculation_type.lower())
            if not calc_type:
                raise ValueError(f"Unsupported calculation type: {calculation_type}")
                
            # Create Calculation object based on mapped calculation type
            calc = Calculation(CalculationType[calc_type])
            
            # Add more detailed error logging
            logging.info(f"Starting analysis with {len(variables)} variables")
            logging.info(f"Input calculation type: {calculation_type}")
            logging.info(f"Mapped to calculation type: {calc_type}")
            
            try:
                results = analysis_setup(variables, calculation=calc)
                return {
                    "status": "success",
                    "results": results,
                    "errorCode": None
                }
            except Exception as e:
                logging.error(f"Analysis setup failed: {str(e)}")
                logging.error(f"Traceback: {traceback.format_exc()}")
                return {
                    "status": "error",
                    "results": None,
                    "errorCode": f"Analysis error: {str(e)}\n{traceback.format_exc()}"
                }
        
    except Exception as e:
        logging.error(f"Main function failed: {str(e)}")
        logging.error(f"Traceback: {traceback.format_exc()}")
        return {
            "status": "error",
            "results": None,
            "errorCode": f"Main function error: {str(e)}\n{traceback.format_exc()}"
        }

if __name__ == "__main__":
    main()




