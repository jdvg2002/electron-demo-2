import React from 'react';
import { Card } from '@/components/ui/card';
import { AreaChart, Area, XAxis, YAxis, Legend, ResponsiveContainer } from 'recharts';

interface PostprocessingChartProps {
  chartData: Array<{
    x: number;
    appliedStress: number;
    flowStress: number;
  }>;
  probabilityOfFailure?: number;
}

export const PostprocessingChart: React.FC<PostprocessingChartProps> = ({
  chartData,
  probabilityOfFailure
}) => {
  return (
    <Card className="w-full h-[400px] flex flex-col bg-[#ffffff]">
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
            <XAxis dataKey="x" />
            <YAxis tick={false} />
            <Legend />
            <Area
              type="monotone"
              dataKey="appliedStress"
              stroke="#8884d8"
              fill="#8884d8"
              fillOpacity={0.3}
              name="Applied Stress"
            />
            <Area
              type="monotone"
              dataKey="flowStress"
              stroke="#82ca9d"
              fill="#82ca9d"
              fillOpacity={0.3}
              name="Flow Stress"
            />
          </AreaChart>
        </ResponsiveContainer>
      </div>
      {probabilityOfFailure !== undefined && (
        <div className="text-center p-1 -mt-6 text-lg font-bold italic">
          Probability of Failure: {(probabilityOfFailure * 100).toFixed(2)}%
        </div>
      )}
    </Card>
  );
}; 