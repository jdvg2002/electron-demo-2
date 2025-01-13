import React, { useState, useCallback, useEffect } from 'react';
import { FileText, Play, ChevronDown, BarChart2, Box, Upload } from 'lucide-react';
import { Card, CardHeader, CardTitle, CardContent } from '@/components/ui/card';
import CodeBlock from './CodeBlock';
import FileOutput from './FileOutput';
import AnalysisSummary from './AnalysisSummary';
import ExternalTool from './ExternalTool';
import VisualizationGrid, { createVisualizationCards } from './CellVisualization';
import FileRenderInfo, { RenderedFileInfo } from './FileRenderInfo';
import { CellData } from '@/backend/models/Cell';
import FileUploadHandler from './FileUploadHandler';
import { FileModuleManager } from '@/backend/manager/FileModuleManager';

interface NotebookCellProps {
  cell: CellData;
  isActive: boolean;
  onToggle(): void;
  onCellChange: (updatedCell: CellData) => void;
}

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

const NotebookCell: React.FC<NotebookCellProps> = ({
  cell,
  isActive,
  onToggle,
  onCellChange
}) => {
  const fileModuleManager = FileModuleManager.getInstance();
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [localCode, setLocalCode] = useState(cell.code || '');
  const [isExecuting, setIsExecuting] = useState(false);
  const [executionResult, setExecutionResult] = useState<any>(null);
  const [viewState, setViewState] = useState<'idle' | 'loading' | 'viewing' | 'error'>('idle');
  const [renderedFile, setRenderedFile] = useState<RenderedFileInfo | null>(null);
  const [stepFileData, setStepFileData] = useState<StepFileData | null>(null);

  const { fileInputRef, handleFileUpload } = FileUploadHandler({
    cell,
    onCellChange,
    onStepFileDataChange: async (newStepData) => {
      setStepFileData(newStepData);
      
      // Create a new global file entry when uploading directly to cell
      if (cell.type === 'preprocessing') {
        const globalFileId = await fileModuleManager.addFileFromUpload(
          newStepData.stlFile,
          newStepData.pipeMeasurements,
          newStepData.originalFileName
        );
      }
    },
    onRenderedFileChange: setRenderedFile,
    onViewStateChange: setViewState,
    onErrorChange: setErrorMessage
  });

  // Load global file data on mount and when cell changes
  useEffect(() => {
    if (cell.type === 'preprocessing' && cell.globalFileId) {
      const globalFile = fileModuleManager.getFileById(cell.globalFileId);
      
      if (globalFile) {
        // Convert base64 back to File object
        const byteString = atob(globalFile.stlFile.data.split(',')[1]);
        const ab = new ArrayBuffer(byteString.length);
        const ia = new Uint8Array(ab);
        for (let i = 0; i < byteString.length; i++) {
          ia[i] = byteString.charCodeAt(i);
        }
        const blob = new Blob([ab], { type: globalFile.stlFile.type });
        const file = new File([blob], globalFile.stlFile.name, { type: globalFile.stlFile.type });
        
        setStepFileData({
          stlFile: file,
          pipeMeasurements: globalFile.pipeMeasurements,
          originalFileName: globalFile.originalFileName,
          timestamp: globalFile.timestamp
        });

        setRenderedFile({
          name: globalFile.originalFileName,
          size: `${(globalFile.stlFile.data.length * 0.75) / 1024} KB`,
          format: globalFile.stlFile.type,
          timestamp: globalFile.timestamp
        });
        
        setViewState('viewing');
      }
    }
  }, [cell]);

  // Listen for new global file updates
  useEffect(() => {
    const unsubscribe = fileModuleManager.addListener(() => {
      if (cell.type === 'preprocessing' && !cell.globalFileId) {
        const unprocessedFiles = fileModuleManager.getUnprocessedFiles();
        
        if (unprocessedFiles.length > 0 && !stepFileData) {
          const firstFile = unprocessedFiles[0];
          
          // Convert base64 back to File object
          const byteString = atob(firstFile.stlFile.data.split(',')[1]);
          const ab = new ArrayBuffer(byteString.length);
          const ia = new Uint8Array(ab);
          for (let i = 0; i < byteString.length; i++) {
            ia[i] = byteString.charCodeAt(i);
          }
          const blob = new Blob([ab], { type: firstFile.stlFile.type });
          const file = new File([blob], firstFile.stlFile.name, { type: firstFile.stlFile.type });
          
          setStepFileData({
            stlFile: file,
            pipeMeasurements: firstFile.pipeMeasurements,
            originalFileName: firstFile.originalFileName,
            timestamp: firstFile.timestamp
          });

          setRenderedFile({
            name: firstFile.originalFileName,
            size: `${(firstFile.stlFile.data.length * 0.75) / 1024} KB`,
            format: firstFile.stlFile.type,
            timestamp: firstFile.timestamp
          });
          
          setViewState('viewing');

          // Update the cell data
          const updatedCell: CellData = {
            ...cell,
            stlFile: firstFile.stlFile,
            pipeMeasurements: firstFile.pipeMeasurements,
            globalFileId: firstFile.id,
            timestamp: firstFile.timestamp
          };
          onCellChange(updatedCell);

          // Mark the file as processed
          fileModuleManager.markFileAsProcessed(firstFile.id);
        }
      }
    });

    return () => unsubscribe();
  }, [cell, stepFileData, onCellChange]);

  const handleCodeChange = (value: string | undefined) => {
    if (value !== undefined) {
      setLocalCode(value);
      // Immediately update the cell data and pass it up
      const updatedCell: CellData = { ...cell, code: value };
      onCellChange(updatedCell);
    }
  };

  const handleRunCell = useCallback(async () => {
    if (cell.type === 'external') {
      try {
        setIsExecuting(true);
        setErrorMessage(null);

        // First get the project root path
        const projectRoot = await window.electronWindow.getProjectRoot();

        // Execute the fatigue crack analysis script
        const result = await window.electronWindow.executePython(`
import sys
import os

# Get the absolute path to the Python script
script_path = os.path.join('${projectRoot}', 'server', 'fatigue_crack_init.py')
print(f"Executing script at: {script_path}")

# Add the server directory to Python path
sys.path.append(os.path.dirname(script_path))

# Run the main function directly
from fatigue_crack_init import main
main()
`);

        if (!result.success) {
          throw new Error(result.error || 'Execution failed');
        }

        // Parse the result
        const parsedResult = {
          success: true,
          results: result.stdout
        };

        // Update cell with results
        const updatedCell = {
          ...cell,
          status: 'completed',
          executionResult: parsedResult
        };
        onCellChange(updatedCell);
        setExecutionResult(parsedResult);

      } catch (error) {
        console.error('External tool execution failed:', error);
        setErrorMessage(error instanceof Error ? error.message : 'Execution failed');
        const updatedCell = {
          ...cell,
          status: 'error'
        };
        onCellChange(updatedCell);
      } finally {
        setIsExecuting(false);
      }
      return;
    }

    // Regular code execution for non-external cells
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
  }, [cell, localCode, onCellChange]);

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

  const handleHeaderClick = (e: React.MouseEvent) => {
    // Only toggle if clicking the header area and not on other interactive elements
    const target = e.target as HTMLElement;
    if (!target.closest('button') && !target.closest('input')) {
      onToggle();
    }
  };

  return (
    <Card className="mb-4 border-l-4 border-l-blue-500 w-full">
      <CardHeader 
        className="flex flex-row items-center justify-between p-4 cursor-pointer" 
        onClick={handleHeaderClick}
      >
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
        <CardContent 
          className="p-2 space-y-4 w-full"
          onClick={(e) => {
            // Only close if clicking the top portion of the expanded content
            const target = e.target as HTMLElement;
            const rect = target.getBoundingClientRect();
            const clickY = e.clientY - rect.top;
            if (clickY < 50 && !target.closest('button') && !target.closest('input')) {
              onToggle();
            }
          }}
        >
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
          {cell.type === 'external' && cell.tool && (
            <ExternalTool
              tool={cell.tool}
              status={cell.status || 'pending'}
              input={cell.pipeMeasurements || {}}
              executionResult={executionResult}
            />
          )}
          
          {/* Visualization Section */}
          {stepFileData && (
            <div className="w-full">
              <VisualizationGrid 
                cards={createVisualizationCards(stepFileData.stlFile, stepFileData.pipeMeasurements)}
                cardsPerRow={7}
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
          
          {/* Output File - Now with JSON data */}
          {cell.output?.file && stepFileData && (
            <FileOutput
              file={{
                name: `${stepFileData.originalFileName}_measurements.json`,
                size: `${JSON.stringify(stepFileData.pipeMeasurements).length} bytes`,
                format: 'JSON',
                timestamp: stepFileData.timestamp,
                data: {
                  pipeMeasurements: stepFileData.pipeMeasurements,
                  originalFileName: stepFileData.originalFileName,
                  timestamp: stepFileData.timestamp
                }
              }}
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