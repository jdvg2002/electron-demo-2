import React from 'react';
import { Play } from 'lucide-react';
import { BaseCell } from './BaseCell';
import type { NotebookCellProps } from './NotebookCell';

export const ExternalCell: React.FC<NotebookCellProps> = (props) => {
  return (
    <BaseCell
      {...props}
      icon={<Play className="text-green-500" />}
      borderColor="border-l-green-500"
    />
  );
}; 