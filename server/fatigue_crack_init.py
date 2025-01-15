import math

def crack_init_fatigue(
    num_angular_divisions,   # total_cycles_divisions: Total number of angular divisions for phase calculation
    selected_angular_index,  # selected_cycle_division: Which cycle increment we are focusing on
    num_epistemic_cases,     # num_stress_blocks: Number of outer epistemic stress scenarios
    num_aleatory_samples,    # num_stress_levels: Number of aleatory stress realizations per epistemic case
    fatigue_mode,            # fatigue_mode: Defines calculation method (1-5)
    phase_fraction,          # phase_fraction: Fractional phase offset (in [0,1))

    # Epistemic inputs (outer loop)
    cycles_per_case,         # cycles_per_block: Number of cycles per epistemic case
    stress_factor_per_case,  # stress_factor_per_block: Factor associated with each epistemic case

    # Aleatory inputs (inner loop, within each epistemic case)
    cycles_per_realization,  # load_cycles_per_level: Randomized applied cycles per stress level
    stress_normalizer,       # stress_normalizer: Normalization factor for stress amplitude calculations
    max_stress_realization,  # max_stress_levels: Maximum stress observed in each aleatory realization
    min_stress_realization,  # min_stress_levels: Minimum stress observed in each aleatory realization
    mean_stress_estimate_1,  # mean_stress_1: First statistical mean stress estimate
    mean_stress_estimate_2,  # mean_stress_2: Second statistical mean stress estimate

    # User-defined damage (only used when fatigue_mode == 5)
    user_defined_damage,     # user_defined_damage: Precomputed crack growth data if using mode 5

    # Environmental & material properties
    temperature_factor,       # temperature_factor: \( T^* \) - Temperature-based correction factor (0-100%)
    reference_stress,         # reference_stress: Used in amplitude normalization
    stress_range_scaling,     # stress_range_scaling: Scaling factor for stress intensity range
    fatigue_threshold,        # fatigue_threshold: Amplitude threshold below which no damage occurs
    baseline_exponent_offset, # baseline_exponent_offset: \( C_0 \) - Baseline exponent offset term
    surface_factor,           # surface_factor: \( F_\text{surf} \) - Surface roughness effect
    loading_factor,           # loading_factor: \( F_\text{load} \) - Loading application effect
    calibration_factor        # calibration_factor: \( F_\text{cal} \) - User-defined calibration factor
):
    """Fatigue crack initiation time calculation with epistemic/aleatory distinction in variables."""
    
    error_code = 0

    # Basic validation checks
    if not (1 <= num_angular_divisions <= 100): error_code = 0x65
    if not (1 <= selected_angular_index <= num_angular_divisions): error_code = 0x66
    if not (1 <= num_epistemic_cases <= 10): error_code = 0x67
    if not (1 <= num_aleatory_samples <= 30): error_code = 0x68
    if not (1 <= fatigue_mode <= 5): error_code = 0x69
    if not (0.0 <= phase_fraction < 1.0): error_code = 0x6a

    # Check aleatory cycles per realization
    for val in cycles_per_realization:
        if val <= 0.0 and (not math.isnan(val)): error_code = 0x6d

    # Check epistemic cycles and stress factors, then iterate over aleatory uncertainty
    for i in range(num_epistemic_cases):
        case_cycles = cycles_per_case[i]
        if case_cycles <= 0.0 and (not math.isnan(case_cycles)): error_code = 0x6b
        case_stress_factor = stress_factor_per_case[i]
        if case_stress_factor <= 0.0 and (not math.isnan(case_stress_factor)): error_code = 0x6c
        for j in range(num_aleatory_samples):
            norm_factor = stress_normalizer[i][j]
            if norm_factor <= 0.0 and (not math.isnan(norm_factor)): error_code = 0x6e
            max_stress = max_stress_realization[i][j]
            min_stress = min_stress_realization[i][j]
            if (max_stress < min_stress) and (not math.isnan(max_stress) and not math.isnan(min_stress)): error_code = 0x6f
            mean_stress_1 = mean_stress_estimate_1[i][j]
            mean_stress_2 = mean_stress_estimate_2[i][j]
            if (mean_stress_1 < mean_stress_2) and (not math.isnan(mean_stress_1) and not math.isnan(mean_stress_2)): error_code = 0x71
            if fatigue_mode == 5 and user_defined_damage[i][j] <= 0.0 and not math.isnan(user_defined_damage[i][j]): error_code = 0x73

    # Validate environmental/material properties
    if not (0.0 <= temperature_factor <= 100.0): error_code = 0x74
    if reference_stress <= 0.0 and not math.isnan(reference_stress): error_code = 0x75
    if stress_range_scaling <= 0.0 and not math.isnan(stress_range_scaling): error_code = 0x76
    if fatigue_threshold <= 0.0 and not math.isnan(fatigue_threshold): error_code = 0x77
    if baseline_exponent_offset <= 0.0 and not math.isnan(baseline_exponent_offset): error_code = 0x78
    if surface_factor <= 0.0 and not math.isnan(surface_factor): error_code = 0x79
    if loading_factor <= 0.0 and not math.isnan(loading_factor): error_code = 0x7a
    if calibration_factor <= 0.0 and not math.isnan(calibration_factor): error_code = 0x7b

    # Initial values
    angle_offset = -1.0
    time_to_initiation = -1.0

    if error_code < 0x65:
        # Compute phase angle
        two_pi = 6.2831854820251465
        inc_angle = two_pi / float(num_angular_divisions)
        angle_offset = inc_angle * (phase_fraction + (selected_angular_index - 1)) - 0.5 * inc_angle
        if angle_offset < 0.0 and (not math.isnan(angle_offset)): angle_offset += two_pi

        # Iterate over epistemic cases
        total_damage = 0.0
        total_cycles = 0.0
        for i in range(num_epistemic_cases):
            local_damage = 0.0
            previous_damage = total_damage
            previous_cycles = total_cycles

            # Iterate over aleatory realizations
            for j in range(num_aleatory_samples):
                stress_amp = ((max_stress_realization[i][j] - min_stress_realization[i][j]) * 100.0) / (2.0 * reference_stress)
                if stress_amp >= fatigue_threshold:
                    norm_factor = stress_normalizer[i][j]
                    damage_factor = (stress_amp - fatigue_threshold) * (1.0 / stress_range_scaling)
                    log_damage = math.log(damage_factor) if damage_factor > 0 else 0.0
                    sqrt_term = math.sqrt(log_damage * surface_factor * loading_factor * calibration_factor)
                    adjusted_damage = baseline_exponent_offset - sqrt_term
                    life_cycles = math.exp(adjusted_damage) if not math.isnan(adjusted_damage) else 0.0
                    partial_damage = cycles_per_realization[j] / life_cycles if life_cycles != 0 else 0.0
                else:
                    partial_damage = 0.0

                local_damage += partial_damage

            total_damage += local_damage * cycles_per_case[i]
            total_cycles += cycles_per_case[i]

            if total_damage >= 1.0:
                time_to_initiation = previous_cycles + ((1.0 - previous_damage) / local_damage) if local_damage != 0 else previous_cycles
                break

    if time_to_initiation < 0.0:
        time_to_initiation = 999.0

    return time_to_initiation, angle_offset, error_code


def main():
    # Example parameters
    params = {
        'num_angular_divisions': 36,
        'selected_angular_index': 1,
        'num_epistemic_cases': 1,
        'num_aleatory_samples': 1,
        'fatigue_mode': 1,
        'phase_fraction': 0.0,
        'cycles_per_case': [100.0],
        'stress_factor_per_case': [1.0],
        'cycles_per_realization': [0.1],
        'stress_normalizer': [[1.0]],
        'max_stress_realization': [[200.0]],
        'min_stress_realization': [[0.0]],
        'mean_stress_estimate_1': [[100.0]],
        'mean_stress_estimate_2': [[100.0]],
        'user_defined_damage': [[1.0]],
        'temperature_factor': 50.0,
        'reference_stress': 100.0,
        'stress_range_scaling': 1.0,
        'fatigue_threshold': 10.0,
        'baseline_exponent_offset': 12.0,
        'surface_factor': 1.0,
        'loading_factor': 1.0,
        'calibration_factor': 1.0
    }
    
    # Call the function
    time_to_init, angle, error = crack_init_fatigue(**params)
    
    # Return structured results
    return {
        "timeToInitiation": float(time_to_init),
        "angleOffset": float(angle),
        "errorCode": hex(error)
    }

if __name__ == "__main__":
    main()