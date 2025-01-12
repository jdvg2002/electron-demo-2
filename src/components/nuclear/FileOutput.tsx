import React from 'react';
import { FileText, Download } from 'lucide-react';

interface FileOutputProps {
  file: {
    name: string;
    size: string;
    format: string;
    timestamp: string;
  };
  className?: string;
  onDownload?: () => void;
}

const FileOutput = ({ file, className = '', onDownload }: FileOutputProps) => {
  const handleDownload = () => {
    onDownload?.();
  };

  return (
    <div className={`bg-gray-50 border rounded-lg p-4 ${className}`}>
      <h3 className="text-sm font-medium mb-2">Output File</h3>
      <div className="flex items-center justify-between">
        <div className="flex items-center gap-4">
          <FileText className="w-4 h-4 text-gray-500" />
          <div>
            <p className="font-medium">{file.name}</p>
            <p className="text-sm text-gray-500">
              {file.format} • {file.size}
            </p>
          </div>
        </div>
        <button 
          onClick={handleDownload}
          className="p-2 hover:bg-gray-100 rounded transition-colors"
          aria-label="Download file"
        >
          <Download className="w-4 h-4" />
        </button>
      </div>
      <p className="text-xs text-gray-500 mt-2">
        Generated on {file.timestamp}
      </p>
    </div>
  );
};

export default FileOutput;