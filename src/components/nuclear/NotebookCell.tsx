import React from 'react';
import { Card, CardHeader, CardTitle, CardContent } from '@/components/ui/card';
import { Play, ChevronDown, Upload, Box, BarChart2 } from 'lucide-react';
import { CellData } from '@/backend/Cell';
import PreprocessingCell from './cells/PreprocessingCell';
import ExternalCell from './cells/ExternalCell';
import PostprocessingCell from './cells/PostprocessingCell';

interface NotebookCellProps {
  cell: CellData;
  isActive: boolean;
  onToggle(): void;
  onCellChange: (updatedCell: CellData) => void;
  availableCells: CellData[];
}

/**
 * NotebookCell serves as a shell component that handles common cell UI elements
 * and delegates specific cell type rendering to specialized components.
 */
const NotebookCell: React.FC<NotebookCellProps> = ({
  cell,
  isActive,
  onToggle,
  onCellChange,
  availableCells = []
}) => {
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
    const target = e.target as HTMLElement;
    if (!target.closest('button') && !target.closest('input')) {
      onToggle();
    }
  };

  const renderCellContent = () => {
    const commonProps = {
      cell,
      onCellChange,
      availableCells
    };

    switch (cell.type) {
      case 'preprocessing':
        return <PreprocessingCell {...commonProps} />;
      case 'external':
        return <ExternalCell {...commonProps} />;
      case 'postprocessing':
        return <PostprocessingCell {...commonProps} />;
      default:
        return null;
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
          {renderCellContent()}
        </CardContent>
      )}
    </Card>
  );
};

export default NotebookCell;