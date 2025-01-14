import React, { useState } from 'react';
import { FileText, Download, Eye } from 'lucide-react';
import ExecutionOutput from './cells/shared/ExecutionOutput';

interface FileOutputProps {
  file: {
    name: string;
    size: string;
    format: string;
    timestamp: string;
    data?: any;
  };
  className?: string;
  onDownload?: () => void;
}

const FileOutput = ({ file, className = '', onDownload }: FileOutputProps) => {
  const [showPreview, setShowPreview] = useState(false);

  const handleDownload = () => {
    if (file.data) {
      const jsonString = JSON.stringify(file.data, null, 2);
      const blob = new Blob([jsonString], { type: 'application/json' });
      
      const url = URL.createObjectURL(blob);
      const a = document.createElement('a');
      a.href = url;
      a.download = file.name.endsWith('.json') ? file.name : `${file.name}.json`;
      
      document.body.appendChild(a);
      a.click();
      
      document.body.removeChild(a);
      URL.revokeObjectURL(url);
    } else {
      onDownload?.();
    }
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
        <div className="flex gap-2">
          <button 
            onClick={() => setShowPreview(!showPreview)}
            className="p-2 hover:bg-gray-100 rounded transition-colors"
            aria-label="Preview file"
          >
            <Eye className="w-4 h-4" />
          </button>
          <button 
            onClick={handleDownload}
            className="p-2 hover:bg-gray-100 rounded transition-colors"
            aria-label="Download file"
          >
            <Download className="w-4 h-4" />
          </button>
        </div>
      </div>
      <p className="text-xs text-gray-500 mt-2">
        Generated on {file.timestamp}
      </p>
      
      {showPreview && file.data && (
        <div className="mt-4">
          <ExecutionOutput result={file.data} />
        </div>
      )}
    </div>
  );
};

export default FileOutput;