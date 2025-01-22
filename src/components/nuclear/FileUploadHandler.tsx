import React from 'react';
import { CellData } from '@/backend/Cell';
import { RenderedFileInfo } from './FileRenderInfo';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';

interface StepFileData {
  stlFile: File;
  originalFileName: string;
  timestamp: string;
  pipeMeasurements?: Record<string, number>;
  fileId?: string;
}

interface FileUploadHandlerConfig {
  cell: CellData | null;
  onCellChange: (updatedCell: CellData) => void;
  onStepFileDataChange: (data: StepFileData) => void;
  onRenderedFileChange: (file: RenderedFileInfo) => void;
  onViewStateChange: (state: 'idle' | 'loading' | 'viewing' | 'error') => void;
  onErrorChange: (error: string | null) => void;
}

export const createFileUploadHandler = (config: FileUploadHandlerConfig) => {
  const globalFileManager = GlobalFileManager.getInstance();
  
  return async (event: React.ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files?.[0];
    if (!file) return;

    if (file.name.toLowerCase().endsWith('.stl')) {
      handleStlUpload(file);
    } 
    else if (file.name.toLowerCase().endsWith('.step') || file.name.toLowerCase().endsWith('.stp')) {
      await handleStepUpload(file);
    } else {
      config.onErrorChange('Please upload an STL or STEP file');
      config.onViewStateChange('error');
    }
  };

  function handleStlUpload(file: File) {
    const newStepFileData = {
      stlFile: file,
      originalFileName: file.name,
      timestamp: new Date().toISOString()
    };
    
    config.onStepFileDataChange(newStepFileData);
    config.onViewStateChange('viewing');
    
    if (config.cell) {
      const reader = new FileReader();
      reader.onload = () => {
        const base64data = reader.result as string;
        const updatedCell: CellData = {
          ...config.cell,
          stlFile: {
            name: file.name,
            data: base64data,
            type: 'model/stl'
          }
        };
        config.onCellChange(updatedCell);
      };
      reader.readAsDataURL(file);
    }
  }

  async function handleStepUpload(file: File) {
    config.onViewStateChange('loading');
    try {
      const buffer = await file.arrayBuffer();
      const tempPath = await window.electronWindow.saveTempFile(buffer);
      const result = await window.stepConverter.convertStep(tempPath);
      
      if (result.success) {
        const stlBlob = new Blob([result.stl_data], { type: 'model/stl' });
        const newFileName = file.name.replace(/\.(step|stp)$/i, '.stl');
        const stlFile = new File([stlBlob], newFileName, { type: 'model/stl' });
        
        const fileId = await globalFileManager.addFileFromUpload(stlFile, file.name);

        if (result.pipe_measurements) {
          Object.entries(result.pipe_measurements).forEach(([name, value]) => {
            globalFileManager.addMeasurement(fileId, name, value as number);
          });
        }

        config.onStepFileDataChange({
          stlFile,
          originalFileName: file.name,
          timestamp: new Date().toISOString(),
          pipeMeasurements: result.pipe_measurements,
          fileId
        });
        
        config.onViewStateChange('viewing');
        config.onRenderedFileChange({
          file: stlFile,
          timestamp: new Date().toISOString(),
          success: true,
          originalFileName: file.name
        });

        if (config.cell) {
          const updatedCell: CellData = {
            ...config.cell,
            globalFileIds: [...(config.cell.globalFileIds || []), fileId]
          };
          config.onCellChange(updatedCell);
        }
      } else {
        config.onErrorChange(result.error || 'Failed to convert STEP file');
        config.onViewStateChange('error');
      }
    } catch (error) {
      config.onErrorChange(error instanceof Error ? error.message : 'Error converting file');
      config.onViewStateChange('error');
    }
  }
};

export default createFileUploadHandler;