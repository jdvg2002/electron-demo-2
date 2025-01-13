import React from 'react';

interface ExecutionOutputProps {
  stdout?: string;
  result?: any;
}

/**
 * Displays execution results in a consistent format
 */
const ExecutionOutput: React.FC<ExecutionOutputProps> = ({ stdout, result }) => {
  return (
    <div className="mt-4 p-4 bg-gray-50 rounded-lg border border-gray-200">
      <h3 className="font-medium text-sm text-gray-700 mb-2">Output:</h3>
      {stdout && (
        <pre className="bg-white p-3 rounded-md text-sm overflow-x-auto mb-2 text-gray-600">
          {stdout}
        </pre>
      )}
      {result !== undefined && result !== null && (
        <>
          <h4 className="font-medium text-sm text-gray-700 mb-1">Return Value:</h4>
          <pre className="bg-white p-3 rounded-md text-sm overflow-x-auto text-gray-800">
            {typeof result === 'object' 
              ? JSON.stringify(result, null, 2)
              : String(result)}
          </pre>
        </>
      )}
    </div>
  );
};

export default ExecutionOutput; 