import React, { useState, useEffect } from 'react';
import { CellData } from '@/backend/models/Cell';
import { FileModuleManager } from '@/backend/manager/FileModuleManager';
import CellExecutionManager from '../managers/CellExecutionManager';
import CellCodeEditor from './shared/CellCodeEditor';
import FileUploadHandler from './shared/FileUploadHandler';
import ErrorDisplay from './shared/ErrorDisplay';
import ExecutionOutput from './shared/ExecutionOutput';
import LoadingIndicator from './shared/LoadingIndicator';
import VisualizationGrid, { createVisualizationCards } from '../CellVisualization';
import { Upload } from 'lucide-react';

interface PreprocessingCellProps {
  cell: CellData;
  onCellChange: (updatedCell: CellData) => void;
}

/**
 * Handles preprocessing operations including file uploads and initial data transformations
 */
const PreprocessingCell: React.FC<PreprocessingCellProps> = ({
  cell,
  onCellChange
}) => {
  const fileModuleManager = FileModuleManager.getInstance();
  const cellExecutionManager = CellExecutionManager.getInstance();
  
  const [localCode, setLocalCode] = useState(cell.code || '');
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [executionResult, setExecutionResult] = useState<any>(null);
  const [stepFilesData, setStepFilesData] = useState<any[]>([]);

  useEffect(() => {
    // Load existing file data if available
    if (cell.globalFileIds?.length) {
      const filesData = cell.globalFileIds
        .map(id => fileModuleManager.getFileById(id))
        .filter((file): file is GlobalFileData => file !== undefined)
        .map(file => ({
          stlFile: file.stlFile,
          pipeMeasurements: file.pipeMeasurements,
          originalFileName: file.originalFileName,
          timestamp: file.timestamp
        }));
      
      setStepFilesData(filesData);
    }
  }, [cell.globalFileIds]);

  const handleFileSelect = async (file: File) => {
    try {
      setErrorMessage(null);
      const globalFileId = await fileModuleManager.addFileFromUpload(
        file,
        { inner_diameter: 0, outer_diameter: 0, wall_thickness: 0 },
        file.name
      );

      const updatedCell = {
        ...cell,
        globalFileIds: [...(cell.globalFileIds || []), globalFileId]
      };
      onCellChange(updatedCell);
    } catch (error) {
      setErrorMessage(error instanceof Error ? error.message : 'File upload failed');
    }
  };

  const handleCodeExecution = async () => {
    try {
      setIsExecuting(true);
      setErrorMessage(null);
      
      const result = await cellExecutionManager.runPreprocessingCode(localCode);
      setExecutionResult(result);
      
      const updatedCell = {
        ...cell,
        code: localCode,
        output: {
          ...cell.output,
          result
        }
      };
      onCellChange(updatedCell);
    } catch (error) {
      setErrorMessage(error instanceof Error ? error.message : 'Execution failed');
    } finally {
      setIsExecuting(false);
    }
  };

  return (
    <div className="space-y-4">
      <FileUploadHandler onFileSelect={handleFileSelect}>
        <button className="flex items-center gap-2 px-4 py-2 bg-blue-500 text-white rounded hover:bg-blue-600">
          <Upload className="w-4 h-4" />
          Upload File
        </button>
      </FileUploadHandler>

      {errorMessage && <ErrorDisplay message={errorMessage} />}

      {stepFilesData.map((fileData, index) => (
        <VisualizationGrid 
          key={index}
          cards={createVisualizationCards(fileData.stlFile, fileData.pipeMeasurements)}
          cardsPerRow={7}
        />
      ))}

      <CellCodeEditor
        code={localCode}
        onChange={setLocalCode}
      />

      <button
        onClick={handleCodeExecution}
        disabled={isExecuting}
        className={`px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600 ${
          isExecuting ? 'opacity-50 cursor-not-allowed' : ''
        }`}
      >
        Run Preprocessing
      </button>

      {isExecuting && <LoadingIndicator />}
      
      {executionResult && <ExecutionOutput {...executionResult} />}
    </div>
  );
};

export default PreprocessingCell;