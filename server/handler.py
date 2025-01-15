import os
import logging
import traceback
import sys
import platform
from Variable import Variable
from Mesh import Mesh, MeshType
from Calculation import Calculation, CalculationType
from Distribution import Distribution, DistributionType

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
        raise

def run_dakota_analysis(variables: list[Variable], mesh=Mesh(mesh_type=MeshType.PIPE), calculation=Calculation(calculation_type=CalculationType.FLOW_STRESS)):
    try:
        # Create dakota directory if it doesn't exist
        os.makedirs("dakota", exist_ok=True)
        
        # Determine platform and set Dakota executable path
        if os.name == 'nt':  # Windows
            dakota_platform = "dakota-6.21.0-public-windows.Windows.x86_64-cli"
            dakota_exe = "dakota.exe"
            
            # Check and decompress libraries if needed
            lib_dir = os.path.join("dakota", dakota_platform, "lib")
            for lib_file in ["colin.lib", "dakota_src.lib"]:
                lib_path = os.path.join(lib_dir, lib_file)
                zip_path = lib_path + ".zip"
                
                if not os.path.exists(lib_path) and os.path.exists(zip_path):
                    import zipfile
                    with zipfile.ZipFile(zip_path, 'r') as zip_ref:
                        zip_ref.extractall(lib_dir)
                        
        elif sys.platform == 'darwin':  # macOS
            if platform.machine() == 'arm64':
                dakota_platform = "dakota-6.21.0-public-darwin.Darwin.arm64-cli"
            else:
                dakota_platform = "dakota-6.19.0-public-darwin.Darwin.x86_64-cli"
            dakota_exe = "dakota"
            
            # Clear quarantine attributes on macOS
            dakota_install_dir = os.path.join("dakota", dakota_platform)
            if os.path.exists(dakota_install_dir):
                os.system(f'xattr -cr "{dakota_install_dir}"')
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
            dakota_install_dir = os.path.join("dakota", dakota_platform, "bin")
            if os.path.exists(dakota_install_dir):
                os.system(f'chmod +x "{os.path.join(dakota_install_dir, dakota_exe)}"')
            
        dakota_path = os.path.join("dakota", dakota_platform, "bin", dakota_exe)
        
        if not os.path.exists(dakota_path):
            raise FileNotFoundError(f"Dakota executable not found at: {dakota_path}")
        
        # Write Dakota input file with calculation type
        dakota_input = os.path.join("dakota", "dakota_input.in")
        write_dakota_input(dakota_input, variables, calculation)
        
        # Store current directory and change to dakota directory
        current_dir = os.getcwd()
        os.chdir("dakota")
        
        # Run Dakota with platform-specific executable
        dakota_command = f'"{os.path.join("..", dakota_path)}" -i dakota_input.in -o dakota_output.out'
        result = os.system(dakota_command)
        
        if result != 0:
            raise RuntimeError(f"Dakota execution failed with return code: {result}")
            
        os.chdir(current_dir)
        
        return os.path.join("dakota", "dakota_output.dat")
        
    except Exception as e:
        raise
    finally:
        # Make sure we change back to original directory even if there's an error
        if os.getcwd() != current_dir:
            os.chdir(current_dir)

def analysis_setup(variables: list[Variable], mesh=Mesh(mesh_type=MeshType.PIPE), calculation=Calculation(calculation_type=CalculationType.FLOW_STRESS)):
    try:
        if mesh.mesh_type.name.lower() != "pipe":
            raise ValueError("Currently only pipe mesh type is supported")
            
        if calculation.calculation_type.name.lower() != "flow_stress":
            raise ValueError("Currently only flow_stress calculation is supported")
            
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
                result_dict = {
                    'eval_id': int(values[0]),
                    'T': float(values[3]),
                    'sigma_f': float(values[4]),
                    'response_fn_1': float(values[5])
                }
                results.append(result_dict)
        
        return results
        
    except Exception as e:
        raise

def main():
    try:
        variables = [
            Variable(name="T", value=15000, distribution=Distribution(DistributionType.NORMAL), uncertainty=5000),
            Variable(name="sigma_f", value=50000, distribution=Distribution(DistributionType.NORMAL), uncertainty=5000),
            Variable(name="phi", value=1, distribution=Distribution(DistributionType.NORMAL), uncertainty=0.1)
        ]
        
        results = analysis_setup(variables) 
        return {
            "status": "success",
            "results": results,
            "errorCode": None
        }
        
    except Exception as e:
        return {
            "status": "error",
            "results": None,
            "errorCode": str(e)
        }

if __name__ == "__main__":
    main()




