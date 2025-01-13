import React, { useState } from 'react';
import { CellData } from '@/backend/models/Cell';
import CellExecutionManager from '../managers/CellExecutionManager';
import ErrorDisplay from './shared/ErrorDisplay';
import ExecutionOutput from './shared/ExecutionOutput';
import LoadingIndicator from './shared/LoadingIndicator';
import ExternalTool from '../ExternalTool';

// Define the analysis options once
const ANALYSIS_OPTIONS = {
  pipeFailure: 'Pipe Failure Probability',
  fatigueCrackInit: 'Fatigue Crack Initiation',
  ansys: 'Ansys Fracture Analysis',
  relap: 'RELAP'
} as const;

// Create the type from the keys of the options object
type AnalysisType = keyof typeof ANALYSIS_OPTIONS;

interface ExternalCellProps {
  cell: CellData;
  onCellChange: (updatedCell: CellData) => void;
}

/**
 * Handles execution of external tools and displays their results
 */
const ExternalCell: React.FC<ExternalCellProps> = ({
  cell,
  onCellChange
}) => {
  const cellExecutionManager = CellExecutionManager.getInstance();
  
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [executionResult, setExecutionResult] = useState<{
    stdout?: string;
    data?: any;
  } | null>(null);
  const [selectedAnalysis, setSelectedAnalysis] = useState<AnalysisType>('pipeFailure');

  const handleExecution = async () => {
    try {
      console.log('Starting external tool execution...', {
        tool: cell.tool,
        analysisType: selectedAnalysis
      });
      
      setIsExecuting(true);
      setErrorMessage(null);

      const projectRoot = await window.electronWindow.getProjectRoot();
      
      if (!cell.tool) {
        throw new Error('No tool specified');
      }

      const result = await cellExecutionManager.runExternalTool(cell.tool, projectRoot, selectedAnalysis);
      
      const executionOutput = {
        stdout: result.stdout,
        data: result.data || result.result // Handle both possible result formats
      };

      setExecutionResult(executionOutput);
      
      const updatedCell = {
        ...cell,
        status: 'completed',
        output: executionOutput
      };

      onCellChange(updatedCell);
    } catch (error) {
      console.error('External tool execution failed:', error);
      setErrorMessage(error instanceof Error ? error.message : 'External tool execution failed');
      const updatedCell = {
        ...cell,
        status: 'error'
      };
      onCellChange(updatedCell);
    } finally {
      setIsExecuting(false);
    }
  };

  return (
    <div className="space-y-4">
      {errorMessage && <ErrorDisplay message={errorMessage} />}

      <div className="flex items-center space-x-4">
        <select
          value={selectedAnalysis}
          onChange={(e) => setSelectedAnalysis(e.target.value as AnalysisType)}
          className="px-4 py-2 border rounded-md focus:outline-none focus:ring-2 focus:ring-green-500"
        >
          {Object.entries(ANALYSIS_OPTIONS).map(([value, label]) => (
            <option key={value} value={value}>{label}</option>
          ))}
        </select>

        <button
          onClick={handleExecution}
          disabled={isExecuting}
          className={`px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600 ${
            isExecuting ? 'opacity-50 cursor-not-allowed' : ''
          }`}
        >
          Run External Tool
        </button>
      </div>

      {isExecuting && <LoadingIndicator message="Running external tool..." />}
      
      {executionResult && (
        <ExecutionOutput stdout={executionResult.stdout} />
      )}
    </div>
  );
};

export default ExternalCell;