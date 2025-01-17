import React, { useState, useMemo, useRef, useCallback, useEffect } from 'react';
import { createFileUploadHandler } from './FileUploadHandler';
import VisualizationGrid, { createVisualizationCards } from './CellVisualization';
import FileRenderInfo, { RenderedFileInfo } from './FileRenderInfo';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';
import { motion, AnimatePresence } from 'framer-motion';

const FileUploadSection: React.FC = () => {
  const fileInputRef = useRef<HTMLInputElement>(null);
  const [uploadError, setUploadError] = useState<string | null>(null);
  const [viewState, setViewState] = useState<'idle' | 'loading' | 'viewing' | 'error'>('idle');
  const [renderedFiles, setRenderedFiles] = useState<RenderedFileInfo[]>([]);
  const [stepFilesData, setStepFilesData] = useState<any[]>([]);
  const [isExpanded, setIsExpanded] = useState(false);
  const [fileIds, setFileIds] = useState<string[]>([]);
  const [updateTrigger, setUpdateTrigger] = useState(0);

  const globalFileManager = GlobalFileManager.getInstance();

  useEffect(() => {
    return globalFileManager.addListener(() => {
      setUpdateTrigger(prev => prev + 1);
    });
  }, []);

  const handleFileUpload = useMemo(() => createFileUploadHandler({
    cell: null,
    onCellChange: () => {},
    onStepFileDataChange: async (newStepData) => {
      try {
        setViewState('loading');
        
        const fileId = newStepData.fileId;

        setFileIds(prev => [...prev, fileId]);
        setStepFilesData(prev => [...prev, { ...newStepData, id: fileId }]);
        
        setViewState('viewing');
        setIsExpanded(true);
      } catch (error) {
        console.error('Error creating file:', error);
        setUploadError(error instanceof Error ? error.message : 'Failed to create file');
        setViewState('error');
      }
    },
    onRenderedFileChange: (newRenderedFile) => {
      setRenderedFiles(prev => [...prev, newRenderedFile]);
    },
    onViewStateChange: setViewState,
    onErrorChange: setUploadError
  }), [globalFileManager]);

  const handleFiles = (files: FileList) => {
    if (files.length > 0 && fileInputRef.current) {
      const dataTransfer = new DataTransfer();
      dataTransfer.items.add(files[0]);
      fileInputRef.current.files = dataTransfer.files;
      handleFileUpload({ target: fileInputRef.current } as any);
    }
  };

  const clearAllFiles = () => {
    setRenderedFiles([]);
    setStepFilesData([]);
    setViewState('idle');
    setUploadError(null);
    if (fileInputRef.current) {
      fileInputRef.current.value = '';
    }
  };

  const removeFile = (index: number) => {
    setRenderedFiles(prev => prev.filter((_, i) => i !== index));
    setStepFilesData(prev => prev.filter((_, i) => i !== index));
    setFileIds(prev => prev.filter((_, i) => i !== index));
  };

  const handleAddVariable = useCallback((variable: Omit<VariableRecord, 'id'>) => {
    const globalFileManager = GlobalFileManager.getInstance();
    
    if (variable.type === 'distribution') {
      globalFileManager.addDistribution(
        variable.fileId,
        variable.label,
        variable.mean,
        variable.stdDev,
        variable.name
      );
    } else if (variable.type === 'measurement') {
      globalFileManager.addMeasurement(
        variable.fileId,
        variable.name,
        variable.value,
        variable.units
      );
    }
  }, []);

  const handleDeleteVariable = useCallback((label: string) => {
    const globalFileManager = GlobalFileManager.getInstance();
    const fileId = fileIds[0]; // or handle multiple files if needed
    
    // Find and delete the variable with this label
    const variables = globalFileManager.getVariablesForFile(fileId);
    const variableToDelete = variables.find(v => v.type === 'distribution' && v.label === label);
    
    if (variableToDelete) {
      globalFileManager.removeVariable(variableToDelete.id);
      
      // Force a re-render by updating stepFilesData
      setStepFilesData(prev => [...prev]);
    }
  }, [fileIds]);

  return (
    <div className="w-full p-6 bg-[#f6f6f6] border-2 border-gray-200 rounded-lg">
      <input
        type="file"
        ref={fileInputRef}
        onChange={handleFileUpload}
        className="hidden"
        accept=".stl,.step,.stp"
      />
      
      <div className="flex flex-col items-center gap-4">
        {stepFilesData.length === 0 ? (
          <>
            <h2 className="text-xl font-semibold text-gray-700">Upload Files</h2>
            <div 
              className="w-full max-w-xl h-32 border-2 border-dashed border-gray-300 rounded-lg flex items-center justify-center"
              onDragOver={(e) => e.preventDefault()}
              onDrop={(e) => {
                e.preventDefault();
                handleFiles(e.dataTransfer.files);
              }}
            >
              <div className="text-center">
                <p className="text-gray-600">
                  {uploadError ? (
                    <span className="text-red-500">{uploadError}</span>
                  ) : (
                    "Drag and drop your files here, or"
                  )}
                </p>
                <button 
                  className="mt-2 text-blue-500 hover:text-blue-600 font-medium"
                  onClick={() => fileInputRef.current?.click()}
                >
                  Browse Files
                </button>
                {viewState === 'loading' && (
                  <p className="mt-2 text-gray-500">Converting files...</p>
                )}
              </div>
            </div>
          </>
        ) : (
          <div className="w-full">
            <div className="flex items-center gap-2">
              <button
                onClick={() => setIsExpanded(!isExpanded)}
                className="flex items-center gap-2 px-3 py-1.5 text-xs font-medium text-gray-600 hover:bg-gray-100 rounded-md border border-gray-200"
              >
                Global Variables {isExpanded ? '▼' : '▶'}
              </button>

              <div className="flex flex-wrap gap-2">
                {renderedFiles.map((fileInfo, index) => (
                  <FileRenderInfo 
                    key={index}
                    fileInfo={fileInfo}
                    onClear={() => removeFile(index)}
                  />
                ))}
              </div>

              <button
                onClick={() => fileInputRef.current?.click()}
                className="ml-auto px-3 py-1.5 text-xs font-medium text-white bg-[#0086bb] hover:bg-[#4fcdff] rounded-md"
              >
                Upload More
              </button>
              
              {renderedFiles.length > 1 && (
                <button
                  onClick={clearAllFiles}
                  className="text-xs font-medium text-red-500 hover:text-red-600"
                >
                  Clear All
                </button>
              )}
            </div>

            <AnimatePresence>
              {isExpanded && (
                <motion.div
                  initial={{ opacity: 0, height: 0 }}
                  animate={{ opacity: 1, height: 'auto' }}
                  exit={{ opacity: 0, height: 0 }}
                  transition={{ duration: 0.2 }}
                  className="overflow-hidden"
                >
                  <div className="mt-4">
                    <VisualizationGrid 
                      key={`grid-${updateTrigger}`}
                      cards={fileIds.flatMap(fileId => {
                        const file = globalFileManager.getFileById(fileId);
                        return file ? createVisualizationCards(fileId, file.stlFile) : [];
                      })}
                      cardsPerRow={6}
                      fileId={fileIds[0]}
                      onAddVariable={handleAddVariable}
                      onDeleteVariable={handleDeleteVariable}
                    />
                  </div>
                </motion.div>
              )}
            </AnimatePresence>
          </div>
        )}
      </div>
    </div>
  );
};

export default FileUploadSection; 