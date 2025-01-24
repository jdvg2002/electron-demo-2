import React from 'react';
import { ParsedFileResult } from '@/backend/manager/FileUploadManager';
import VisualizationGrid from './VisualizationGrid';
import { useFileUpload } from '@/hooks/useFileUpload';
import { CardFactory } from './CardFactory';
import { GlobalManager } from '@/backend/manager/GlobalManager';

interface VisualizationManagerProps {
  files: ParsedFileResult[];
}

export const VisualizationManager: React.FC<VisualizationManagerProps> = ({ files }) => {
  const { addMeasurement, addDistribution } = useFileUpload();

  if (!files.length) return null;

  return (
    <div className="space-y-4">
      {files.map((file) => (
        <VisualizationGrid
          key={file.fileId}
          cards={CardFactory.createCards(file.fileId, file.rawFile)}
          cardsPerRow={6}
          fileId={file.fileId}
          onAddVariable={(variable) => {
            if (variable.type === 'distribution') {
              addDistribution(file.fileId, variable);
            } else {
              addMeasurement(file.fileId, variable);
            }
          }}
          onDeleteVariable={(label) => {
            const globalManager = GlobalManager.getInstance();
            const variables = globalManager.getDistributionsForFile(file.fileId);
            const variableToDelete = variables.find((v) => v.label === label);
            if (variableToDelete) {
              globalManager.removeVariable(variableToDelete.id);
            }
          }}
        />
      ))}
    </div>
  );
}; 