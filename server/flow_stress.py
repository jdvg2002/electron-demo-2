import os
import sys
import platform
import importlib.util
import types
import math
import logging

def load_dakota_interface():
    # Determine platform and set Dakota path
    if os.name == 'nt':  # Windows
        dakota_platform = "dakota-6.21.0-public-windows.Windows.x86_64-cli"
    elif sys.platform == 'darwin':  # macOS
        if platform.machine() == 'arm64':
            dakota_platform = "dakota-6.21.0-public-darwin.Darwin.arm64-cli"
        else:
            dakota_platform = "dakota-6.19.0-public-darwin.Darwin.x86_64-cli"
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
        
        if rhel_version == 7:
            dakota_platform = "dakota-6.19.0-public-rhel7.Linux.x86_64-cli"
        else:
            dakota_platform = "dakota-6.21.0-public-rhel8.Linux.x86_64-cli"
    
    # Get the project root directory
    project_root = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    
    # Create base paths using project root
    base_path = os.path.join(project_root, "dakota", dakota_platform, "share", "dakota", "Python", "dakota", "interfacing")
    dprepro_path = os.path.abspath(os.path.join(base_path, "dprepro.py"))
    interface_path = os.path.abspath(os.path.join(base_path, "interfacing.py"))

    if not os.path.exists(dprepro_path):
        raise ImportError(f"Dakota dprepro module not found at: {dprepro_path}")
    if not os.path.exists(interface_path):
        raise ImportError(f"Dakota interface module not found at: {interface_path}")
    if not os.path.exists(base_path):
        raise FileNotFoundError(f"Dakota base path not found: {base_path}")

    # Create package structure
    dakota = types.ModuleType("dakota")
    dakota.interfacing = types.ModuleType("dakota.interfacing")
    sys.modules["dakota"] = dakota
    sys.modules["dakota.interfacing"] = dakota.interfacing

    # Load dprepro
    dprepro_spec = importlib.util.spec_from_file_location("dakota.interfacing.dprepro", dprepro_path)
    dprepro = importlib.util.module_from_spec(dprepro_spec)
    sys.modules["dakota.interfacing.dprepro"] = dprepro
    dprepro_spec.loader.exec_module(dprepro)
    dakota.interfacing.dprepro = dprepro

    # Load interfacing
    interface_spec = importlib.util.spec_from_file_location("dakota.interfacing.interfacing", interface_path)
    di = importlib.util.module_from_spec(interface_spec)
    sys.modules["dakota.interfacing.interfacing"] = di
    interface_spec.loader.exec_module(di)
    
    logging.info(f"Project root: {project_root}")
    logging.info(f"Base path: {base_path}")
    logging.info(f"Dprepro path: {dprepro_path}")
    logging.info(f"Interface path: {interface_path}")
    
    return di

# Load Dakota interface
di = load_dakota_interface()

def flow_stress(T, sigma_f, phi):
    if T <= 0:
        raise ValueError("Force (T) must be positive")

    area = 0.5 * math.pi * (phi**2)

    sigma_m = T/area
    safety_factor = sigma_f/sigma_m

    return sigma_m, safety_factor

if __name__ == "__main__":
    # Dakota parameters
    params = di.read_parameters_file()[0]
    phi = params['phi']
    T = params['T']
    sigma_f = params['sigma_f']
    
    sigma_m, safety_factor = flow_stress(T, sigma_f, phi)
    
    # Write results to Dakota's output file
    with open("results.out", "w") as f:
        f.write(f"{sigma_m}\n")