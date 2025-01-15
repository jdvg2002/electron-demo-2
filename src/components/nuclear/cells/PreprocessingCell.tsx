import React, { useState, useEffect } from 'react';
import { CellData } from '@/backend/models/Cell';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';
import CellExecutionManager from '../managers/CellExecutionManager';
import CellCodeEditor from './shared/CellCodeEditor';
import FileUploadHandler from './shared/FileUploadHandler';
import ErrorDisplay from './shared/ErrorDisplay';
import ExecutionOutput from './shared/ExecutionOutput';
import LoadingIndicator from './shared/LoadingIndicator';
import VisualizationGrid, { createVisualizationCards } from '../CellVisualization';
import { Upload } from 'lucide-react';
import FileOutput from '../FileOutput';

interface PreprocessingCellProps {
  cell: CellData;
  onCellChange: (updatedCell: CellData) => void;
}

/**
 * Handles preprocessing operations including file uploads and initial data transformations
 */
const PreprocessingCell: React.FC<PreprocessingCellProps> = ({
  cell,
  onCellChange
}) => {
  const globalFileManager = GlobalFileManager.getInstance();
  const cellExecutionManager = CellExecutionManager.getInstance();
  
  const [localCode, setLocalCode] = useState(cell.code || 'import numpy as np\n\n# Process reactor data\ndef process_data(input):\n    return np.mean(input)');
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [executionResult, setExecutionResult] = useState<any>(null);
  const [stepFilesData, setStepFilesData] = useState<any[]>([]);

  useEffect(() => {
    if (cell.globalFileIds?.length) {
      const filesData = cell.globalFileIds
        .map(id => {
          const file = globalFileManager.getFileById(id);
          if (!file) {
            console.warn(`File with ID ${id} not found in GlobalFileManager`);
            return undefined;
          }
          
          const measurements = globalFileManager.getMeasurementsForFile(id)
            .reduce((acc, m) => ({ ...acc, [m.name]: m.value }), {});
          
          const distributions = globalFileManager.getDistributionsForFile(id)
            .reduce((acc, d) => ({ 
              ...acc, 
              [d.label]: { label: d.label, mean: d.mean, stdDev: d.stdDev, name: d.name }
            }), {});

          return {
            stlFile: file.stlFile,
            pipeMeasurements: measurements,
            distributions,
            originalFileName: file.originalFileName,
            timestamp: file.timestamp
          };
        })
        .filter(file => file !== undefined);
      
      setStepFilesData(filesData);
    }
  }, [cell.globalFileIds]);

  const prepareInputData = (stepFilesData: any[]) => {
    if (!cell.globalFileIds?.length) return null;
    
    const processedData = {
      files: cell.globalFileIds
        .map(id => {
          const file = globalFileManager.getFileById(id);
          if (!file) return undefined;
          
          const measurements = globalFileManager.getMeasurementsForFile(id)
            .reduce((acc, m) => ({ ...acc, [m.name]: m.value }), {});
          
          const distributions = globalFileManager.getDistributionsForFile(id)
            .reduce((acc, d) => ({ 
              ...acc, 
              [d.label]: { label: d.label, mean: d.mean, stdDev: d.stdDev, name: d.name }
            }), {});

          return {
            stlFile: file.stlFile,
            measurements,
            distributions,
            metadata: {
              file_name: file.originalFileName,
              timestamp: file.timestamp
            }
          };
        })
        .filter(file => file !== undefined)
    };

    // Get the first file to extract available variable names
    const firstFile = globalFileManager.getFileById(cell.globalFileIds[0]);
    const availableVariables = {
      stlFile: firstFile?.stlFile ? ['vertices', 'faces'] : [],
      measurements: Object.keys(firstFile?.pipeMeasurements || {}),
      distributions: Object.keys(firstFile?.distributions || {}),
      metadata: ['file_name', 'timestamp']
    };

    return {
      ...processedData,
      availableVariables,
      totalFiles: cell.globalFileIds.length
    };
  };

  const handlePreprocessingClick = async () => {
    try {
      setIsExecuting(true);
      setErrorMessage(null);

      const preprocessedData = prepareInputData(stepFilesData);
      if (!preprocessedData) {
        throw new Error('No input data available for preprocessing');
      }
      
      // Structure the output in a standardized format
      const outputData = {
        type: 'preprocessed_data',
        version: '1.0',
        timestamp: new Date().toISOString(),
        data: preprocessedData,
        metadata: {
          sourceFiles: cell.globalFileIds,
          processingSteps: ['data_preparation', 'preprocessing']
        }
      };

      // Update cell with structured output
      const updatedCell = {
        ...cell,
        status: 'completed',
        output: {
          preprocessedData: outputData
        }
      };

      // Important: Call onCellChange to update the parent's state
      onCellChange(updatedCell);

      // Update execution result for display
      setExecutionResult({
        success: true,
        message: "Data prepared successfully",
        preprocessedData: outputData
      });

    } catch (error) {
      console.error('Preprocessing failed:', error);
      setErrorMessage(error instanceof Error ? error.message : 'Preprocessing failed');
      
      const updatedCell = {
        ...cell,
        status: 'error'
      };
      onCellChange(updatedCell);
    } finally {
      setIsExecuting(false);
    }
  };


  const renderOutputs = (executionResult: any) => {
    if (!executionResult?.preprocessedData) return null;

    const fileData = {
      name: 'preprocessed_data.json',
      size: `${JSON.stringify(executionResult.preprocessedData).length} bytes`,
      format: 'JSON',
      timestamp: new Date().toLocaleString(),
      data: executionResult.preprocessedData
    };

    return (
      <div className="space-y-4">
        <FileOutput file={fileData} />
      </div>
    );
  };

  return (
    <div className="space-y-4">
      {stepFilesData.map((fileData, index) => (
        <VisualizationGrid 
          key={index}
          cards={createVisualizationCards(
            cell.globalFileIds[index],
            fileData.stlFile
          )}
          cardsPerRow={6}
          fileId={cell.globalFileIds[index]}
        />
      ))}

      <CellCodeEditor
        code={localCode}
        onChange={setLocalCode}
      />

      <button
        onClick={handlePreprocessingClick}
        disabled={isExecuting}
        className={`px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600 ${
          isExecuting ? 'opacity-50 cursor-not-allowed' : ''
        }`}
      >
        Run Preprocessing
      </button>

      {isExecuting && <LoadingIndicator />}
      
      {executionResult && renderOutputs(executionResult)}
    </div>
  );
};

export default PreprocessingCell;