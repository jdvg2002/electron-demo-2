import { VariableRecord } from './Variable';
import { FileRecord } from './File';

export interface CellInput {
  files?: FileRecord;
  variables?: VariableRecord[];
}

export interface CellOutput {
  //  Either pre or post processed data
  processedData?: FileRecord;
  probabilityOfFailure?: number;
  chartData?: Array<{
    x: number;
    appliedStress: number;
    flowStress: number;
  }>;
  metadata?: {
    analysisTimestamp: string;
    sourceAnalysis: string;
    displayState?: {
      showChart?: boolean;
    };
  };
  stdout?: string;
  data?: any;
}

export interface CellData {
  id: string;
  type: 'preprocessing' | 'external' | 'postprocessing';
  title: string;
  code: string;
  status: 'pending' | 'running' | 'completed' | 'error';
  input: CellInput;
  output: CellOutput;
  dependencyCellId?: string;
  tool?: string;
  localVariables?: Map<string, VariableRecord>;
} 