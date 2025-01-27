import React from 'react';
import { Box } from 'lucide-react';
import { BaseCell } from './BaseCell';
import type { NotebookCellProps } from './NotebookCell';
import { GlobalManager } from '@/backend/manager/GlobalManager';
import type { ParsedFileResult } from '@/backend/manager/FileUploadManager';
import { VisualizationManager } from '../visualization/VisualizationManager';
import { useVariableManager } from '@/hooks/useVariableManager';

export const PreprocessingCell: React.FC<NotebookCellProps> = (props) => {
  const { cell } = props;
  const { module } = useVariableManager(cell.id);
  const globalManager = GlobalManager.getInstance();
  
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

  return (
    <BaseCell {...props} icon={<Box className="text-blue-500" />} borderColor="border-l-blue-500">
      <VisualizationManager files={files} />
    </BaseCell>
  );
}; 