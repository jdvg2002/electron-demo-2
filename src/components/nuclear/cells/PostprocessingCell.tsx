import React, { useState, useEffect } from 'react';
import { CellData } from '@/backend/Cell';
import CellCodeEditor from './shared/CellCodeEditor';
import ErrorDisplay from './shared/ErrorDisplay';
import LoadingIndicator from './shared/LoadingIndicator';
import { AreaChart, Area, XAxis, YAxis,Legend, ResponsiveContainer } from 'recharts';
import { Card } from '@/components/ui/card';
import FileOutput from './shared/FileOutput';

interface PostprocessingCellProps {
  cell: CellData;
  onCellChange: (updatedCell: CellData) => void;
  availableCells: CellData[];
}

/**
 * Handles post-processing operations and analysis of results
 */
const PostprocessingCell: React.FC<PostprocessingCellProps> = ({
  cell,
  onCellChange,
  availableCells
}) => {
  const [localCode, setLocalCode] = useState(cell.code || '');
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [showChart, setShowChart] = useState(false);
  const [chartData, setChartData] = useState<any[]>([]);
  const [probabilityOfFailure, setProbabilityOfFailure] = useState<number>(0);

  useEffect(() => {
    if (cell.output?.processedData) {
      setChartData(cell.output.processedData.chartData);
      setProbabilityOfFailure(cell.output.processedData.probabilityOfFailure);
      setShowChart(true);
    }
  }, [cell.output?.processedData]);

  const getExternalCellResults = () => {
    const externalCell = availableCells
      .find(c => c.type === 'external');
    
    if (!externalCell) {
      throw new Error('No external analysis cell found.');
    }
    
    if (externalCell.status === 'pending') {
      throw new Error('External analysis is pending. Please run the external analysis first.');
    }
    
    if (externalCell.status !== 'completed') {
      throw new Error(`External analysis is in state: ${externalCell.status}. Please run the external analysis first.`);
    }
    
    if (!externalCell.output) {
      throw new Error('External analysis completed but no results available. Please try running the analysis again.');
    }
    
    return externalCell.output;
  };

  const hasExternalResults = () => {
    try {
      const results = getExternalCellResults();
      return !!results;
    } catch (e) {
      // Update the warning message to be more specific
      const warningMessage = e instanceof Error ? e.message : 'External analysis results not available';
      return (
        <div className="text-amber-600 bg-amber-50 p-4 rounded-md">
          {warningMessage}
        </div>
      );
    }
  };

  const handleCodeExecution = async () => {
    try {
      setIsExecuting(true);
      setErrorMessage(null);

      const externalOutput = getExternalCellResults();
      
      // Ensure we're accessing the results array correctly
      const dataArray = Array.isArray(externalOutput) ? externalOutput :
                       Array.isArray(externalOutput.results) ? externalOutput.results :
                       Array.isArray(externalOutput.data) ? externalOutput.data : null;
      
      if (!dataArray) {
        throw new Error('External analysis results are not in the expected format. Expected an array of data points.');
      }
      
      // Extract T and sigma_f values
      const T = dataArray.map((d: any) => d.T);
      const sigma_f = dataArray.map((d: any) => d.sigma_f);
      
      // Find global min and max for consistent x-axis
      const allValues = [...T, ...sigma_f];
      const globalMin = Math.min(...allValues);
      const globalMax = Math.max(...allValues);
      
      // Calculate KDE for both distributions
      const calculateKDE = (data: number[], min: number, max: number, points: number = 200) => {
        const x = Array.from({length: points}, (_, i) => 
          min + (i * (max - min) / (points-1))
        );
        
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
        
        return x.map((xi, i) => ({
          x: xi,
          density: density[i] / integral
        }));
      };

      // Calculate KDE for both distributions
      const T_kde = calculateKDE(T, globalMin, globalMax);
      const sigma_f_kde = calculateKDE(sigma_f, globalMin, globalMax);
      
      // Merge the data for the chart
      const mergedData = T_kde.map((point, index) => ({
        x: point.x,
        appliedStress: point.density,
        flowStress: sigma_f_kde[index].density
      }));
      
      // Calculate probability of failure
      const failureCount = dataArray.filter((d: any) => d.T > d.sigma_f).length;
      const pof = failureCount / dataArray.length;
      
      // Update cell with structured output using new format
      const updatedCell = {
        ...cell,
        status: 'completed',
        output: {
          processedData: {
            chartData: mergedData,
            probabilityOfFailure: pof
          },
          metadata: {
            analysisTimestamp: new Date().toISOString(),
            sourceAnalysis: 'kde_analysis'
          }
        }
      };

      onCellChange(updatedCell);
      
      // Update local state for display
      setChartData(mergedData);
      setProbabilityOfFailure(pof);
      setShowChart(true);

    } catch (error) {
      console.error('Execution error:', error);
      setErrorMessage(error instanceof Error ? error.message : 'Execution failed');
      const updatedCell = {
        ...cell,
        status: 'error'
      };
      onCellChange(updatedCell);
    } finally {
      setIsExecuting(false);
    }
  };

  const renderExternalResults = () => {
    try {
      const externalCell = availableCells
        .find(c => c.type === 'external' && c.status === 'completed');
      
      if (!externalCell?.output) {
        return null;
      }

      const fileData = {
        name: 'analysis_results.json',
        size: `${JSON.stringify(externalCell.output).length} bytes`,
        format: 'JSON',
        timestamp: new Date().toLocaleString(),
        data: externalCell.output
      };

      return (
        <div className="mb-4">
          <div className="text-sm font-medium text-gray-500 mb-2">
            External Analysis Results
          </div>
          <FileOutput file={fileData} type="input" />
        </div>
      );
    } catch (error) {
      console.warn('Error rendering external results:', error);
      return null;
    }
  };

  const renderAnalysisOutput = () => {
    if (!cell.output?.processedData) return null;

    const fileData = {
      name: 'analysis_results.json',
      size: `${JSON.stringify(cell.output.processedData).length} bytes`,
      format: 'JSON',
      timestamp: new Date().toLocaleString(),
      data: {
        chartData: cell.output.processedData.chartData,
        probabilityOfFailure: cell.output.processedData.probabilityOfFailure,
        metadata: cell.output.metadata
      }
    };

    return (
      <div className="space-y-4">
        <FileOutput file={fileData} type="output" />
      </div>
    );
  };

  return (
    <div className="space-y-4">
      {typeof hasExternalResults() === 'boolean' ? null : hasExternalResults()}

      {/* Input File Output */}
      {renderExternalResults()}

      {errorMessage && <ErrorDisplay message={errorMessage} />}

      {/* Code Editor */}
      <CellCodeEditor
        code={localCode}
        onChange={setLocalCode}
      />

      <button
        onClick={handleCodeExecution}
        disabled={isExecuting || !hasExternalResults()}
        className={`px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600 ${
          isExecuting || !hasExternalResults() ? 'opacity-50 cursor-not-allowed' : ''
        }`}
      >
        Run Analysis
      </button>

      {isExecuting && <LoadingIndicator />}

      {/* Chart */}
      {showChart && (
        <Card className="w-full h-[400px] flex flex-col bg-[#eaf9ff]">
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
                  tickFormatter={(value) => {
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
      )}

      {/* Output File Output */}
      {renderAnalysisOutput()}
    </div>
  );
};

export default PostprocessingCell;