import React, { useEffect } from 'react';
import { CellData } from '@/backend/models/Cell';

interface NotebookCellProps {
  cell: CellData;
  isActive: boolean;
  onToggle: () => void;
  onCellChange: (updatedCell: CellData) => void;
  availableCells: CellData[];
}

const NotebookCell: React.FC<NotebookCellProps> = ({
  cell,
  isActive,
  onToggle,
  onCellChange,
  availableCells
}) => {
  useEffect(() => {
    console.log('NotebookCell mounted:', {
      cellId: cell.id,
      type: cell.type
    });
  }, [cell]);

  return (
    <div>
      <pre>
        {JSON.stringify(cell, null, 2)}
      </pre>
    </div>
  );
};

export default NotebookCell;
