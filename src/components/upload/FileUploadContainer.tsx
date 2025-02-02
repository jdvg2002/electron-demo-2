import React, { useRef, useEffect } from 'react';
import { useFileUpload } from '@/hooks/useFileUpload';
import { FileList } from '@/components/upload/FileList';
import { VisualizationManager } from '@/components/visualization/VisualizationManager';
import { motion, AnimatePresence } from 'framer-motion';

export const FileUploadContainer: React.FC = () => {
  const fileInputRef = useRef<HTMLInputElement>(null);
  const { 
    files, 
    isLoading, 
    error, 
    uploadFile, 
    removeFile,
    isExpanded,
    setIsExpanded
  } = useFileUpload();

  const handleFiles = (fileList: FileList) => {
    if (fileList.length > 0) {
      uploadFile(fileList[0]);
      if (fileInputRef.current) {
        fileInputRef.current.value = '';
      }
    }
  };

  useEffect(() => {
    if (fileInputRef.current && files.length === 0) {
      fileInputRef.current.value = '';
    }
  }, [files.length]);

  return (
    <div className="w-full p-6 bg-[#f6f6f6] border-2 border-gray-200 rounded-lg">
      <input
        type="file"
        ref={fileInputRef}
        onChange={(e) => e.target.files && handleFiles(e.target.files)}
        className="hidden"
        accept=".gltf,.step,.stp,.csv,.glb"
      />
      
      <div className="flex flex-col items-center gap-4">
        {files.length === 0 ? (
          <UploadPrompt 
            error={error}
            isLoading={isLoading}
            onUpload={() => fileInputRef.current?.click()}
            onDrop={(e) => {
              e.preventDefault();
              handleFiles(e.dataTransfer.files);
            }}
          />
        ) : (
          <div className="w-full">
            <FileList
              files={files}
              onRemoveFile={removeFile}
              onUploadMore={() => fileInputRef.current?.click()}
              isExpanded={isExpanded}
              onToggleExpand={() => setIsExpanded(!isExpanded)}
            />
            
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
                    <VisualizationManager files={files} />
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

const UploadPrompt: React.FC<{
  error: string | null;
  isLoading: boolean;
  onUpload: () => void;
  onDrop: (e: React.DragEvent) => void;
}> = ({ error, isLoading, onUpload, onDrop }) => (
  <>
    <h2 className="text-xl font-semibold text-gray-700">Upload Files</h2>
    <div 
      className="w-full max-w-xl h-32 border-2 border-dashed border-gray-300 rounded-lg flex items-center justify-center"
      onDragOver={(e) => e.preventDefault()}
      onDrop={onDrop}
    >
      <div className="text-center">
        <p className="text-gray-600">
          {error ? (
            <span className="text-red-500">{error}</span>
          ) : (
            "Drag and drop your files here, or"
          )}
        </p>
        <button 
          className="mt-2 text-blue-500 hover:text-blue-600 font-medium"
          onClick={onUpload}
        >
          Browse Files
        </button>
        {isLoading && (
          <p className="mt-2 text-gray-500">Converting files...</p>
        )}
      </div>
    </div>
  </>
); 