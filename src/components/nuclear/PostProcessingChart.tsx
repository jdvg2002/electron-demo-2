import React, { useState, useEffect } from 'react';
import { AreaChart, Area, XAxis, YAxis, CartesianGrid, Legend, ResponsiveContainer } from 'recharts';
import { Card } from '@/components/ui/card';

interface DataPoint {
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

const PostProcessingChart: React.FC<{ data: DataPoint[] }> = ({ data }) => {
  const [chartData, setChartData] = useState<ChartPoint[]>([]);
  const [probabilityOfFailure, setProbabilityOfFailure] = useState<number>(0);

  useEffect(() => {
    try {
      const T = data.map(d => d.T);
      const sigma_f = data.map(d => d.sigma_f);
      
      // Find global min/max
      const allValues = [...T, ...sigma_f];
      const globalMin = Math.min(...allValues);
      const globalMax = Math.max(...allValues);
      
      // KDE calculation function
      const calculateKDE = (values: number[], min: number, max: number, points: number = 200): KDEPoint[] => {
        const x = Array.from({length: points}, (_, i) => 
          min + (i * (max - min) / (points-1))
        );
        
        const mean = values.reduce((a, b) => a + b) / values.length;
        const variance = values.reduce((a, b) => a + Math.pow(b - mean, 2), 0) / values.length;
        const h = Math.sqrt(variance) * Math.pow(values.length, -0.2) * 3.0;
        
        const density = x.map(xi => {
          const values_sum = values.map(d => 
            Math.exp(-0.5 * Math.pow((xi - d) / h, 2)) / (h * Math.sqrt(2 * Math.PI))
          );
          return values_sum.reduce((a, b) => a + b) / values.length;
        });
        
        // Normalize density
        const dx = x[1] - x[0];
        const integral = density.reduce((sum, y, i) => {
          if (i === 0 || i === density.length - 1) return sum + y * dx / 2;
          return sum + y * dx;
        }, 0);
        
        return x.map((xi, i) => ({
          x: xi,
          density: density[i] / integral
        }));
      };

      // Calculate KDEs
      const T_kde = calculateKDE(T, globalMin, globalMax);
      const sigma_f_kde = calculateKDE(sigma_f, globalMin, globalMax);
      
      // Merge data
      const mergedData = T_kde.map((point, index) => ({
        x: point.x,
        appliedStress: point.density,
        flowStress: sigma_f_kde[index].density
      }));
      
      // Calculate probability of failure
      const failureCount = data.filter(d => d.T > d.sigma_f).length;
      setProbabilityOfFailure(failureCount / data.length);

      setChartData(mergedData);
    } catch (error) {
      console.error("Error processing data:", error);
    }
  }, [data]);

  return (
    <Card className="w-full h-full flex flex-col bg-[#ffffff]">
      <div className="h-[400px]">
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
                if (index === 0 || index === chartData.length - 1) return '';
                const magnitude = Math.floor(Math.log10(Math.abs(value)));
                const scale = Math.pow(10, magnitude);
                return (Math.round(value / scale) * scale).toLocaleString();
              }}
            />
            <YAxis tick={false} />
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
        Probability of Failure: {(probabilityOfFailure * 100).toFixed(2)}%
      </div>
    </Card>
  );
};

export default PostProcessingChart; 