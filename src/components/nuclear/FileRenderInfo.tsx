import React from 'react';
import { Check, X, FileText } from 'lucide-react';
import { Tooltip } from '@/components/ui/tooltip';

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
    <Tooltip content={`Uploaded: ${new Date(fileInfo.timestamp).toLocaleString()}`}>
      <div className="flex items-center gap-2 px-2 py-1 bg-gray-50 rounded border border-gray-200 text-xs">
        <FileText className="w-3 h-3 text-gray-500" />
        <span className="truncate max-w-[120px]" title={fileInfo.originalFileName}>
          {fileInfo.originalFileName}
        </span>
        {fileInfo.success ? (
          <Check className="w-3 h-3 text-green-500 flex-shrink-0" />
        ) : null}
        <button
          onClick={onClear}
          className="ml-auto p-1 hover:bg-gray-200 rounded-sm"
          title="Remove file"
        >
          <X className="w-3 h-3 text-gray-400 hover:text-gray-600" />
        </button>
      </div>
    </Tooltip>
  );
};

export default FileRenderInfo; 