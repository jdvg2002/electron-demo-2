import { VariableRecord } from './Variable';

export interface CellOutput {
  //  Either pre or post processed data
  processedData?: {
    type: string;
    version: string;
    timestamp: string;
    data?: any;
    chartData?: Array<{
      x: number;
      appliedStress: number;
      flowStress: number;
    }>;
    probabilityOfFailure?: number;
    metadata: {
      analysisTimestamp: string;
      sourceAnalysis: string;
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
  input?: {
    sourceModuleId?: number;
    inputData?: {
      type: string;
      version: string;
      timestamp: string;
      data: any;
      metadata: {
        sourceModule: string;
        sourceCell: string;
      };
    };
  };
  globalFileIds?: string[];
  dependencyCellId?: string;
  localVariables: Map<string, VariableRecord>;
} 