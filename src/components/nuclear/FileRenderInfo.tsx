import React from 'react';
import { Check } from 'lucide-react';

export interface RenderedFileInfo {
  file: File;
  timestamp: string;
  success: boolean;
  originalFileName: string;
}

interface FileRenderInfoProps {
  fileInfo: RenderedFileInfo;
  onClear: () => void;
}

const FileRenderInfo: React.FC<FileRenderInfoProps> = ({ fileInfo, onClear }) => {
  return (
    <div className="flex items-center justify-between p-3 bg-green-50 rounded-lg border border-green-200">
      <div className="flex items-center gap-3">
        <Check className="w-5 h-5 text-green-500" />
        <div>
          <p className="font-medium text-green-700">{fileInfo.originalFileName}</p>
          <p className="text-sm text-green-600">
            {new Date(fileInfo.timestamp).toLocaleString()}
          </p>
        </div>
      </div>
      <button
        onClick={onClear}
        className="px-3 py-1 text-sm text-green-700 hover:bg-green-100 rounded"
      >
        Clear
      </button>
    </div>
  );
};

export default FileRenderInfo; 