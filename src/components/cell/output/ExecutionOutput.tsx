import React from 'react';
import { Download } from 'lucide-react';

interface ExecutionOutputProps {
  output: any;
  onDownload?: () => void;
}

export const ExecutionOutput: React.FC<ExecutionOutputProps> = ({
  output,
  onDownload
}) => {
  const handleDownload = () => {
    const blob = new Blob([JSON.stringify(output, null, 2)], 
      { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = 'preprocessing-output.json';
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
  };

  return (
    <div className="mt-4 bg-gray-50 border rounded-lg p-4">
      <div className="flex items-center justify-between mb-2">
        <h3 className="text-sm font-medium">Output</h3>
        <button
          onClick={handleDownload}
          className="flex items-center gap-2 text-sm text-blue-500 hover:text-blue-600"
        >
          <Download className="w-4 h-4" />
          Download JSON
        </button>
      </div>
      <pre className="bg-white p-3 rounded-md text-sm overflow-x-auto">
        {JSON.stringify(output, null, 2)}
      </pre>
    </div>
  );
}; 