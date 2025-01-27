import React from 'react';
import { BarChart2 } from 'lucide-react';
import { BaseCell } from './BaseCell';
import type { NotebookCellProps } from './NotebookCell';

export const PostprocessingCell: React.FC<NotebookCellProps> = (props) => {
  return (
    <BaseCell
      {...props}
      icon={<BarChart2 className="text-purple-500" />}
      borderColor="border-l-purple-500"
    />
  );
}; 