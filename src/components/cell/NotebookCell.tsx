import React from 'react';
import { CellData } from '@/backend/models/Cell';
import { PreprocessingCell } from './PreprocessingCell';
import { ExternalCell } from './ExternalCell';
import { PostprocessingCell } from './PostprocessingCell';

export interface NotebookCellProps {
  cell: CellData;
  isActive: boolean;
  onToggle: () => void;
  onCellChange: (updates: Partial<CellData>) => void;
}

const NotebookCell: React.FC<NotebookCellProps> = (props) => {
  switch (props.cell.type) {
    case 'preprocessing':
      return <PreprocessingCell {...props} />;
    case 'external':
      return <ExternalCell {...props} />;
    case 'postprocessing':
      return <PostprocessingCell {...props} />;
    default:
      return null;
  }
};

export default NotebookCell;
