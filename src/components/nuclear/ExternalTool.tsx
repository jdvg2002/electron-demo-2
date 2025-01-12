import React from 'react';
import { FileText } from 'lucide-react';
import StatusIndicator from './StatusIndicator';

interface ExternalToolProps {
  tool: string;
  status: string;
  input: {
    file: string;
    status: string;
    checksum?: string;
  };
  className?: string;
}

const ExternalTool = ({ tool, status, input, className = '' }: ExternalToolProps) => {
  return (
    <div className={`space-y-4 ${className}`}>
      {/* Tool Header */}
      <div className="flex items-center gap-4 text-sm text-gray-600">
        <span className="flex items-center gap-2">
          <FileText className="w-4 h-4" />
          {tool}
        </span>
        <StatusIndicator status={status} />
      </div>
      
      {/* Input File Details */}
      <div className="bg-blue-50 p-4 rounded-lg">
        <h3 className="text-sm font-medium text-blue-900 mb-2">Input File</h3>
        <div className="flex items-center justify-between text-sm">
          <div className="flex items-center gap-2">
            <FileText className="w-4 h-4 text-blue-500" />
            <span>{input.file}</span>
          </div>
          <div className="flex items-center gap-4">
            {input.checksum && (
              <span className="text-gray-500">
                Checksum: {input.checksum.slice(0, 8)}...
              </span>
            )}
            <span className="text-blue-600">
              Status: {input.status}
            </span>
          </div>
        </div>
      </div>
    </div>
  );
};

export default ExternalTool;