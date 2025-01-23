import { useState, useEffect, useCallback } from 'react';
import { FileUploadManager, FileUploadState } from '@/backend/models/FileUploadManager';
import { VariableRecord } from '@/backend/Variable';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';

export function useFileUpload() {
  const [state, setState] = useState<FileUploadState>(() => 
    FileUploadManager.getInstance().getFilesState()
  );
  const [isExpanded, setIsExpanded] = useState(false);

  useEffect(() => {
    const globalFileManager = GlobalFileManager.getInstance();
    return globalFileManager.addListener(() => {
      setState(FileUploadManager.getInstance().getFilesState());
    });
  }, []);

  const uploadFile = useCallback(async (file: File) => {
    try {
      setState(prev => ({ ...prev, isLoading: true, error: null }));
      const manager = FileUploadManager.getInstance();
      await manager.uploadFile(file);
      setState(manager.getFilesState());
    } catch (error) {
      setState(prev => ({
        ...prev,
        isLoading: false,
        error: error instanceof Error ? error.message : 'Failed to upload file'
      }));
    }
  }, []);

  const removeFile = useCallback((fileId: string) => {
    const manager = FileUploadManager.getInstance();
    manager.removeFile(fileId);
    setState(manager.getFilesState());
  }, []);

  const addMeasurement = useCallback((fileId: string, measurement: Omit<VariableRecord, 'id'>) => {
    const manager = FileUploadManager.getInstance();
    manager.addMeasurement(fileId, measurement);
  }, []);

  const addDistribution = useCallback((fileId: string, distribution: Omit<VariableRecord, 'id'>) => {
    const manager = FileUploadManager.getInstance();
    manager.addDistribution(fileId, distribution);
  }, []);

  return {
    ...state,
    uploadFile,
    removeFile,
    addMeasurement,
    addDistribution,
    isExpanded,
    setIsExpanded
  };
} 