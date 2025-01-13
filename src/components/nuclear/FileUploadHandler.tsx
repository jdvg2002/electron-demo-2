import { FileModuleManager } from '@/backend/manager/FileModuleManager';
import React from 'react';
import { CellData } from '@/backend/models/Cell';
import { RenderedFileInfo } from './FileRenderInfo';

interface PipeMeasurements {
  inner_diameter: number;
  outer_diameter: number;
  wall_thickness: number;
}

interface StepFileData {
  stlFile: File;
  pipeMeasurements: PipeMeasurements;
  originalFileName: string;
  timestamp: string;
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
      pipeMeasurements: null,
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
        
        const newStepFileData = {
          stlFile,
          pipeMeasurements: result.pipe_measurements,
          originalFileName: file.name,
          timestamp: new Date().toISOString()
        };

        config.onStepFileDataChange(newStepFileData);
        config.onViewStateChange('viewing');
        config.onRenderedFileChange({
          file: stlFile,
          timestamp: new Date().toISOString(),
          success: true,
          originalFileName: file.name
        });

        if (config.cell) {
          const reader = new FileReader();
          reader.onload = () => {
            const base64data = reader.result as string;
            const updatedCell: CellData = {
              ...config.cell,
              stlFile: {
                name: newFileName,
                data: base64data,
                type: 'model/stl'
              },
              pipeMeasurements: result.pipe_measurements
            };
            config.onCellChange(updatedCell);
          };
          reader.readAsDataURL(stlFile);
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