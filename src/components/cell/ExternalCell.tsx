import React, { useState } from 'react';
import { Play } from 'lucide-react';
import { BaseCell } from './BaseCell';
import type { NotebookCellProps } from './NotebookCell';
import CellExecutionManager from './CellExecutionManager';
import ErrorDisplay from './ErrorDisplay';
import LoadingIndicator from './LoadingIndicator';

// Define the analysis options
const ANALYSIS_OPTIONS = {
  pipeFailure: 'Pipe Failure Probability',
  fatigueCrackInit: 'Fatigue Crack Initiation',
  ansys: 'Ansys Fracture Analysis',
  relap: 'RELAP'
} as const;

type AnalysisType = keyof typeof ANALYSIS_OPTIONS;

export const ExternalCell: React.FC<NotebookCellProps> = (props) => {
  const { cell, onCellChange, previousCell } = props;
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [selectedAnalysis, setSelectedAnalysis] = useState<AnalysisType>('pipeFailure');

  const handleExecution = async () => {
    try {
      setIsExecuting(true);
      setErrorMessage(null);

      const projectRoot = await window.electronWindow.getProjectRoot();
      
      if (!cell.tool) {
        throw new Error('No tool specified');
      }

      // Get the preprocessed data from the previous cell
      if (!previousCell?.output?.processedData?.data) {
        throw new Error('No preprocessed data available');
      }

      // Format the data structure expected by handler.py
      const formattedData = {
        data: {
          files: [{
            distributions: previousCell.output.processedData.data.files[0].distributions
          }]
        }
      };

      // Execute the external tool
      const result = await CellExecutionManager.getInstance().runExternalTool(
        cell.tool,
        projectRoot,
        selectedAnalysis,
        formattedData
      );
      
      // Update cell with results in a consistent format
      onCellChange({
        ...cell,
        status: 'completed',
        output: {
          processedData: {
            id: crypto.randomUUID(),
            type: 'analysis_results',
            version: '1.0',
            timestamp: new Date().toISOString(),
            originalFileName: 'analysis_results.json',
            sourceEnvironment: 'external',
            data: result
          },
          metadata: {
            analysisTimestamp: new Date().toISOString(),
            sourceAnalysis: selectedAnalysis
          }
        }
      });

    } catch (error) {
      setErrorMessage(error instanceof Error ? error.message : 'External tool execution failed');
      onCellChange({
        ...cell,
        status: 'error',
        output: {
          metadata: {
            analysisTimestamp: new Date().toISOString(),
            sourceAnalysis: 'external_error'
          }
        }
      });
    } finally {
      setIsExecuting(false);
    }
  };

  return (
    <BaseCell {...props} icon={<Play className="text-green-500" />} borderColor="border-l-green-500">
      <div className="space-y-4">
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
            className={`px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600 
                       transition-colors ${isExecuting ? 'opacity-50 cursor-not-allowed' : ''}`}
          >
            {isExecuting ? 'Running...' : 'Run Analysis'}
          </button>
        </div>

        {isExecuting && <LoadingIndicator message="Running external analysis..." />}
        {errorMessage && <ErrorDisplay message={errorMessage} />}
      </div>
    </BaseCell>
  );
}; 