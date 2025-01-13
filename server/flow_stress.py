import dakota.interfacing as di
import math

def flow_stress(T, sigma_f, phi):
    if T <= 0:
        raise ValueError("Force (T) must be positive")

    area = 0.5* math.pi*(phi**2)

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

    
    # Print detailed results
    #print(f"Primary membrane stress: {sigma_m:2.4f}")
    #print(f"Safety factor: {safety_factor:2.4f}")
    
    # Write results to Dakota's output file
    with open("results.out", "w") as f:
        f.write(f"{sigma_m}\n")