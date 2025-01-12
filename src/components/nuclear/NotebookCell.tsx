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
import ExternalTool from './ExternalTool';
import CellVisualization from './CellVisualization';
import VisualizationGrid, { createVisualizationCards } from './CellVisualization';
import FileRenderInfo, { RenderedFileInfo } from './FileRenderInfo';
import { CellData } from '@/backend/models/Cell';

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
  cell: CellData;
  isActive: boolean;
  onToggle(): void;
  onCellChange: (updatedCell: CellData) => void;
}

type DistributionType = 'normal' | 'uniform' | 'exponential';

interface PipeMeasurements {
  inner_diameter: number;
  outer_diameter: number;
  wall_thickness: number;
}

interface StepFileData {
  stlFile: File;
  pipeMeasurements: PipeMeasurements;
  originalFileName: string;
  timestamp: string;
}

const formatNumber = (value: number): string => {
  if (Math.abs(value) < 10) {
    return value.toFixed(2);
  }
  return new Intl.NumberFormat('en-US').format(Math.round(value));
};

const NotebookCell: React.FC<NotebookCellProps> = ({
  cell,
  isActive,
  onToggle,
  onCellChange
}) => {
  const fileInputRef = React.useRef<HTMLInputElement>(null);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [localCode, setLocalCode] = useState(cell.code || '');
  const [isExecuting, setIsExecuting] = useState(false);
  const [executionResult, setExecutionResult] = useState<any>(null);
  const [viewState, setViewState] = useState<'idle' | 'loading' | 'viewing' | 'error'>('idle');
  const [renderedFile, setRenderedFile] = useState<RenderedFileInfo | null>(null);
  const [stepFileData, setStepFileData] = useState<StepFileData | null>(null);

  useEffect(() => {
    if (cell.stlFile?.data) {
      // Convert base64 back to File object
      const byteString = atob(cell.stlFile.data.split(',')[1]);
      const ab = new ArrayBuffer(byteString.length);
      const ia = new Uint8Array(ab);
      for (let i = 0; i < byteString.length; i++) {
        ia[i] = byteString.charCodeAt(i);
      }
      const blob = new Blob([ab], { type: cell.stlFile.type });
      const file = new File([blob], cell.stlFile.name, { type: cell.stlFile.type });
      
      setStepFileData({
        stlFile: file,
        pipeMeasurements: cell.pipeMeasurements || null,
        originalFileName: cell.stlFile.name,
        timestamp: new Date().toISOString()
      });

      setRenderedFile({
        file: file,
        timestamp: new Date().toISOString(),
        success: true,
        originalFileName: cell.stlFile.name
      });
      
      setViewState('viewing');
    }
  }, [cell.stlFile]);

  const handleFileUpload = async (event: React.ChangeEvent<HTMLInputElement>) => {
    const file = event.target.files?.[0];
    if (!file) return;

    if (file.name.toLowerCase().endsWith('.stl')) {
      const newStepFileData = {
        stlFile: file,
        pipeMeasurements: null,
        originalFileName: file.name,
        timestamp: new Date().toISOString()
      };
      
      console.log('STL File Data:', newStepFileData);
      setStepFileData(newStepFileData);
      setViewState('viewing');
      
      const reader = new FileReader();
      reader.onload = () => {
        const base64data = reader.result as string;
        const updatedCell: CellData = {
          ...cell,
          stlFile: {
            name: file.name,
            data: base64data,
            type: 'model/stl'
          }
        };
        onCellChange(updatedCell);
      };
      reader.readAsDataURL(file);
    } 
    else if (file.name.toLowerCase().endsWith('.step') || file.name.toLowerCase().endsWith('.stp')) {
      setViewState('loading');
      try {
        const buffer = await file.arrayBuffer();
        const tempPath = await window.electronWindow.saveTempFile(buffer);
        const result = await window.stepConverter.convertStep(tempPath);
        
        if (result.success) {
          const stlBlob = new Blob([result.stl_data], { type: 'model/stl' });
          const newFileName = file.name.replace(/\.(step|stp)$/i, '.stl');
          const stlFile = new File([stlBlob], newFileName, { type: 'model/stl' });
          
          const newStepFileData = {
            stlFile,
            pipeMeasurements: result.pipe_measurements,
            originalFileName: file.name,
            timestamp: new Date().toISOString()
          };
          console.log('STEP File Data:', newStepFileData);
          setStepFileData(newStepFileData);
          
          setViewState('viewing');
          setRenderedFile({
            file: stlFile,
            timestamp: new Date().toISOString(),
            success: true,
            originalFileName: file.name
          });

          const reader = new FileReader();
          reader.onload = () => {
            const base64data = reader.result as string;
            const updatedCell: CellData = {
              ...cell,
              stlFile: {
                name: newFileName,
                data: base64data,
                type: 'model/stl'
              },
              pipeMeasurements: result.pipe_measurements
            };
            onCellChange(updatedCell);
          };
          reader.readAsDataURL(stlFile);
        } else {
          setErrorMessage(result.error || 'Failed to convert STEP file');
          setViewState('error');
        }
      } catch (error) {
        setErrorMessage(error instanceof Error ? error.message : 'Error converting file');
        setViewState('error');
      }
    } else {
      setErrorMessage('Please upload an STL or STEP file');
      setViewState('error');
    }
  };

  const handleCodeChange = (value: string | undefined) => {
    if (value !== undefined) {
      setLocalCode(value);
      // Immediately update the cell data and pass it up
      const updatedCell: CellData = { ...cell, code: value };
      onCellChange(updatedCell);
    }
  };

  const handleRunCell = useCallback(async () => {
    if (!localCode) {
      console.log("Cannot execute: missing cellCode");
      return;
    }
    
    try {
      console.log("Starting execution...");
      setIsExecuting(true);
      setErrorMessage(null);

      const result = await window.electronWindow.executePython(localCode);
      
      if (!result.success) {
        throw new Error(result.error);
      }

      setExecutionResult({
        stdout: result.stdout,
        result: result.result
      });
    } catch (error) {
      console.error("Execution failed:", error);
      setErrorMessage(error instanceof Error ? error.message : 'Execution failed');
    } finally {
      setIsExecuting(false);
    }
  }, [localCode]);

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
        <CardContent className="p-2 space-y-4 w-full">
          {/* Rendered File Info Component */}
          {renderedFile && (
            <FileRenderInfo 
              fileInfo={renderedFile}
              onClear={() => {
                setRenderedFile(null);
                setStepFileData(null);
                setViewState('idle');
                setErrorMessage(null);
                if (fileInputRef.current) {
                  fileInputRef.current.value = '';
                }
              }}
            />
          )}

          {/* External Tool */}
          {cell.type === 'external' && cell.tool && cell.input && (
            <ExternalTool
              tool={cell.tool}
              status={cell.status || 'pending'}
              input={cell.input}
            />
          )}
          
          {/* Visualization Section */}
          {stepFileData && (
            <div className="w-full">
              <VisualizationGrid 
                cards={createVisualizationCards(stepFileData.stlFile, stepFileData.pipeMeasurements)}
                cardsPerRow={5}
              />
            </div>
          )}

          {/* Error Message */}
          {errorMessage && (
            <div className="p-4 bg-red-50 text-red-500 rounded-lg">
              {errorMessage}
            </div>
          )}

          {/* Code Block */}
          {cell.code && (
            <CodeBlock 
              code={localCode}
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