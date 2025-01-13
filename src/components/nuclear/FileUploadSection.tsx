import React, { useState } from 'react';
import FileUploadHandler from './FileUploadHandler';
import VisualizationGrid, { createVisualizationCards } from './CellVisualization';
import FileRenderInfo, { RenderedFileInfo } from './FileRenderInfo';

const FileUploadSection: React.FC = () => {
  const [uploadError, setUploadError] = useState<string | null>(null);
  const [viewState, setViewState] = useState<'idle' | 'loading' | 'viewing' | 'error'>('idle');
  const [renderedFiles, setRenderedFiles] = useState<RenderedFileInfo[]>([]);
  const [stepFilesData, setStepFilesData] = useState<any[]>([]);

  const { fileInputRef, handleFileUpload } = FileUploadHandler({
    cell: null,
    onCellChange: (updatedCell) => {
    },
    onStepFileDataChange: (newStepData) => {
      setStepFilesData(prev => [...prev, newStepData]);
    },
    onRenderedFileChange: (newRenderedFile) => {
      setRenderedFiles(prev => [...prev, newRenderedFile]);
    },
    onViewStateChange: setViewState,
    onErrorChange: setUploadError
  });

  const handleFiles = (files: FileList) => {
    Array.from(files).forEach(file => {
      if (fileInputRef.current) {
        const dataTransfer = new DataTransfer();
        dataTransfer.items.add(file);
        fileInputRef.current.files = dataTransfer.files;
        handleFileUpload({ target: fileInputRef.current } as any);
      }
    });
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
                <input
                  type="file"
                  ref={fileInputRef}
                  onChange={(e) => e.target.files && handleFiles(e.target.files)}
                  accept=".stl,.step,.stp"
                  className="hidden"
                  multiple
                />
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
              {renderedFiles.length > 1 && (
                <button
                  onClick={clearAllFiles}
                  className="text-red-500 hover:text-red-600 text-sm"
                >
                  Clear All Files
                </button>
              )}
            </div>
            <VisualizationGrid 
              cards={stepFilesData.flatMap(data => 
                createVisualizationCards(data.stlFile, data.pipeMeasurements)
              )}
              cardsPerRow={5}
            />
          </div>
        )}
      </div>
    </div>
  );
};

export default FileUploadSection; 