import React, { useState, useEffect, useCallback, useMemo } from 'react';
import { CellData } from '@/backend/Cell';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';
import { VariableRecord } from '@/backend/Variable';
import CellExecutionManager from '../managers/CellExecutionManager';
import CellCodeEditor from './shared/CellCodeEditor';
import ErrorDisplay from './shared/ErrorDisplay';
import ExecutionOutput from './shared/ExecutionOutput';
import LoadingIndicator from './shared/LoadingIndicator';
import VisualizationGrid, { createVisualizationCards } from '../visualization/CellVisualization';
import { Upload } from 'lucide-react';
import FileOutput from '../FileOutput';

interface PreprocessingCellProps {
  cell: CellData;
  onCellChange: (updatedCell: CellData) => void;
}

/**
 * Handles preprocessing operations including file uploads and initial data transformations
 */
const PreprocessingCell: React.FC<PreprocessingCellProps> = React.memo(({
  cell,
  onCellChange
}) => {
  const globalFileManager = GlobalFileManager.getInstance();
  const cellExecutionManager = CellExecutionManager.getInstance();
  
  const [localCode, setLocalCode] = useState(cell.code || '#Add variables and calculations here\n');
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [executionResult, setExecutionResult] = useState<any>(null);
  const [stepFilesData, setStepFilesData] = useState<any[]>([]);
  const [localRenderTrigger, setLocalRenderTrigger] = useState(0);
  const [updateTrigger, setUpdateTrigger] = useState(0);
  const [localVariables, setLocalVariables] = useState<Map<string, VariableRecord>>(cell.localVariables);

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

  useEffect(() => {
    const globalFileManager = GlobalFileManager.getInstance();
    return globalFileManager.addListener(() => {
      setUpdateTrigger(prev => prev + 1);
    });
  }, []);

  useEffect(() => {
    setLocalVariables(cell.localVariables);
  }, [cell.localVariables]);

  const prepareInputData = (stepFilesData: any[]) => {
    if (!cell.globalFileIds?.length) return null;
    
    const processedData = {
      files: cell.globalFileIds
        .map(id => {
          const file = globalFileManager.getFileById(id);
          if (!file) return undefined;
          
          // Get local variables for this file instead of global measurements/distributions
          const localVars = Array.from(cell.localVariables.values())
            .filter(v => v.fileId === id)
            .reduce((acc, v) => ({
              ...acc,
              [v.label]: { 
                label: v.label, 
                mean: v.mean, 
                stdDev: v.stdDev,
                name: v.name 
              }
            }), {});

          return {
            stlFile: file.stlFile,
            distributions: localVars,
            metadata: {
              file_name: file.originalFileName,
              timestamp: file.timestamp
            }
          };
        })
        .filter(file => file !== undefined)
    };

    // Get available variables from local variables
    const firstFileId = cell.globalFileIds[0];
    const availableVariables = {
      stlFile: ['vertices', 'faces'],
      distributions: Array.from(cell.localVariables.values())
        .filter(v => v.fileId === firstFileId)
        .map(v => v.label),
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

      const processedData = prepareInputData(stepFilesData);
      if (!processedData) {
        throw new Error('No input data available for preprocessing');
      }
      
      // Structure the output in a standardized format
      const outputData = {
        type: 'preprocessed_data',
        version: '1.0',
        timestamp: new Date().toISOString(),
        data: processedData,
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
          processedData: outputData
        }
      };

      // Important: Call onCellChange to update the parent's state
      onCellChange(updatedCell);

      // Update execution result for display
      setExecutionResult({
        success: true,
        message: "Data prepared successfully",
        processedData: outputData
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

  const handleAddLocalVariable = useCallback((fileId: string, variable: Omit<VariableRecord, 'id'>) => {
    const id = crypto.randomUUID();
    const variableRecord: VariableRecord = { 
        ...variable,
        id,
        fileId 
    };
    
    setLocalVariables(prev => {
      const newLocalVariables = new Map(prev);
      newLocalVariables.set(id, variableRecord);
      
      const updatedCell = {
        ...cell,
        localVariables: newLocalVariables
      };
      
      onCellChange(updatedCell);
      return newLocalVariables;
    });
  }, [cell, onCellChange]);

  const handleDeleteVariable = useCallback((fileId: string, label: string) => {
    setLocalVariables(prev => {
      const newLocalVariables = new Map(prev);
      
      for (const [id, variable] of newLocalVariables.entries()) {
        if (variable.type === 'distribution' && variable.label === label && variable.fileId === fileId) {
          newLocalVariables.delete(id);
          break;
        }
      }
      
      const updatedCell = {
        ...cell,
        localVariables: newLocalVariables
      };
      
      onCellChange(updatedCell);
      return newLocalVariables;
    });
  }, [cell, onCellChange]);

  const handleCodeChange = (newCode: string) => {
    setLocalCode(newCode);
    // Optionally, if you want to persist changes immediately:
    onCellChange({
      ...cell,
      code: newCode
    });
  };

  const renderOutputs = (executionResult: any) => {
    if (!executionResult?.processedData) return null;

    const fileData = {
      name: 'preprocessed_data.json',
      size: `${JSON.stringify(executionResult.processedData).length} bytes`,
      format: 'JSON',
      timestamp: new Date().toLocaleString(),
      data: executionResult.processedData
    };

    return (
      <div className="space-y-4">
        <FileOutput file={fileData} type="output" />
      </div>
    );
  };

  const renderWiredInput = () => {
    if (!cell.input?.inputData) return null;

    const fileData = {
      name: 'wired_input.json',
      size: `${JSON.stringify(cell.input.inputData.data).length} bytes`,
      format: 'JSON',
      timestamp: cell.input.inputData.timestamp,
      data: cell.input.inputData.data
    };

    return (
      <div className="mb-4">
        <div className="text-sm font-medium mb-2">
          Input from {cell.input.inputData.metadata.sourceModule}
        </div>
        <FileOutput file={fileData} type="input" />
      </div>
    );
  };

  // Memoize the visualization grids
  const visualizationGrids = useMemo(() => {
    return stepFilesData.map((fileData, index) => {
      const fileId = cell.globalFileIds[index];
      return (
        <VisualizationGrid 
          key={fileId} // Use stable fileId instead of index + size
          cards={createVisualizationCards(
            fileId,
            fileData.stlFile,
            localVariables
          )}
          cardsPerRow={6}
          fileId={fileId}
          onAddVariable={(variable) => handleAddLocalVariable(fileId, variable)}
          onDeleteVariable={(label) => handleDeleteVariable(fileId, label)}
        />
      );
    });
  }, [stepFilesData, cell.globalFileIds, localVariables, handleAddLocalVariable, handleDeleteVariable]);

  return (
    <div className="space-y-4">
      {renderWiredInput()}
      {visualizationGrids}
      <CellCodeEditor
        code={localCode}
        onChange={handleCodeChange}
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
});

PreprocessingCell.displayName = 'PreprocessingCell';

export default PreprocessingCell;