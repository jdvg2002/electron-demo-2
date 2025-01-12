import React, { useState, useCallback, useEffect } from 'react';
import { FileText, Play, ChevronDown, BarChart2, Box, Upload } from 'lucide-react';
import { Card, CardHeader, CardTitle, CardContent } from '@/components/ui/card';
import { 
  DistributionChart 
} from '../charts/ReactorCharts';
import CodeBlock from './CodeBlock';
import FileOutput from './FileOutput';
import AnalysisSummary from './AnalysisSummary';
import { temperatureData, fluxData, safetyMarginData, coolantData } from '../../data/nuclearData';
import { StlViewer } from 'react-stl-viewer';
import PostProcessingChart from './PostProcessingChart';
import resultsData from '@/data/results.json';
import { loadPyodide } from 'pyodide';
import ExternalTool from './ExternalTool';

interface CellFile {
  name: string;
  size: string;
  format: string;
  timestamp: string;
}

interface CellInput {
  file: string;
  status: string;
  checksum: string;
}

interface CellOutput {
  file?: CellFile;
  summary?: {
    status: string;
    key_metrics: {
      label: string;
      value: string;
      status: 'safe' | 'warning' | 'danger';
    }[];
  };
}

interface NotebookCellProps {
  cell: {
    id: number;
    type: 'preprocessing' | 'external' | 'postprocessing';
    title: string;
    code?: string;
    status?: string;
    tool?: string;
    input?: CellInput;
    output?: CellOutput;
    onExecute?: (code: string) => Promise<any>;
  };
  isActive: boolean;
  onToggle: () => void;
}

type DistributionType = 'normal' | 'uniform' | 'exponential';

interface PipeMeasurements {
  inner_diameter: number;
  outer_diameter: number;
  wall_thickness: number;
}

const formatNumber = (value: number): string => {
  if (Math.abs(value) < 10) {
    return value.toFixed(2);
  }
  return new Intl.NumberFormat('en-US').format(Math.round(value));
};

const NotebookCell = ({ cell, isActive, onToggle }: NotebookCellProps) => {
  const fileInputRef = React.useRef<HTMLInputElement>(null);
  const [stlFile, setStlFile] = useState<File | null>(null);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [cellCode, setCellCode] = useState(cell.code || '');
  const [isExecuting, setIsExecuting] = useState(false);
  const [executionResult, setExecutionResult] = useState<any>(null);
  const [pyodide, setPyodide] = useState<any>(null);
  const [viewState, setViewState] = useState<'idle' | 'loading' | 'viewing' | 'error'>('idle');
  const [pipeMeasurements, setPipeMeasurements] = useState<PipeMeasurements | null>(null);

  useEffect(() => {
    const initPyodide = async () => {
      console.log("Starting Pyodide initialization...");
      try {
        const pyodideInstance = await loadPyodide({
          indexURL: "https://cdn.jsdelivr.net/pyodide/v0.27.0/full/"
        });
        console.log("Pyodide initialized successfully!");
        setPyodide(pyodideInstance);
      } catch (error) {
        console.error("Failed to initialize Pyodide:", error);
      }
    };
    initPyodide();
  }, []);

  const handleFileUpload = async (event: React.ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files?.[0];
    if (!file) return;

    if (file.name.toLowerCase().endsWith('.stl')) {
      setStlFile(file);
      setViewState('viewing');
    } 
    else if (file.name.toLowerCase().endsWith('.step') || file.name.toLowerCase().endsWith('.stp')) {
      setViewState('loading');
      try {
        const formData = new FormData();
        formData.append('file', file);
        
        const response = await fetch('http://localhost:5001/convert', {
          method: 'POST',
          body: formData,
        });
        
        const data = await response.json();
        if (data.success) {
          const stlBlob = new Blob([data.stl_data], { type: 'model/stl' });
          const stlFile = new File([stlBlob], 'converted.stl', { type: 'model/stl' });
          setStlFile(stlFile);
          console.log("Pipe measurements:", data.pipe_measurements);
          setPipeMeasurements(data.pipe_measurements);
          setViewState('viewing');
        } else {
          setErrorMessage(data.error || 'Failed to convert STEP file');
          setViewState('error');
        }
      } catch (error) {
        setErrorMessage('Error connecting to conversion server');
        setViewState('error');
        console.error(error);
      }
    } else {
      setErrorMessage('Please upload an STL or STEP file');
      setViewState('error');
    }
  };

  const handleCodeChange = (value: string | undefined) => {
    if (value !== undefined) {
      setCellCode(value);
      // You might want to add logic here to save the code
      // or sync it with your application state
    }
  };

  const handleRunCell = useCallback(async () => {
    if (!cellCode) {
      console.log("Cannot execute: missing cellCode");
      return;
    }
    
    if (!pyodide) {
      setErrorMessage('Python runtime not initialized');
      return;
    }
    
    try {
      console.log("Starting execution...");
      setIsExecuting(true);

      // Create a new stdout capture
      const stdout: string[] = [];
      pyodide.setStdout({
        batched: (text: string[]) => {
          stdout.push(...text);
        },
      });

      // Run the code
      const result = await pyodide.runPythonAsync(cellCode);
      console.log("Execution completed:", { stdout, result });

      setExecutionResult({
        stdout: stdout.join('\n'),
        result: result
      });
    } catch (error) {
      console.error("Execution failed:", error);
      setErrorMessage(error instanceof Error ? error.message : 'Execution failed');
    } finally {
      setIsExecuting(false);
    }
  }, [cellCode, pyodide]);

  const renderCellIcon = () => {
    switch (cell.type) {
      case 'preprocessing':
        return <Box className="text-blue-500" />;
      case 'external':
        return <Play className="text-green-500" />;
      case 'postprocessing':
        return <BarChart2 className="text-purple-500" />;
      default:
        return null;
    }
  };

  const STLViewer = () => (
    stlFile && (
      <div className="space-y-4">
        <div className="w-full h-[400px] bg-[#ffffff] rounded-lg overflow-hidden">
          <StlViewer
            style={{ width: '100%', height: '100%' }}
            orbitControls
            shadows
            url={URL.createObjectURL(stlFile)}
            modelProps={{
              scale: 1.25,
              rotationX: 0,
              rotationY: 0,
              rotationZ: 0
            }}
          />
        </div>
        
        {/* Pipe measurements */}
        {pipeMeasurements && (
          <div className="p-4 bg-gray-50 rounded-lg">
            <h3 className="font-medium mb-2">Pipe Measurements</h3>
            <div className="grid grid-cols-3 gap-4">
              <div>
                <p className="text-sm text-gray-500">Inner Diameter</p>
                <p className="font-medium">{pipeMeasurements.inner_diameter} mm</p>
              </div>
              <div>
                <p className="text-sm text-gray-500">Outer Diameter</p>
                <p className="font-medium">{pipeMeasurements.outer_diameter} mm</p>
              </div>
              <div>
                <p className="text-sm text-gray-500">Wall Thickness</p>
                <p className="font-medium">{pipeMeasurements.wall_thickness} mm</p>
              </div>
            </div>
          </div>
        )}

        {/* Updated Preprocessing Charts */}
        {cell.type === 'preprocessing' && pipeMeasurements && (
          <div className="w-full grid grid-cols-3 gap-4">
            {Object.entries(pipeMeasurements).map(([key, value]: [string, number], index: number) => {
              const formattedTitle = key
                .split('_')
                .map((word: string) => word.charAt(0).toUpperCase() + word.slice(1))
                .join(' ');
              
              // Define standard deviation as a percentage based on measurement type
              const stdDevPercentage = key.includes('thickness') ? 0.1 : 0.05; // 10% for thickness, 5% for diameters
              
              return (
                <Card key={index} className="flex flex-col items-center p-2 bg-[#ffffff]">
                  <div className="text-center mb-2 p-1 rounded w-full">
                    <h2 className="text-sm font-semibold">
                      {formattedTitle}
                    </h2>
                    <div className="text-xs">
                      μ={formatNumber(value)}
                      <br />
                      σ={formatNumber(value * stdDevPercentage)}
                    </div>
                  </div>
                  <div className="h-[200px] w-full">
                    <DistributionChart 
                      mean={value}
                      stdDev={value * stdDevPercentage}
                      type="normal"
                      data={[]}
                      height={200}
                      className="mt-2"
                    />
                  </div>
                </Card>
              );
            })}
          </div>
        )}

        {/* Postprocessing Charts */}
        {cell.type === 'postprocessing' && (
          <div className="mt-4">
            <PostProcessingChart data={resultsData} />
          </div>
        )}
      </div>
    )
  );

  return (
    <Card className="mb-4 border-l-4 border-l-blue-500 w-full">
      <CardHeader className="flex flex-row items-center justify-between p-4">
        <div className="flex items-center gap-2">
          {renderCellIcon()}
          <CardTitle className="text-lg font-medium">{cell.title}</CardTitle>
        </div>
        <div className="flex items-center gap-2">
          <input
            type="file"
            ref={fileInputRef}
            onChange={handleFileUpload}
            className="hidden"
            accept=".stl,.step,.stp"
          />
          <button 
            className="p-2 hover:bg-gray-100 rounded transition-colors"
            onClick={() => fileInputRef.current?.click()}
            aria-label="Upload STL file"
          >
            <Upload className="w-4 h-4" />
          </button>
          <button 
            className={`p-2 hover:bg-gray-100 rounded transition-colors ${
              isExecuting ? 'opacity-50 cursor-not-allowed' : ''
            }`}
            onClick={handleRunCell}
            disabled={isExecuting}
            aria-label="Run cell"
          >
            <Play className={`w-4 h-4 ${isExecuting ? 'animate-pulse' : ''}`} />
          </button>
          <button 
            className="p-2 hover:bg-gray-100 rounded transition-colors"
            onClick={onToggle}
            aria-label={isActive ? 'Collapse cell' : 'Expand cell'}
          >
            <ChevronDown 
              className={`w-4 h-4 transform transition-transform duration-200 ${
                isActive ? 'rotate-180' : ''
              }`} 
            />
          </button>
        </div>
      </CardHeader>
      
      {isActive && (
        <CardContent className="p-4 space-y-4">
          {/* External Tool */}
          {cell.type === 'external' && cell.tool && cell.input && (
            <ExternalTool
              tool={cell.tool}
              status={cell.status || 'pending'}
              input={cell.input}
            />
          )}
          
          {/* STL viewer section with measurements and charts */}
          <STLViewer />
          {errorMessage && (
            <div className="p-4 bg-red-50 text-red-500 rounded-lg">
              {errorMessage}
            </div>
          )}

          {/* Code Block */}
          {cell.code && (
            <CodeBlock 
              code={cellCode}
              language="python"
              showCopy={true}
              onChange={handleCodeChange}
              readOnly={false}
            />
          )}
          
          {/* Output File */}
          {cell.output?.file && (
            <FileOutput
              file={cell.output.file}
              onDownload={() => {/* Handle download */}}
            />
          )}
          
          {/* Analysis Summary */}
          {cell.output?.summary && (
            <AnalysisSummary
              status={cell.output.summary.status}
              metrics={cell.output.summary.key_metrics}
            />
          )}

          {/* Execution Output and Loading State */}
          {executionResult && (
            <div className="mt-4 p-4 bg-gray-50 rounded-lg border border-gray-200">
              <h3 className="font-medium text-sm text-gray-700 mb-2">Output:</h3>
              {executionResult.stdout && (
                <pre className="bg-white p-3 rounded-md text-sm overflow-x-auto mb-2 text-gray-600">
                  {executionResult.stdout}
                </pre>
              )}
              {executionResult.result !== undefined && executionResult.result !== null && (
                <>
                  <h4 className="font-medium text-sm text-gray-700 mb-1">Return Value:</h4>
                  <pre className="bg-white p-3 rounded-md text-sm overflow-x-auto text-gray-800">
                    {typeof executionResult.result === 'object' 
                      ? JSON.stringify(executionResult.result, null, 2)
                      : String(executionResult.result)}
                  </pre>
                </>
              )}
            </div>
          )}

          {/* Show a loading state while executing */}
          {isExecuting && (
            <div className="mt-4 text-blue-500">
              Executing code...
            </div>
          )}
        </CardContent>
      )}
    </Card>
  );
};

export default NotebookCell;