import React from 'react';
import {
  LineChart,
  Line,
  BarChart,
  Bar,
  AreaChart,
  Area,
  XAxis,
  YAxis,
  CartesianGrid,
  Tooltip,
  Legend,
  ResponsiveContainer
} from 'recharts';

interface ChartProps {
  data: any[];
  height?: number;
  className?: string;
}

interface DataPoint {
  x: number;
  y: number;
}

type DistributionType = 'normal' | 'uniform' | 'exponential';

interface DistributionChartProps extends ChartProps {
  mean: number;
  stdDev: number;
  type: DistributionType;
  onChartClick?: () => void;
}

// Common chart configuration
const chartConfig = {
  colors: {
    temperature: '#ff6b6b',
    limit: '#adb5bd',
    flux: '#4dabf7',
    margin: '#51cf66',
    coolant: {
      flow: '#74c0fc',
      flowStroke: '#4dabf7',
      temp: '#ff6b6b'
    }
  },
  defaultHeight: 200,
};

// Common components for all charts
const CommonChartElements = () => (
  <>
    <CartesianGrid strokeDasharray="3 3" />
    <Tooltip />
    <Legend />
  </>
);

export const TemperatureChart: React.FC<ChartProps> = ({ 
  data, 
  height = chartConfig.defaultHeight,
  className = ''
}) => (
  <div className={`w-full ${className}`}>
    <ResponsiveContainer width="100%" height={height}>
      <LineChart data={data}>
        <CommonChartElements />
        <XAxis 
          dataKey="position" 
          label={{ value: 'Position (cm)', position: 'bottom' }} 
        />
        <YAxis 
          label={{ 
            value: 'Temperature (K)', 
            angle: -90, 
            position: 'left' 
          }} 
        />
        <Line 
          type="monotone" 
          dataKey="temp" 
          stroke={chartConfig.colors.temperature} 
          name="Temperature" 
        />
        <Line 
          type="monotone" 
          dataKey="limit" 
          stroke={chartConfig.colors.limit} 
          strokeDasharray="5 5" 
          name="Limit" 
        />
      </LineChart>
    </ResponsiveContainer>
  </div>
);

export const FluxChart: React.FC<ChartProps> = ({ 
  data, 
  height = chartConfig.defaultHeight,
  className = ''
}) => (
  <div className={`w-full ${className}`}>
    <ResponsiveContainer width="100%" height={height}>
      <BarChart data={data}>
        <CommonChartElements />
        <XAxis dataKey="position" />
        <YAxis 
          label={{ 
            value: 'Flux (1E15 n/cm²·s)', 
            angle: -90, 
            position: 'left' 
          }} 
        />
        <Bar 
          dataKey="flux" 
          fill={chartConfig.colors.flux} 
          name="Neutron Flux" 
        />
      </BarChart>
    </ResponsiveContainer>
  </div>
);

export const SafetyMarginChart: React.FC<ChartProps> = ({ 
  data, 
  height = chartConfig.defaultHeight,
  className = ''
}) => (
  <div className={`w-full ${className}`}>
    <ResponsiveContainer width="100%" height={height}>
      <BarChart data={data}>
        <CommonChartElements />
        <XAxis dataKey="region" />
        <YAxis 
          label={{ 
            value: 'Margin to Limit (%)', 
            angle: -90, 
            position: 'left' 
          }} 
        />
        <Bar 
          dataKey="margin" 
          fill={chartConfig.colors.margin} 
          name="Safety Margin" 
        />
        <Bar 
          dataKey="limit" 
          fill={chartConfig.colors.limit} 
          stackId="a" 
          name="Remaining Margin" 
        />
      </BarChart>
    </ResponsiveContainer>
  </div>
);

export const CoolantChart: React.FC<ChartProps> = ({ 
  data, 
  height = chartConfig.defaultHeight,
  className = ''
}) => (
  <div className={`w-full ${className}`}>
    <ResponsiveContainer width="100%" height={height}>
      <AreaChart data={data}>
        <CommonChartElements />
        <XAxis 
          dataKey="time" 
          label={{ value: 'Time (s)', position: 'bottom' }} 
        />
        <YAxis 
          yAxisId="left" 
          label={{ 
            value: 'Flow Rate (kg/s)', 
            angle: -90, 
            position: 'left' 
          }} 
        />
        <YAxis 
          yAxisId="right" 
          orientation="right" 
          label={{ 
            value: 'Temperature (K)', 
            angle: 90, 
            position: 'right' 
          }} 
        />
        <Area 
          yAxisId="left" 
          type="monotone" 
          dataKey="flow" 
          fill={chartConfig.colors.coolant.flow} 
          stroke={chartConfig.colors.coolant.flowStroke} 
          name="Coolant Flow" 
        />
        <Line 
          yAxisId="right" 
          type="monotone" 
          dataKey="temp" 
          stroke={chartConfig.colors.coolant.temp} 
          name="Coolant Temp" 
        />
      </AreaChart>
    </ResponsiveContainer>
  </div>
);

const generateNormalDistribution = (mean: number, stdDev: number, points: number = 100): DataPoint[] => {
  const data: DataPoint[] = [];
  const range: number = 4 * stdDev;
  const step: number = range / points;
  
  for (let x: number = mean - range/2; x <= mean + range/2; x += step) {
    const y: number = (1 / (stdDev * Math.sqrt(2 * Math.PI))) * 
             Math.exp(-Math.pow(x - mean, 2) / (2 * Math.pow(stdDev, 2)));
    data.push({ x, y });
  }
  return data;
};

export const DistributionChart: React.FC<DistributionChartProps> = ({
  mean,
  stdDev,
  type,
  height = chartConfig.defaultHeight,
  className = '',
  onChartClick
}) => {
  // Generate a new key when mean or stdDev changes to force complete re-render
  const chartKey = React.useMemo(() => `dist-${mean}-${stdDev}`, [mean, stdDev]);
  const data = generateNormalDistribution(mean, stdDev);
  
  return (
    <div 
      className={`w-full h-full ${className}`}
      onClick={onChartClick}
      style={{ cursor: onChartClick ? 'pointer' : 'default' }}
    >
      <ResponsiveContainer width="100%" height="100%">
        <LineChart 
          key={chartKey}  // Add key here to force re-render
          data={data}
          margin={{ top: 0, right: 0, bottom: 0, left: 0 }}
        >
          <XAxis 
            dataKey="x" 
            tick={false}
            domain={['dataMin', 'dataMax']}
            height={20}
          />
          <YAxis 
            tick={false} 
            domain={['auto', 'auto']}
            width={20}
          />
          <Line 
            type="monotone" 
            dataKey="y" 
            stroke={chartConfig.colors.flux} 
            dot={false}
            strokeWidth={2}
            // Add animation properties
            isAnimationActive={true}
            animationDuration={500}
            animationBegin={0}
          />
        </LineChart>
      </ResponsiveContainer>
    </div>
  );
};

// Utility component for chart containers
export const ChartContainer: React.FC<{
  title: string;
  description?: string;
  children: React.ReactNode;
  className?: string;
}> = ({ title, description, children, className = '' }) => (
  <div className={`bg-white rounded-md p-4 flex flex-col items-center ${className}`}>
    <h3 className="font-medium mb-4">{title}</h3>
    {children}
    {description && (
      <span className="text-gray-500 text-center mt-4">{description}</span>
    )}
  </div>
);

// Export a default object with all charts for convenience
const ReactorCharts = {
  TemperatureChart,
  FluxChart,
  SafetyMarginChart,
  CoolantChart,
  DistributionChart,
  ChartContainer,
};

export default ReactorCharts;