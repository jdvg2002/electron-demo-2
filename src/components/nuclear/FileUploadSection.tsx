import React, { useState } from 'react';
import FileUploadHandler from './FileUploadHandler';
import VisualizationGrid, { createVisualizationCards } from './CellVisualization';
import FileRenderInfo, { RenderedFileInfo } from './FileRenderInfo';

const FileUploadSection: React.FC = () => {
  const [uploadError, setUploadError] = useState<string | null>(null);
  const [viewState, setViewState] = useState<'idle' | 'loading' | 'viewing' | 'error'>('idle');
  const [renderedFile, setRenderedFile] = useState<RenderedFileInfo | null>(null);
  const [stepFileData, setStepFileData] = useState<any>(null);

  const { fileInputRef, handleFileUpload } = FileUploadHandler({
    cell: null,
    onCellChange: (updatedCell) => {
    },
    onStepFileDataChange: setStepFileData,
    onRenderedFileChange: setRenderedFile,
    onViewStateChange: setViewState,
    onErrorChange: setUploadError
  });

  return (
    <div className="w-full p-6 bg-white border-2 border-gray-200 rounded-lg">
      <div className="flex flex-col items-center gap-4">
        <h2 className="text-xl font-semibold text-gray-700">Upload Nuclear Data File</h2>
        <div 
          className="w-full max-w-xl h-32 border-2 border-dashed border-gray-300 rounded-lg flex items-center justify-center"
          onDragOver={(e) => e.preventDefault()}
          onDrop={(e) => {
            e.preventDefault();
            const file = e.dataTransfer.files[0];
            if (file) {
              const input = fileInputRef.current;
              if (input) {
                const dataTransfer = new DataTransfer();
                dataTransfer.items.add(file);
                input.files = dataTransfer.files;
                handleFileUpload({ target: input } as any);
              }
            }
          }}
        >
          <div className="text-center">
            <p className="text-gray-600">
              {uploadError ? (
                <span className="text-red-500">{uploadError}</span>
              ) : (
                "Drag and drop your file here, or"
              )}
            </p>
            <input
              type="file"
              ref={fileInputRef}
              onChange={handleFileUpload}
              accept=".stl,.step,.stp"
              className="hidden"
            />
            <button 
              className="mt-2 text-blue-500 hover:text-blue-600 font-medium"
              onClick={() => fileInputRef.current?.click()}
            >
              Browse Files
            </button>
            {viewState === 'loading' && (
              <p className="mt-2 text-gray-500">Converting file...</p>
            )}
          </div>
        </div>

        {/* Visualization Section */}
        {stepFileData && (
          <div className="w-full mt-4">
            {renderedFile && (
              <FileRenderInfo 
                fileInfo={renderedFile}
                onClear={() => {
                  setRenderedFile(null);
                  setStepFileData(null);
                  setViewState('idle');
                  setUploadError(null);
                  if (fileInputRef.current) {
                    fileInputRef.current.value = '';
                  }
                }}
              />
            )}
            <VisualizationGrid 
              cards={createVisualizationCards(stepFileData.stlFile, stepFileData.pipeMeasurements)}
              cardsPerRow={5}
            />
          </div>
        )}
      </div>
    </div>
  );
};

export default FileUploadSection; 