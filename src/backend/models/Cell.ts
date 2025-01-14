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
  preprocessedData?: {
    type: string;
    version: string;
    timestamp: string;
    data: any;
    metadata: {
      sourceFiles: string[];
      processingSteps: string[];
    };
  };
  stdout?: string;
  data?: any;
}

export interface CellData {
  id: string;
  type: 'preprocessing' | 'external' | 'postprocessing';
  title: string;
  code?: string;
  tool?: string;
  status?: 'pending' | 'running' | 'completed' | 'error';
  output?: CellOutput;
  globalFileIds?: string[];
  dependencyCellId?: string;
} 