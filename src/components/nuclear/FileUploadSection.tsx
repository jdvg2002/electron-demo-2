import React, { useState, useMemo, useRef } from 'react';
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

  const globalFileManager = GlobalFileManager.getInstance();

  const handleFileUpload = useMemo(() => createFileUploadHandler({
    cell: null,
    onCellChange: () => {},
    onStepFileDataChange: async (newStepData) => {
      const handleFileCreation = async () => {
        try {
          setViewState('loading');
          
          await globalFileManager.addFileFromUpload(
            newStepData.stlFile,
            newStepData.pipeMeasurements,
            newStepData.originalFileName
          );

          setStepFilesData(prev => [...prev, newStepData]);
          setViewState('viewing');
          setIsExpanded(true);
        } catch (error) {
          console.error('Error creating file:', error);
          setUploadError(error instanceof Error ? error.message : 'Failed to create file');
          setViewState('error');
        }
      };

      handleFileCreation();
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
                className="ml-auto px-3 py-1.5 text-xs font-medium text-white bg-blue-500 hover:bg-blue-600 rounded-md"
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
                      cards={stepFilesData.flatMap(data => 
                        createVisualizationCards(data.stlFile, data.pipeMeasurements)
                      )}
                      cardsPerRow={6}
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