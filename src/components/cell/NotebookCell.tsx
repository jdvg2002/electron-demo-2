import React from 'react';
import { CellData } from '@/backend/models/Cell';
import { PreprocessingCell } from './PreprocessingCell';
import { ExternalCell } from './ExternalCell';
import { PostprocessingCell } from './PostprocessingCell';
import { CellOutputDisplay } from './output/CellOutputDisplay';

export interface NotebookCellProps {
  cell: CellData;
  isActive: boolean;
  onToggle: () => void;
  onCellChange: (updates: Partial<CellData>) => void;
  previousCell?: CellData;
  nextCell?: CellData;
}

const NotebookCell: React.FC<NotebookCellProps> = (props) => {
  const { cell, previousCell, nextCell } = props;

  const shouldShowPreprocessingOutput = cell.type === 'external' && 
    previousCell?.type === 'preprocessing' &&
    previousCell?.output !== undefined &&
    previousCell?.status === 'completed';

  const shouldShowExternalOutput = 
    nextCell?.type === 'postprocessing' && 
    cell.type === 'external' &&
    cell.output !== undefined &&
    cell.status === 'completed';

  const shouldShowPostprocessingOutput = 
    cell.type === 'postprocessing' &&
    cell.output !== undefined &&
    cell.status === 'completed';

  const shouldShowWiredInput = 
    cell.type === 'preprocessing' &&
    cell.input?.files !== undefined;

  return (
    <>
      {shouldShowWiredInput && (
        <CellOutputDisplay 
          previousCell={{
            ...cell,
            type: 'postprocessing',
            output: {
              processedData: cell.input.files,
              metadata: {
                analysisTimestamp: new Date().toISOString(),
                sourceAnalysis: 'postprocessing'
              }
            }
          }}
          nextCell={cell}
        />
      )}

      {shouldShowPreprocessingOutput && (
        <CellOutputDisplay 
          previousCell={previousCell} 
          nextCell={cell} 
        />
      )}
      
      {(() => {
        switch (cell.type) {
          case 'preprocessing':
            return <PreprocessingCell {...props} />;
          case 'external':
            return <ExternalCell {...props} />;
          case 'postprocessing':
            return <PostprocessingCell {...props} />;
          default:
            return null;
        }
      })()}

      {shouldShowExternalOutput && (
        <CellOutputDisplay 
          previousCell={cell} 
          nextCell={nextCell}
        />
      )}

      {shouldShowPostprocessingOutput && (
        <CellOutputDisplay 
          previousCell={cell}
          nextCell={nextCell}
        />
      )}
    </>
  );
};

export default NotebookCell;
