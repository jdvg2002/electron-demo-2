import React, { useState } from 'react';
import { FileText, Download, Eye } from 'lucide-react';
import { CellData } from '@/backend/models/Cell';

interface CellOutputDisplayProps {
  previousCell?: CellData;
  nextCell?: CellData;
}

export const CellOutputDisplay: React.FC<CellOutputDisplayProps> = ({
  previousCell,
  nextCell
}) => {
  const [showPreview, setShowPreview] = useState(false);

  if (!previousCell?.output) return null;

  const isPreprocessing = previousCell.type === 'preprocessing';
  const isPostprocessing = previousCell.type === 'postprocessing';
  
  const title = isPreprocessing ? 'Preprocessing Output' : 
                isPostprocessing ? 'Postprocessing Output' : 
                'Analysis Output';
  
  const filename = isPreprocessing ? 'preprocessing-output.json' : 
                  isPostprocessing ? 'postprocessing-output.json' : 
                  'analysis-output.json';

  const handleDownload = () => {
    const jsonString = JSON.stringify(previousCell.output, null, 2);
    const blob = new Blob([jsonString], { type: 'application/json' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = filename;
    document.body.appendChild(a);
    a.click();
    document.body.removeChild(a);
    URL.revokeObjectURL(url);
  };

  return (
    <div className="mx-8 my-4 bg-gray-50 border rounded-lg p-4">
      <div className="flex items-center justify-between">
        <div className="flex items-center gap-4">
          <FileText className="w-4 h-4 text-gray-500" />
          <div>
            <p className="font-medium">{title}</p>
            <p className="text-sm text-gray-500">
              JSON • {new Date(previousCell.output.metadata?.analysisTimestamp || '').toLocaleString()}
            </p>
          </div>
        </div>
        <div className="flex gap-2">
          <button 
            onClick={() => setShowPreview(!showPreview)}
            className="p-2 hover:bg-gray-100 rounded transition-colors"
            aria-label="Preview output"
          >
            <Eye className="w-4 h-4" />
          </button>
          <button 
            onClick={handleDownload}
            className="p-2 hover:bg-gray-100 rounded transition-colors"
            aria-label="Download output"
          >
            <Download className="w-4 h-4" />
          </button>
        </div>
      </div>
      
      {showPreview && (
        <div className="mt-4">
          <pre className="bg-white p-3 rounded-md text-sm overflow-x-auto">
            {JSON.stringify(previousCell.output, null, 2)}
          </pre>
        </div>
      )}
    </div>
  );
}; 