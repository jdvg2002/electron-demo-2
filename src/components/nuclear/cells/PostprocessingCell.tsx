import React, { useState } from 'react';
import { CellData } from '@/backend/models/Cell';
import CellExecutionManager from '../managers/CellExecutionManager';
import CellCodeEditor from './shared/CellCodeEditor';
import ErrorDisplay from './shared/ErrorDisplay';
import ExecutionOutput from './shared/ExecutionOutput';
import LoadingIndicator from './shared/LoadingIndicator';
import AnalysisSummary from '../AnalysisSummary';

interface PostprocessingCellProps {
  cell: CellData;
  onCellChange: (updatedCell: CellData) => void;
}

/**
 * Handles post-processing operations and analysis of results
 */
const PostprocessingCell: React.FC<PostprocessingCellProps> = ({
  cell,
  onCellChange
}) => {
  const cellExecutionManager = CellExecutionManager.getInstance();
  
  const [localCode, setLocalCode] = useState(cell.code || 'import numpy as np\n\n# Process reactor data\ndef process_data(input):\n    return np.mean(input)');
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [executionResult, setExecutionResult] = useState<any>(null);

  const handleCodeExecution = async () => {
    try {
      setIsExecuting(true);
      setErrorMessage(null);
      
      const result = await cellExecutionManager.runPostprocessingCode(localCode);
      setExecutionResult(result);
      
      const updatedCell = {
        ...cell,
        code: localCode,
        output: {
          ...cell.output,
          result
        }
      };
      onCellChange(updatedCell);
    } catch (error) {
      setErrorMessage(error instanceof Error ? error.message : 'Execution failed');
    } finally {
      setIsExecuting(false);
    }
  };

  return (
    <div className="space-y-4">
      {errorMessage && <ErrorDisplay message={errorMessage} />}

      <CellCodeEditor
        code={localCode}
        onChange={setLocalCode}
      />

      <button
        onClick={handleCodeExecution}
        disabled={isExecuting}
        className={`px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600 ${
          isExecuting ? 'opacity-50 cursor-not-allowed' : ''
        }`}
      >
        Run Analysis
      </button>

      {isExecuting && <LoadingIndicator />}
      
      {executionResult && <ExecutionOutput {...executionResult} />}

      {cell.output?.summary && (
        <AnalysisSummary
          status={cell.output.summary.status}
          metrics={cell.output.summary.key_metrics}
        />
      )}
    </div>
  );
};

export default PostprocessingCell;