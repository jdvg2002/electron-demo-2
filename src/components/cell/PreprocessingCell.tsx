import React, { useState } from 'react';
import { Box } from 'lucide-react';
import { BaseCell } from './BaseCell';
import type { NotebookCellProps } from './NotebookCell';
import { GlobalManager } from '@/backend/manager/GlobalManager';
import type { ParsedFileResult } from '@/backend/manager/FileUploadManager';
import { VisualizationManager } from '../visualization/VisualizationManager';
import { useVariableManager } from '@/hooks/useVariableManager';
import { CellManager } from '@/backend/manager/CellManager';
import { VariableRecord } from '@/backend/models/Variable';
import { CodeEditor } from './code/CodeEditor';

export const PreprocessingCell: React.FC<NotebookCellProps> = (props) => {
  const { cell, nextCell, onCellChange } = props;
  const { module, localVariables } = useVariableManager(cell.id);
  const [isExecuting, setIsExecuting] = useState(false);
  const globalManager = GlobalManager.getInstance();
  const cellManager = CellManager.getInstance();
  
  const files: ParsedFileResult[] = module?.globalFileIds?.map((fileId: string) => {
    const file = globalManager.getFileById(fileId);
    if (!file) return null;

    return {
      fileId: file.id,
      fileType: file.originalFileName.toLowerCase().endsWith('.stl') ? 'stl' : 'step',
      measurements: {},
      rawFile: new File(
        [Uint8Array.from(atob(file.data.split(',')[1]), c => c.charCodeAt(0))],
        file.originalFileName,
        { type: 'model/stl' }
      ),
      originalFileName: file.originalFileName,
      timestamp: file.timestamp
    };
  }).filter((f): f is ParsedFileResult => f !== null) || [];

  // Create a dummy file if we have local variables but no files
  if (localVariables?.size > 0 && files.length === 0) {
    files.push({
      fileId: `local-${cell.id}`,
      fileType: 'local',
      measurements: {},
      rawFile: new File([], 'local.ghost'),
      originalFileName: 'Local Variables',
      timestamp: new Date().toISOString()
    });
  }

  const handleLocalVariableChange = (variable: Omit<VariableRecord, 'id'>) => {
    if (!module) return;

    // Get current cell
    const currentCell = cellManager.getCellsForModule(module.card.id)
      .find(c => c.id === cell.id);
    
    if (!currentCell) return;

    // Create new Map from existing variables
    const newLocalVariables = new Map(currentCell.localVariables || new Map());

    if (variable._delete) {
      // Remove the variable if delete flag is set
      newLocalVariables.delete(variable.label);
    } else {
      // Add/update the variable
      const id = crypto.randomUUID();
      newLocalVariables.set(variable.label, { ...variable, id });
    }

    // Update cell with new variables
    cellManager.updateCell(module.card.id, cell.id, {
      ...currentCell,
      localVariables: newLocalVariables
    });
  };

  const handleRunPreprocessing = async () => {
    if (!module) return;
    setIsExecuting(true);

    try {
      // Format the variables into distributions
      const distributions = Array.from(localVariables?.entries() || [])
        .reduce((acc, [key, value]) => ({
          ...acc,
          [key]: {
            name: value.name || key,
            label: key,
            mean: value.mean,
            stdDev: value.stdDev
          }
        }), {});

      // Create the output data structure that matches handler.py's expectations
      const outputData = {
        processedData: {
          id: crypto.randomUUID(),
          type: 'preprocessed_data',
          version: '1.0',
          timestamp: new Date().toISOString(),
          originalFileName: 'preprocessed_data.json',
          sourceEnvironment: 'preprocessing',
          data: {
            files: [{
              distributions: distributions
            }]
          }
        },
        metadata: {
          analysisTimestamp: new Date().toISOString(),
          sourceAnalysis: 'preprocessing'
        }
      };

      // Update both cells
      onCellChange({
        ...cell,
        output: outputData,
        status: 'completed'
      });

      if (nextCell?.type === 'external') {
        cellManager.updateCell(module.card.id, nextCell.id, {
          ...nextCell,
          input: {
            files: outputData.processedData,
            variables: []
          }
        });
      }

    } catch (error) {
      onCellChange({
        ...cell,
        status: 'error',
        output: {
          metadata: {
            analysisTimestamp: new Date().toISOString(),
            sourceAnalysis: 'preprocessing_error'
          }
        }
      });
    } finally {
      setIsExecuting(false);
    }
  };

  return (
    <BaseCell {...props} icon={<Box className="text-blue-500" />} borderColor="border-l-blue-500">
      <div className="space-y-4">
        <VisualizationManager 
          files={files} 
          localVariables={localVariables}
          onAddLocalVariable={handleLocalVariableChange}
        />

        <CodeEditor
          code={cell.code || ''}
          onChange={(newCode) => {
            onCellChange({
              ...cell,
              code: newCode
            });
          }}
        />

        <button
          onClick={handleRunPreprocessing}
          disabled={isExecuting}
          className={`px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600 
                     transition-colors ${isExecuting ? 'opacity-50 cursor-not-allowed' : ''}`}
        >
          {isExecuting ? 'Running...' : 'Run Preprocessing'}
        </button>
      </div>
    </BaseCell>
  );
}; 