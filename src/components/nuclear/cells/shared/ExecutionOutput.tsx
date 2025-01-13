import React from 'react';

interface ExecutionOutputProps {
  stdout?: string;
  result?: any;
}

/**
 * Displays execution results in a consistent format
 */
const ExecutionOutput: React.FC<ExecutionOutputProps> = ({ stdout, result }) => {
  // If we have a result, show that. Otherwise, show stdout
  const output = result !== undefined ? result : stdout;
  
  if (!output) return null;

  return (
    <div className="mt-4 p-4 bg-gray-50 rounded-lg border border-gray-200">
      <pre className="bg-white p-3 rounded-md text-sm overflow-x-auto text-gray-800">
        {typeof output === 'object' 
          ? JSON.stringify(output, null, 2)
          : String(output)}
      </pre>
    </div>
  );
};

export default ExecutionOutput; 