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

  const shouldShowOutput = cell.type === 'external' && 
    previousCell?.type === 'preprocessing' &&
    previousCell?.output !== undefined &&
    previousCell?.status === 'completed';  // Only show if preprocessing completed successfully

  return (
    <>
      {shouldShowOutput && (
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
    </>
  );
};

export default NotebookCell;
