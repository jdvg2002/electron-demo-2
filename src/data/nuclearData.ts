import type {
    TemperatureDataPoint,
    FluxDataPoint,
    SafetyMarginDataPoint,
    CoolantDataPoint,
    ChartConfig,
    NotebookCell
  } from '../types/nuclear';
  
  // Chart Data
  export const temperatureData: TemperatureDataPoint[] = [
    { position: 0, temp: 320, limit: 400 },
    { position: 50, temp: 350, limit: 400 },
    { position: 100, temp: 380, limit: 400 },
    { position: 150, temp: 360, limit: 400 },
    { position: 200, temp: 340, limit: 400 },
    { position: 250, temp: 310, limit: 400 },
  ];
  
  export const fluxData: FluxDataPoint[] = [
    { position: 'A1', flux: 2.1 },
    { position: 'A2', flux: 2.4 },
    { position: 'A3', flux: 2.8 },
    { position: 'B1', flux: 1.9 },
    { position: 'B2', flux: 2.3 },
    { position: 'B3', flux: 2.5 },
  ];
  
  export const safetyMarginData: SafetyMarginDataPoint[] = [
    { region: 'Core 1', margin: 42, limit: 100 },
    { region: 'Core 2', margin: 38, limit: 100 },
    { region: 'Core 3', margin: 45, limit: 100 },
    { region: 'Core 4', margin: 35, limit: 100 },
  ];
  
  // Generate coolant flow and temperature data
  export const coolantData: CoolantDataPoint[] = Array.from({ length: 20 }, (_, i) => ({
    time: i,
    flow: 100 + Math.random() * 20,
    temp: 280 + Math.random() * 40
  }));
  
  // Chart Configuration
  export const chartConfig: ChartConfig = {
    colors: {
      temperature: '#ff6b6b',
      limit: '#adb5bd',
      flux: '#4dabf7',
      margin: '#51cf66',
      coolant: {
        flow: '#74c0fc',
        flowStroke: '#4dabf7',
        temp: '#ff6b6b'
      }
    },
    dimensions: {
      height: 200,
      minHeight: 300
    }
  };
  
  // Sample Python code snippets
  const preprocessingCode = `def preprocess_reactor_data(input_data):
      # Convert thermal parameters to SI units
      temps_kelvin = input_data['temperatures'] + 273.15
      
      # Validate neutron flux ranges
      if not all(0 <= flux <= MAX_FLUX for flux in input_data['neutron_flux']):
          raise ValueError("Neutron flux values out of acceptable range")
      
      # Format coolant flow data
      formatted_flow = normalize_flow_rates(input_data['coolant_flow'])
      
      return {
          'temperatures': temps_kelvin,
          'neutron_flux': input_data['neutron_flux'],
          'coolant_flow': formatted_flow
      }`;
  
  const analysisCode = `def analyze_safety_margins(simulation_output):
      # Calculate thermal safety margins
      thermal_margins = calculate_thermal_margins(
          simulation_output['core_temperatures'],
          THERMAL_LIMITS
      )
      
      # Analyze neutron flux distribution
      flux_analysis = analyze_flux_distribution(
          simulation_output['neutron_flux_map']
      )
      
      # Verify coolant flow parameters
      flow_verification = verify_coolant_parameters(
          simulation_output['coolant_data']
      )
      
      return {
          'thermal_margins': thermal_margins,
          'flux_distribution': flux_analysis,
          'coolant_status': flow_verification
      }`;
  
  // Mock cell data for the notebook
  export const cells: NotebookCell[] = [
    {
      id: 1,
      type: 'preprocessing',
      title: 'Input Preprocessing',
      code: preprocessingCode,
      output: {
        visualizations: [
          {
            title: "Temperature Distribution",
            description: "Distribution of normalized temperature values",
            type: "temperature"
          },
          {
            title: "Neutron Flux Map",
            description: "2D visualization of neutron flux distribution",
            type: "flux"
          }
        ],
        file: {
          name: "preprocessed_reactor_data.inp",
          size: "2.4 MB",
          format: "INP",
          timestamp: "2025-01-10 14:30:22"
        }
      }
    },
    {
      id: 2,
      type: 'external',
      title: 'External Tool Execution',
      status: 'ready',
      tool: 'REACTOR_SIM_V2.1',
      input: {
        file: "preprocessed_reactor_data.inp",
        status: 'validated',
        checksum: "sha256:8f4e9b..."
      }
    },
    {
      id: 3,
      type: 'postprocessing',
      title: 'Output Analysis',
      code: analysisCode,
      output: {
        visualizations: [
          {
            title: "Thermal Safety Margins",
            description: "Core temperature distribution relative to safety limits",
            type: "safety"
          },
          {
            title: "Coolant Flow Status",
            description: "Coolant flow rates and temperature gradients",
            type: "coolant"
          }
        ],
        file: {
          name: "safety_analysis_report.pdf",
          size: "4.2 MB",
          format: "PDF",
          timestamp: "2025-01-10 14:30:25"
        },
        summary: {
          status: "PASS",
          key_metrics: [
            { label: "Peak Temperature Margin", value: "42.3°C", status: "safe" },
            { label: "Max Neutron Flux", value: "2.4E15 n/cm²·s", status: "safe" },
            { label: "Min Coolant Flow", value: "103.2 kg/s", status: "warning" },
            { label: "Overall Safety Rating", value: "A-", status: "safe" }
          ]
        }
      }
    }
  ];
  
  // Helper function to get chart data by type
  export const getChartData = (type: string) => {
    switch (type) {
      case 'temperature':
        return temperatureData;
      case 'flux':
        return fluxData;
      case 'safety':
        return safetyMarginData;
      case 'coolant':
        return coolantData;
      default:
        return [];
    }
  };