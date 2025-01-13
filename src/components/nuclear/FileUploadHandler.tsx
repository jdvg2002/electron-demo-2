import React, { useState } from 'react';
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

interface FileUploadHandlerProps {
  cell: CellData;
  onCellChange: (updatedCell: CellData) => void;
  onStepFileDataChange: (data: StepFileData | null) => void;
  onRenderedFileChange: (file: RenderedFileInfo | null) => void;
  onViewStateChange: (state: 'idle' | 'loading' | 'viewing' | 'error') => void;
  onErrorChange: (error: string | null) => void;
}

const FileUploadHandler: React.FC<FileUploadHandlerProps> = ({
  cell,
  onCellChange,
  onStepFileDataChange,
  onRenderedFileChange,
  onViewStateChange,
  onErrorChange,
}) => {
  const fileInputRef = React.useRef<HTMLInputElement>(null);

  const handleFileUpload = async (event: React.ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files?.[0];
    if (!file) return;

    if (file.name.toLowerCase().endsWith('.stl')) {
      handleStlUpload(file);
    } 
    else if (file.name.toLowerCase().endsWith('.step') || file.name.toLowerCase().endsWith('.stp')) {
      await handleStepUpload(file);
    } else {
      onErrorChange('Please upload an STL or STEP file');
      onViewStateChange('error');
    }
  };

  const handleStlUpload = (file: File) => {
    const newStepFileData = {
      stlFile: file,
      pipeMeasurements: null,
      originalFileName: file.name,
      timestamp: new Date().toISOString()
    };
    
    onStepFileDataChange(newStepFileData);
    onViewStateChange('viewing');
    
    const reader = new FileReader();
    reader.onload = () => {
      const base64data = reader.result as string;
      const updatedCell: CellData = {
        ...cell,
        stlFile: {
          name: file.name,
          data: base64data,
          type: 'model/stl'
        }
      };
      onCellChange(updatedCell);
    };
    reader.readAsDataURL(file);
  };

  const handleStepUpload = async (file: File) => {
    onViewStateChange('loading');
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

        onStepFileDataChange(newStepFileData);
        onViewStateChange('viewing');
        onRenderedFileChange({
          file: stlFile,
          timestamp: new Date().toISOString(),
          success: true,
          originalFileName: file.name
        });

        const reader = new FileReader();
        reader.onload = () => {
          const base64data = reader.result as string;
          const updatedCell: CellData = {
            ...cell,
            stlFile: {
              name: newFileName,
              data: base64data,
              type: 'model/stl'
            },
            pipeMeasurements: result.pipe_measurements
          };
          onCellChange(updatedCell);
        };
        reader.readAsDataURL(stlFile);
      } else {
        onErrorChange(result.error || 'Failed to convert STEP file');
        onViewStateChange('error');
      }
    } catch (error) {
      onErrorChange(error instanceof Error ? error.message : 'Error converting file');
      onViewStateChange('error');
    }
  };

  return {
    fileInputRef,
    handleFileUpload
  };
};

export default FileUploadHandler;