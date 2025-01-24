import React from 'react';
import { ParsedFileResult } from '@/backend/manager/FileUploadManager';
import FileRenderInfo from './FileRenderInfo';

interface FileListProps {
  files: ParsedFileResult[];
  onRemoveFile: (fileId: string) => void;
  onUploadMore: () => void;
  isExpanded: boolean;
  onToggleExpand: () => void;
}

export const FileList: React.FC<FileListProps> = ({
  files,
  onRemoveFile,
  onUploadMore,
  isExpanded,
  onToggleExpand,
}) => {
  return (
    <div className="flex items-center gap-2">
      <button
        onClick={onToggleExpand}
        className="flex items-center gap-2 px-3 py-1.5 text-xs font-medium text-gray-600 hover:bg-gray-100 rounded-md border border-gray-200"
      >
        Global Variables {isExpanded ? '▼' : '▶'}
      </button>

      <div className="flex flex-wrap gap-2">
        {files.map((file) => (
          <FileRenderInfo 
            key={file.fileId}
            fileInfo={{
              file: file.rawFile,
              timestamp: file.timestamp,
              originalFileName: file.originalFileName,
              success: true
            }}
            onClear={() => onRemoveFile(file.fileId)}
          />
        ))}
      </div>

      <button
        onClick={onUploadMore}
        className="ml-auto px-3 py-1.5 text-xs font-medium text-white bg-[#0086bb] hover:bg-[#4fcdff] rounded-md"
      >
        Upload More
      </button>
      
      {files.length > 1 && (
        <button
          onClick={() => files.forEach(f => onRemoveFile(f.fileId))}
          className="text-xs font-medium text-red-500 hover:text-red-600"
        >
          Clear All
        </button>
      )}
    </div>
  );
}; 