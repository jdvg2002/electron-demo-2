import React, { useState } from 'react';
import { CellData } from '@/backend/Cell';
import CellExecutionManager from '../managers/CellExecutionManager';
import ErrorDisplay from './shared/ErrorDisplay';
import LoadingIndicator from './shared/LoadingIndicator';
import FileOutput from './shared/FileOutput';

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
  availableCells: CellData[];
}

/**
 * Handles execution of external tools and displays their results
 */
const ExternalCell: React.FC<ExternalCellProps> = ({
  cell,
  onCellChange,
  availableCells = []
}) => {
  const cellExecutionManager = CellExecutionManager.getInstance();
  
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [executionResult, setExecutionResult] = useState<any>(null);
  const [selectedAnalysis, setSelectedAnalysis] = useState<AnalysisType>('pipeFailure');
  const [hasClickedRun, setHasClickedRun] = useState(false);

  const handleExecution = async () => {
    setHasClickedRun(true);
    try {
      setIsExecuting(true);
      setErrorMessage(null);

      const projectRoot = await window.electronWindow.getProjectRoot();
      
      if (!cell.tool) {
        throw new Error('No tool specified');
      }

      // Get the preprocessed data
      const processedData = getprocessedData();

      // Pass preprocessed data to runExternalTool
      const result = await cellExecutionManager.runExternalTool(
        cell.tool, 
        projectRoot, 
        selectedAnalysis,
        processedData
      );
      
      setExecutionResult(result);
      
      const updatedCell = {
        ...cell,
        status: 'completed',
        output: result
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

  // Get preprocessed data from the preprocessing cell (if it exists)
  const getprocessedData = () => {
    const preprocessingCell = availableCells.find(c => 
      c.type === 'preprocessing' && 
      c.status === 'completed' && 
      c.output?.processedData
    );
    
    // Ensure we're using the local variables data
    if (preprocessingCell?.output?.processedData) {
      const data = preprocessingCell.output.processedData;
      // The data structure is already correct from the preprocessing cell
      // since we modified it there to use local variables
      return data;
    }
    
    return null;
  };

  // Render the preprocessed data if available
  const renderprocessedData = () => {
    const processedData = getprocessedData();
    if (!processedData) return null;

    const fileData = {
      name: 'preprocessed_data.json',
      size: `${JSON.stringify(processedData).length} bytes`,
      format: 'JSON',
      timestamp: new Date().toLocaleString(),
      data: processedData
    };

    return (
      <div className="mb-4">
        <FileOutput file={fileData} type="input" />
      </div>
    );
  };

  const renderOutputs = () => {
    if (!executionResult) return null;

    const fileData = {
      name: 'analysis_results.json',
      size: `${JSON.stringify(executionResult).length} bytes`,
      format: 'JSON',
      timestamp: new Date().toLocaleString(),
      data: {
        type: 'analysis_results',
        version: '1.0',
        timestamp: new Date().toISOString(),
        analysisType: selectedAnalysis,
        results: executionResult
      }
    };

    return (
      <div className="space-y-4">
        <FileOutput file={fileData} type="output" />
      </div>
    );
  };

  return (
    <div className="space-y-4">
      {!getprocessedData() && (
        <div className="text-gray-500 italic">
          No preprocessed data available. Please run the preprocessing cell first.
        </div>
      )}
      
      {renderprocessedData()}
      
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
      
      {hasClickedRun && renderOutputs()}
    </div>
  );
};

export default ExternalCell;