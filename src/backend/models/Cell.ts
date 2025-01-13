export interface Visualization {
  title: string;
  description: string;
  type: string;
}

export interface FileInfo {
  name: string;
  size: string;
  format: string;
  timestamp: string;
  data?: any;
}

export interface KeyMetric {
  label: string;
  value: string;
  status: 'safe' | 'warning' | 'danger';
}

export interface CellOutput {
  visualizations?: Visualization[];
  file?: FileInfo;
  summary?: {
    status: string;
    key_metrics: KeyMetric[];
  };
  result?: any;
}

export interface CellData {
  id: number;
  type: 'preprocessing' | 'external' | 'postprocessing';
  title: string;
  code?: string;
  tool?: string;
  status?: string;
  input?: any;
  output?: CellOutput;
  globalFileIds?: string[];
  stlFile?: any;
  pipeMeasurements?: any;
  timestamp?: string;
} 