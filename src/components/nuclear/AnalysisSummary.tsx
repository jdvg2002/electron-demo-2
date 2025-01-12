import React from 'react';

interface Metric {
  label: string;
  value: string;
  status: 'safe' | 'warning' | 'danger';
}

interface AnalysisSummaryProps {
  status: string;
  metrics: Metric[];
  className?: string;
}

const StatusBadge = ({ status }: { status: string }) => (
  <span className={`px-3 py-1 rounded-full text-sm font-medium 
    ${status === 'PASS' ? 'bg-green-100 text-green-800' : 'bg-red-100 text-red-800'}`}>
    {status}
  </span>
);

const MetricCard = ({ metric }: { metric: Metric }) => {
  const getStatusColor = (status: Metric['status']) => {
    switch (status) {
      case 'safe':
        return 'bg-green-500';
      case 'warning':
        return 'bg-yellow-500';
      case 'danger':
        return 'bg-red-500';
      default:
        return 'bg-gray-500';
    }
  };

  const getProgressWidth = (status: Metric['status']) => {
    switch (status) {
      case 'safe':
        return '80%';
      case 'warning':
        return '60%';
      case 'danger':
        return '30%';
      default:
        return '0%';
    }
  };

  return (
    <div className="bg-white p-3 rounded-lg border">
      <p className="text-sm text-gray-600 mb-2">{metric.label}</p>
      <div className="flex items-center justify-between">
        <p className="font-medium">{metric.value}</p>
        <div className="flex items-center gap-2">
          <div className="w-24 h-2 bg-gray-200 rounded-full overflow-hidden">
            <div 
              className={`h-full rounded-full ${getStatusColor(metric.status)}`}
              style={{ width: getProgressWidth(metric.status) }}
            />
          </div>
          <span className={`h-2 w-2 rounded-full ${getStatusColor(metric.status)}`} />
        </div>
      </div>
    </div>
  );
};

const AnalysisSummary = ({ status, metrics, className = '' }: AnalysisSummaryProps) => {
  return (
    <div className={`bg-gray-50 rounded-lg p-4 border ${className}`}>
      <div className="flex items-center justify-between mb-4">
        <h3 className="text-lg font-medium">Analysis Summary</h3>
        <StatusBadge status={status} />
      </div>
      <div className="grid grid-cols-1 md:grid-cols-2 gap-4">
        {metrics.map((metric, index) => (
          <MetricCard key={index} metric={metric} />
        ))}
      </div>
    </div>
  );
};

export default AnalysisSummary;