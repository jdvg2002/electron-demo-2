import React from 'react';

interface ExternalToolProps {
  tool: string;
  status: string;
  input: any;
  executionResult?: any;
}

const ExternalTool: React.FC<ExternalToolProps> = ({
  tool,
  status,
  input,
  executionResult
}) => {
  // Parse the results from the output
  const parseResults = (output: string) => {
    const lines = output.split('\n');
    const results: Record<string, string> = {};
    
    lines.forEach(line => {
      if (line.includes('Time to initiation:')) {
        results.timeToInitiation = line.split(':')[1].trim();
      }
      if (line.includes('Angle offset:')) {
        results.angleOffset = line.split(':')[1].trim();
      }
      if (line.includes('Error code:')) {
        results.errorCode = line.split(':')[1].trim();
      }
    });
    
    return results;
  };

  const results = executionResult?.results ? parseResults(executionResult.results) : null;

  return (
    <div className="space-y-4">
      <div className="flex items-center justify-between">
        <div>
          <h3 className="text-lg font-medium">External Tool: {tool}</h3>
          <p className="text-sm text-gray-500">Status: {status}</p>
        </div>
      </div>

      {results && (
        <div className="mt-4 p-4 bg-gray-50 rounded-lg">
          <h4 className="font-medium mb-2">Fatigue Analysis Results:</h4>
          <div className="grid grid-cols-1 gap-2">
            <div>
              <p className="text-sm text-gray-600">Time to Initiation:</p>
              <p className="font-medium">{results.timeToInitiation} cycles</p>
            </div>
            <div>
              <p className="text-sm text-gray-600">Angle Offset:</p>
              <p className="font-medium">{results.angleOffset} radians</p>
            </div>
            <div>
              <p className="text-sm text-gray-600">Error Code:</p>
              <p className="font-medium">{results.errorCode}</p>
            </div>
          </div>
        </div>
      )}

      {executionResult?.error && (
        <div className="mt-4 p-4 bg-red-50 rounded-lg">
          <h4 className="font-medium mb-2 text-red-700">Error:</h4>
          <pre className="whitespace-pre-wrap font-mono text-sm text-red-600">
            {executionResult.error}
          </pre>
        </div>
      )}
    </div>
  );
};

export default ExternalTool;