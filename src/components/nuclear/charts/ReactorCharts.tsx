import React from 'react';

interface DistributionChartProps {
  mean: number;
  stdDev: number;
  type: 'normal';
  data: any[];
  className?: string;
}

export const DistributionChart: React.FC<DistributionChartProps> = ({
  mean,
  stdDev,
  type,
  data,
  className
}) => {
  // Placeholder for actual chart implementation
  return (
    <div className={className}>
      Distribution Chart (Mean: {mean}, StdDev: {stdDev})
    </div>
  );
}; 