import React, { useState, useMemo, useRef } from 'react';
import { createFileUploadHandler } from './FileUploadHandler';
import VisualizationGrid, { createVisualizationCards } from './CellVisualization';
import FileRenderInfo, { RenderedFileInfo } from './FileRenderInfo';
import { FileModuleManager } from '@/backend/manager/FileModuleManager';
import { motion, AnimatePresence } from 'framer-motion';

const FileUploadSection: React.FC = () => {
  const fileInputRef = useRef<HTMLInputElement>(null);
  const [uploadError, setUploadError] = useState<string | null>(null);
  const [viewState, setViewState] = useState<'idle' | 'loading' | 'viewing' | 'error'>('idle');
  const [renderedFiles, setRenderedFiles] = useState<RenderedFileInfo[]>([]);
  const [stepFilesData, setStepFilesData] = useState<any[]>([]);
  const [isExpanded, setIsExpanded] = useState(false);

  const fileModuleManager = FileModuleManager.getInstance();

  const handleFileUpload = useMemo(() => createFileUploadHandler({
    cell: null,
    onCellChange: () => {},
    onStepFileDataChange: async (newStepData) => {
      const processFile = async () => {
        try {
          setViewState('loading');
          
          await fileModuleManager.createModuleFromFile(
            newStepData.stlFile,
            newStepData.pipeMeasurements,
            newStepData.originalFileName
          );

          setStepFilesData(prev => [...prev, newStepData]);
          setViewState('viewing');
        } catch (error) {
          console.error('Error processing file:', error);
          setUploadError(error instanceof Error ? error.message : 'Failed to process file');
          setViewState('error');
        }
      };

      processFile();
    },
    onRenderedFileChange: (newRenderedFile) => {
      setRenderedFiles(prev => [...prev, newRenderedFile]);
    },
    onViewStateChange: setViewState,
    onErrorChange: setUploadError
  }), [fileModuleManager]);

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
  };

  return (
    <div className="w-full p-6 bg-white border-2 border-gray-200 rounded-lg">
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
            <h2 className="text-xl font-semibold text-gray-700">Upload Nuclear Data Files</h2>
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
            <button
              onClick={() => setIsExpanded(!isExpanded)}
              className="bg-blue-500 hover:bg-blue-600 text-white px-4 py-2 rounded w-full"
            >
              Global Variables {isExpanded ? '▼' : '▶'}
            </button>

            <AnimatePresence>
              {isExpanded && (
                <motion.div
                  initial={{ opacity: 0, height: 0 }}
                  animate={{ opacity: 1, height: 'auto' }}
                  exit={{ opacity: 0, height: 0 }}
                  transition={{ duration: 0.3 }}
                  className="overflow-hidden"
                >
                  <div className="mt-4">
                    <div className="mb-4 space-y-2">
                      {renderedFiles.map((fileInfo, index) => (
                        <FileRenderInfo 
                          key={index}
                          fileInfo={fileInfo}
                          onClear={() => removeFile(index)}
                        />
                      ))}
                    </div>
                    
                    <VisualizationGrid 
                      cards={stepFilesData.flatMap(data => 
                        createVisualizationCards(data.stlFile, data.pipeMeasurements)
                      )}
                      cardsPerRow={7}
                    />

                    <div className="mt-4 flex justify-between items-center">
                      <button
                        onClick={() => fileInputRef.current?.click()}
                        className="bg-blue-500 hover:bg-blue-600 text-white px-4 py-2 rounded"
                      >
                        Upload More Files
                      </button>
                      {renderedFiles.length > 1 && (
                        <button
                          onClick={clearAllFiles}
                          className="text-red-500 hover:text-red-600"
                        >
                          Clear All Files
                        </button>
                      )}
                    </div>
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