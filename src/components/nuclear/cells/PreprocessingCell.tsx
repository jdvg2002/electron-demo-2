import React, { useState, useEffect } from 'react';
import { CellData } from '@/backend/models/Cell';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';
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
  const globalFileManager = GlobalFileManager.getInstance();
  const cellExecutionManager = CellExecutionManager.getInstance();
  
  const [localCode, setLocalCode] = useState(cell.code || 'import numpy as np\n\n# Process reactor data\ndef process_data(input):\n    return np.mean(input)');
  const [isExecuting, setIsExecuting] = useState(false);
  const [errorMessage, setErrorMessage] = useState<string | null>(null);
  const [executionResult, setExecutionResult] = useState<any>(null);
  const [stepFilesData, setStepFilesData] = useState<any[]>([]);

  useEffect(() => {
    if (cell.globalFileIds?.length) {
      const filesData = cell.globalFileIds
        .map(id => globalFileManager.getFileById(id))
        .filter(file => file !== undefined)
        .map(file => ({
          stlFile: file.stlFile,
          pipeMeasurements: file.pipeMeasurements,
          distributions: file.distributions,
          originalFileName: file.originalFileName,
          timestamp: file.timestamp
        }));
      
      setStepFilesData(filesData);
    }
  }, [cell.globalFileIds]);

  const handleFileSelect = async (file: File) => {
    try {
      setErrorMessage(null);
      const globalFileId = await globalFileManager.addFileFromUpload(
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
      {stepFilesData.map((fileData, index) => (
        <VisualizationGrid 
          key={index}
          cards={createVisualizationCards(
            fileData.stlFile, 
            fileData.pipeMeasurements,
            fileData.distributions
          )}
          cardsPerRow={6}
          fileId={cell.globalFileIds[index]}
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