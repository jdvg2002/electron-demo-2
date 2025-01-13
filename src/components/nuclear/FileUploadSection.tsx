import React, { useState, useMemo, useRef } from 'react';
import { createFileUploadHandler } from './FileUploadHandler';
import VisualizationGrid, { createVisualizationCards } from './CellVisualization';
import FileRenderInfo, { RenderedFileInfo } from './FileRenderInfo';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';

const FileUploadSection: React.FC = () => {
  const fileInputRef = useRef<HTMLInputElement>(null);
  const [uploadError, setUploadError] = useState<string | null>(null);
  const [viewState, setViewState] = useState<'idle' | 'loading' | 'viewing' | 'error'>('idle');
  const [renderedFiles, setRenderedFiles] = useState<RenderedFileInfo[]>([]);
  const [stepFilesData, setStepFilesData] = useState<any[]>([]);

  const moduleManager = useMemo(() => ModuleManager.getInstance(), []);
  const fileManager = useMemo(() => GlobalFileManager.getInstance(), []);

  const handleFileUpload = useMemo(() => createFileUploadHandler({
    cell: null,
    onCellChange: () => {},
    onStepFileDataChange: async (newStepData) => {
      const processFile = async () => {
        try {
          console.log('Processing file:', {
            name: newStepData.stlFile.name,
            size: newStepData.stlFile.size,
            type: newStepData.stlFile.type
          });

          // Check if this is a STEP file that needs conversion
          if (newStepData.stlFile.name.toLowerCase().endsWith('.step') || 
              newStepData.stlFile.name.toLowerCase().endsWith('.stp')) {
            // Where was your STEP to STL conversion happening before?
            // We need to add that back in here
            console.log('Need to convert STEP to STL first');
            return;
          }

          // Continue with STL processing
          setStepFilesData(prev => {
            console.log('Setting stepFilesData:', newStepData);
            return [...prev, newStepData];
          });
          setViewState('viewing');

          // Read file data
          const reader = new FileReader();
          reader.onload = () => {
            const globalFile = {
              id: Date.now().toString(),
              stlFile: {
                name: newStepData.stlFile.name,
                data: '',
                type: newStepData.stlFile.type
              },
              pipeMeasurements: newStepData.pipeMeasurements,
              timestamp: new Date().toISOString(),
              originalFileName: newStepData.originalFileName
            };

            globalFile.stlFile.data = reader.result as string;
            fileManager.addFile(globalFile);
            moduleManager.createPreprocessingModule(globalFile);
          };

          reader.onerror = () => {
            throw new Error('Failed to read file');
          };

          reader.readAsDataURL(newStepData.stlFile);

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
  }), [fileManager, moduleManager]);

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
        ) : null}

        {/* Visualization Section */}
        {stepFilesData.length > 0 && (
          <div className="w-full mt-4">
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
              cardsPerRow={5}
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
        )}
      </div>
    </div>
  );
};

export default FileUploadSection; 