import React from 'react';
import { ParsedFileResult } from '@/backend/models/FileUploadManager';
import VisualizationGrid, { createVisualizationCards } from '../visualization/CellVisualization';
import { useFileUpload } from '@/hooks/useFileUpload';

interface VisualizationManagerProps {
  files: ParsedFileResult[];
}

export const VisualizationManager: React.FC<VisualizationManagerProps> = ({ files }) => {
  const { addMeasurement, addDistribution } = useFileUpload();
  
  // Only show visualizations for the first file for now
  // (We could add tabs or other UI to handle multiple files)
  const activeFile = files[0];
  
  if (!activeFile) return null;

  return (
    <VisualizationGrid
      cards={createVisualizationCards(activeFile.fileId, activeFile.rawFile)}
      cardsPerRow={6}
      fileId={activeFile.fileId}
      onAddVariable={(variable) => {
        if (variable.type === 'distribution') {
          addDistribution(activeFile.fileId, variable);
        } else {
          addMeasurement(activeFile.fileId, variable);
        }
      }}
    />
  );
}; 