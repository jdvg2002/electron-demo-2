import React from 'react';
import { CellData } from '@/backend/models/Cell';
import { Card, CardHeader, CardTitle, CardContent } from '@/components/ui/card';
import { ChevronDown } from 'lucide-react';

export interface BaseCellProps {
  cell: CellData;
  isActive: boolean;
  onToggle: () => void;
  onCellChange: (updates: Partial<CellData>) => void;
  icon: React.ReactNode;
  borderColor: string;
  children?: React.ReactNode;
}

export const BaseCell: React.FC<BaseCellProps> = ({
  cell,
  isActive,
  onToggle,
  onCellChange,
  icon,
  borderColor,
  children,
}) => {
  const handleHeaderClick = (e: React.MouseEvent) => {
    const target = e.target as HTMLElement;
    if (!target.closest('button') && !target.closest('input')) {
      onToggle();
    }
  };

  return (
    <Card className={`mb-4 border-l-4 ${borderColor} w-full`}>
      <CardHeader 
        className="flex flex-row items-center justify-between p-4 cursor-pointer" 
        onClick={handleHeaderClick}
      >
        <div className="flex items-center gap-2">
          {icon}
          <CardTitle className="text-lg font-medium">Cell Type: {cell.type}</CardTitle>
        </div>
        <div className="flex items-center gap-2">
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
          {children}
        </CardContent>
      )}
    </Card>
  );
}; 