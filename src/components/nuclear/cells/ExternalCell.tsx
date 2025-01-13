import React, { useState } from 'react';
import { CellData } from '@/backend/models/Cell';
import CellExecutionManager from '../managers/CellExecutionManager';
import ErrorDisplay from './shared/ErrorDisplay';
import ExecutionOutput from './shared/ExecutionOutput';
import LoadingIndicator from './shared/LoadingIndicator';
import ExternalTool from '../ExternalTool';

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
  const [executionResult, setExecutionResult] = useState<any>(null);

  const handleExecution = async () => {
    try {
      setIsExecuting(true);
      setErrorMessage(null);

      const projectRoot = await window.electronWindow.getProjectRoot();
      const result = await cellExecutionManager.runExternalTool(cell.tool || '', projectRoot);
      
      setExecutionResult(result);
      
      const updatedCell = {
        ...cell,
        status: 'completed',
        output: {
          ...cell.output,
          result
        }
      };
      onCellChange(updatedCell);
    } catch (error) {
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

      <ExternalTool
        tool={cell.tool || ''}
        status={cell.status || 'pending'}
        input={cell.input || {}}
        executionResult={executionResult}
      />

      <button
        onClick={handleExecution}
        disabled={isExecuting}
        className={`px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600 ${
          isExecuting ? 'opacity-50 cursor-not-allowed' : ''
        }`}
      >
        Run External Tool
      </button>

      {isExecuting && <LoadingIndicator message="Running external tool..." />}
      
      {executionResult && <ExecutionOutput {...executionResult} />}
    </div>
  );
};

export default ExternalCell;