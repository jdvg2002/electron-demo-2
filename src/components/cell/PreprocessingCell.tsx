import React from 'react';
import { Box } from 'lucide-react';
import { BaseCell } from './BaseCell';
import type { NotebookCellProps } from './NotebookCell';
import { GlobalManager } from '@/backend/manager/GlobalManager';
import type { ParsedFileResult } from '@/backend/manager/FileUploadManager';
import { VisualizationManager } from '../visualization/VisualizationManager';
import { useVariableManager } from '@/hooks/useVariableManager';
import { CellManager } from '@/backend/manager/CellManager';
import { VariableRecord } from '@/backend/models/Variable';

export const PreprocessingCell: React.FC<NotebookCellProps> = (props) => {
  const { cell } = props;
  const { module, localVariables } = useVariableManager(cell.id);
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

  return (
    <BaseCell {...props} icon={<Box className="text-blue-500" />} borderColor="border-l-blue-500">
      <VisualizationManager 
        files={files} 
        localVariables={localVariables}
        onAddLocalVariable={handleLocalVariableChange}
      />
    </BaseCell>
  );
}; 