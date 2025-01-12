import React from 'react';

interface StatusIndicatorProps {
  status: string;
  size?: 'sm' | 'md' | 'lg';
  showLabel?: boolean;
  className?: string;
}

// Moved outside component to be accessible by both components
const getStatusColor = (status: string) => {
  const statusMap: Record<string, { bg: string; text: string }> = {
    'ready': { bg: 'bg-green-500', text: 'text-green-800' },
    'running': { bg: 'bg-blue-500', text: 'text-blue-800' },
    'error': { bg: 'bg-red-500', text: 'text-red-800' },
    'warning': { bg: 'bg-yellow-500', text: 'text-yellow-800' },
    'waiting': { bg: 'bg-gray-500', text: 'text-gray-800' },
    'stopped': { bg: 'bg-red-500', text: 'text-red-800' },
    'completed': { bg: 'bg-green-500', text: 'text-green-800' },
    'validated': { bg: 'bg-green-500', text: 'text-green-800' },
  };

  return statusMap[status.toLowerCase()] || { bg: 'bg-gray-500', text: 'text-gray-800' };
};

const getDotSize = (size: 'sm' | 'md' | 'lg') => {
  const sizeMap = {
    'sm': 'w-2 h-2',
    'md': 'w-3 h-3',
    'lg': 'w-4 h-4'
  } as const;
  return sizeMap[size];
};

const StatusIndicator = ({ 
  status, 
  size = 'sm', 
  showLabel = true,
  className = '' 
}: StatusIndicatorProps) => {
  const { bg, text } = getStatusColor(status);
  const dotSize = getDotSize(size);

  return (
    <div className={`flex items-center gap-2 ${className}`}>
      <div className={`${dotSize} rounded-full ${bg}`} />
      {showLabel && (
        <span className={`text-sm capitalize ${text}`}>
          {status.toLowerCase()}
        </span>
      )}
    </div>
  );
};

// Optional Badge version with background
export const StatusBadge = ({ 
  status, 
  size = 'sm',
  className = '' 
}: StatusIndicatorProps) => {
  const { bg, text } = getStatusColor(status);
  const baseClasses = 'px-2.5 py-0.5 rounded-full inline-flex items-center gap-1.5';
  const sizeClasses = size === 'lg' ? 'text-sm' : 'text-xs';

  return (
    <span className={`${baseClasses} ${sizeClasses} ${bg.replace('bg-', 'bg-opacity-15')} ${text} ${className}`}>
      <div className={`w-1.5 h-1.5 rounded-full ${bg}`} />
      <span className="capitalize">{status.toLowerCase()}</span>
    </span>
  );
};

export default StatusIndicator;