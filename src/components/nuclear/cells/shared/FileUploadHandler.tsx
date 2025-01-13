import React, { useRef } from 'react';
import { CellData } from '@/backend/models/Cell';

interface FileUploadHandlerProps {
  onFileSelect: (file: File) => void;
  acceptedTypes?: string;
  children?: React.ReactNode;
}

/**
 * Handles file upload interactions across different cell types
 */
const FileUploadHandler: React.FC<FileUploadHandlerProps> = ({
  onFileSelect,
  acceptedTypes = '.stl,.step,.stp',
  children
}) => {
  const fileInputRef = useRef<HTMLInputElement>(null);

  const handleFileChange = (event: React.ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files?.[0];
    if (file) {
      onFileSelect(file);
    }
  };

  return (
    <>
      <input
        type="file"
        ref={fileInputRef}
        onChange={handleFileChange}
        className="hidden"
        accept={acceptedTypes}
      />
      <div onClick={() => fileInputRef.current?.click()}>
        {children}
      </div>
    </>
  );
};

export default FileUploadHandler; 