import React from 'react';
import { ParsedFileResult } from '@/backend/manager/FileUploadManager';
import VisualizationGrid from './VisualizationGrid';
import { useFileUpload } from '@/hooks/useFileUpload';
import { CardFactory } from './CardFactory';
import { GlobalManager } from '@/backend/manager/GlobalManager';
import { VariableRecord } from '@/backend/models/Variable';
interface VisualizationManagerProps {
  files?: ParsedFileResult[];
  localVariables?: Map<string, VariableRecord>;
  onAddLocalVariable?: (variable: Omit<VariableRecord, 'id'>) => void;
}

export function VisualizationManager({
  files = [],
  localVariables,
  onAddLocalVariable
}: VisualizationManagerProps) {
  const { addMeasurement, addDistribution } = useFileUpload();

  if (!files.length) return null;

  return (
    <div className="space-y-4">
      {files.map((file) => (
        <VisualizationGrid
          key={file.fileId}
          cards={CardFactory.createCards(
            file.fileId, 
            file.rawFile,
            localVariables,
            !!localVariables  // Pass boolean for isPreprocessing
          )}
          cardsPerRow={6}
          fileId={file.fileId}
          onAddVariable={(variable) => {
            if (localVariables !== undefined) {
              // If we have localVariables, this is a preprocessing cell
              onAddLocalVariable?.(variable);
            } else {
              // Otherwise, add to global store
              if (variable.type === 'distribution') {
                addDistribution(file.fileId, variable);
              } else {
                addMeasurement(file.fileId, variable);
              }
            }
          }}
          onDeleteVariable={(label) => {
            if (localVariables !== undefined) {
              // If we have localVariables, this is a preprocessing cell
              onAddLocalVariable?.({
                type: 'distribution',
                label,
                fileId: file.fileId,
                name: label,
                mean: 0,
                stdDev: 0,
                _delete: true
              });
            } else {
              // Otherwise, delete from global store
              const globalManager = GlobalManager.getInstance();
              const variables = globalManager.getDistributionsForFile(file.fileId);
              const variableToDelete = variables.find((v) => v.label === label);
              if (variableToDelete) {
                globalManager.removeVariable(variableToDelete.id);
              }
            }
          }}
        />
      ))}
    </div>
  );
} 