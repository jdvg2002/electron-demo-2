export type CellType = 'preprocessing' | 'external' | 'postprocessing';

export interface FileInfo {
  name: string;
  size: string;
  format: string;
  timestamp: string;
}

export interface SummaryMetric {
  label: string;
  value: string;
  status: 'safe' | 'warning' | 'danger';
}

export interface CellOutput {
  file?: FileInfo;
  summary?: {
    status: string;
    key_metrics: SummaryMetric[];
  };
  // Add any additional fields you need (e.g. visualizations) here
  // visualizations?: Array<{
  //   title: string;
  //   description: string;
  //   type: string;
  // }>;
}

export interface CellInput {
  file: string;
  status: string;
  checksum?: string;
}

export interface CellData {
  id: number;
  type: CellType;
  title: string;
  code?: string;
  status?: string;
  tool?: string;
  input?: CellInput;
  output?: CellOutput;
  // Track additional fields needed
  uploadedFilePath?: string;
  executionResult?: any;
  stlFile?: {
    name: string;
    data: string;  // Base64 encoded STL data
    type: string;
  };
  pipeMeasurements?: {
    inner_diameter: number;
    outer_diameter: number;
    wall_thickness: number;
  };
} 