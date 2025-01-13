import React from 'react';

interface ErrorDisplayProps {
  message: string;
}

/**
 * Displays error messages in a consistent format
 */
const ErrorDisplay: React.FC<ErrorDisplayProps> = ({ message }) => {
  return (
    <div className="p-4 bg-red-50 text-red-500 rounded-lg">
      {message}
    </div>
  );
};

export default ErrorDisplay; 