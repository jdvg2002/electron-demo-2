import React from 'react';

interface LoadingIndicatorProps {
  message?: string;
}

/**
 * Displays a loading state with optional message
 */
const LoadingIndicator: React.FC<LoadingIndicatorProps> = ({ 
  message = 'Executing code...' 
}) => {
  return (
    <div className="mt-4 text-blue-500 flex items-center gap-2">
      <div className="animate-spin h-4 w-4 border-2 border-blue-500 rounded-full border-t-transparent"></div>
      {message}
    </div>
  );
};

export default LoadingIndicator; 