import React, { useState, useEffect } from 'react';
import { AreaChart, Area, XAxis, YAxis, CartesianGrid, Tooltip, Legend, ResponsiveContainer } from 'recharts';
import FillerView from '@/components/ui/filler';
import LoadingView from '@/components/ui/loading';
import { Card } from '@/components/ui/card';

export interface DataPoint {
  T: number;
  sigma_f: number;
}

interface ChartPoint {
  x: number;
  appliedStress: number;
  flowStress: number;
}

interface KDEPoint {
  x: number;
  density: number;
}

const OutputCharts: React.FC<{ jsonData: DataPoint[] | DataPoint }> = ({ jsonData }) => {
  const [chartData, setChartData] = useState<ChartPoint[]>([]);
  const [hasInput, setHasInput] = useState(false);
  const [isLoading, setIsLoading] = useState(false);
  const [probabilityOfFailure, setProbabilityOfFailure] = useState<number>(0);

  useEffect(() => {
    // Check initial states
    const initialHasInput = localStorage.getItem('hasUserInput') === 'true';
    const initialIsLoading = localStorage.getItem('isLoading') === 'true';
    setHasInput(initialHasInput);
    setIsLoading(initialIsLoading);

    // Setup event listener for changes
    const handleStorageChange = () => {
      const newHasInput = localStorage.getItem('hasUserInput') === 'true';
      const newIsLoading = localStorage.getItem('isLoading') === 'true';
      setHasInput(newHasInput);
      setIsLoading(newIsLoading);
    };

    window.addEventListener('storage', handleStorageChange);

    // Poll for changes
    const interval = setInterval(() => {
      const currentHasInput = localStorage.getItem('hasUserInput') === 'true';
      const currentIsLoading = localStorage.getItem('isLoading') === 'true';
      if (currentHasInput !== hasInput || currentIsLoading !== isLoading) {
        setHasInput(currentHasInput);
        setIsLoading(currentIsLoading);
      }
    }, 100);

    return () => {
      window.removeEventListener('storage', handleStorageChange);
      clearInterval(interval);
    };
  }, [hasInput, isLoading]);

  useEffect(() => {
    setIsLoading(true);
    const dataArray = Array.isArray(jsonData) ? jsonData : [jsonData];

    try {
      const T = dataArray.map(d => d.T);
      const sigma_f = dataArray.map(d => d.sigma_f);
      
      // Find the global min and max across both datasets
      const allValues = [...T, ...sigma_f];
      const globalMin = Math.min(...allValues);
      const globalMax = Math.max(...allValues);
      
      // Modify calculateKDE to accept min/max parameters
      const calculateKDE = (data: number[], min: number, max: number, points: number = 200): KDEPoint[] => {
        // Use provided min/max instead of data bounds
        const x = Array.from({length: points}, (_, i) => 
          min + (i * (max - min) / (points-1))
        );
        
        // Rest of KDE calculation remains the same
        const mean = data.reduce((a, b) => a + b) / data.length;
        const variance = data.reduce((a, b) => a + Math.pow(b - mean, 2), 0) / data.length;
        const initialBandwidth = Math.sqrt(variance) * Math.pow(data.length, -0.2);
        const h = initialBandwidth * 3.0;
        
        const density = x.map(xi => {
          const values = data.map(d => 
            Math.exp(-0.5 * Math.pow((xi - d) / h, 2)) / (h * Math.sqrt(2 * Math.PI))
          );
          return values.reduce((a, b) => a + b) / data.length;
        });
        
        const dx = x[1] - x[0];
        const integral = density.reduce((sum, y, i) => {
          if (i === 0 || i === density.length - 1) return sum + y * dx / 2;
          return sum + y * dx;
        }, 0);
        
        const normalizedDensity = density.map(d => d / integral);
        
        return x.map((xi, i) => ({
          x: xi,
          density: normalizedDensity[i]
        }));
      };

      // Calculate KDE using the same x-axis range for both datasets
      const T_kde = calculateKDE(T, globalMin, globalMax);
      const sigma_f_kde = calculateKDE(sigma_f, globalMin, globalMax);
      
      const mergedData = T_kde.map((point, index) => ({
        x: point.x,
        appliedStress: point.density,
        flowStress: sigma_f_kde[index].density
      }));
      
      // Calculate probability of failure
      const failureCount = dataArray.filter(d => d.T > d.sigma_f).length;
      const pof = failureCount / dataArray.length;
      setProbabilityOfFailure(pof);

      setChartData(mergedData);
    } catch (error) {
      console.error("Error processing data:", error);
    }
    setIsLoading(false);
  }, [jsonData]);

  if (!hasInput && !isLoading) {
    return <FillerView message="" />;
  }

  if (isLoading) {
    return <LoadingView message="Loading one million iterations..." />;
  }

  if (chartData.length === 0) {
    return <LoadingView message="Loading one million iterations..." />;
  }

  return (
    <Card className="w-full h-full flex flex-col bg-[#eaf9ff]">
      <div className="flex-grow">
        <ResponsiveContainer>
          <AreaChart
            data={chartData}
            margin={{
              top: 10,
              right: 50,
              left: -20,
              bottom: 20,
            }}
          >
            <XAxis 
              dataKey="x" 
              label={{ 
                value: 'σₘ',
                position: 'right',
                offset: 0,
                dx: 10,
                dy: -20,
                style: { 
                  fontStyle: 'italic',
                  fontSize: '26px',
                  textAnchor: 'start',
                  dominantBaseline: 'middle'
                }
              }}
              tickFormatter={(value: number, index: number): string => {
                // Hide the first and last ticks
                if (index === 0 || value === chartData[chartData.length - 1].x) {
                  return '';
                }
                // Original formatting for other ticks
                const magnitude = Math.floor(Math.log10(Math.abs(value)));
                const scale = Math.pow(10, magnitude);
                return (Math.round(value / scale) * scale).toLocaleString();
              }}
            />
            <YAxis
              tick={false}
            />
            <Legend />
            <Area
              type="monotone"
              dataKey="appliedStress"
              stroke="#8884d8"
              fill="#8884d8"
              fillOpacity={0.3}
              name="Applied Stress"
              connectNulls={true}
              activeDot={false}
            />
            <Area
              type="monotone"
              dataKey="flowStress"
              stroke="#82ca9d"
              fill="#82ca9d"
              fillOpacity={0.3}
              name="Flow Stress"
              connectNulls={true}
              activeDot={false}
            />
          </AreaChart>
        </ResponsiveContainer>
      </div>
      <div className="text-center p-1 -mt-6 text-lg font-bold italic">
        Probability of Failure: {(probabilityOfFailure * 100)}%
      </div>
    </Card>
  );
};

export default OutputCharts;