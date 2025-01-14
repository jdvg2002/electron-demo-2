import React, { useState } from 'react';
import NotebookCell from '@/components/nuclear/NotebookCell';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { CellData } from '@/backend/models/Cell';
import { Module } from '@/backend/models/Module';

interface DemoProps {
  className?: string;
  cardId?: number;
}

const Demo = ({ className = '', cardId }: DemoProps) => {
  const manager = ModuleManager.getInstance();
  const [activeCells, setActiveCells] = useState<number[]>([]);

  let moduleObj: Module | undefined;
  if (cardId) {
    moduleObj = manager.getModuleById(cardId);
  }

  if (!moduleObj && cardId) {
    const parsedId = parseInt(cardId, 10);
    moduleObj = manager.createPreprocessingModuleWithGlobalFiles([]);
  }

  if (moduleObj && moduleObj.cells.length === 0) {
    moduleObj.setCells(defaultCells);
    manager.updateModuleCells(moduleObj.card.id, defaultCells);
  }

  if (!moduleObj) {
    return (
      <div className={`max-w-6xl mx-auto p-6 ${className}`}>
        <h1 className="text-2xl font-bold mb-2">Nuclear Safety Analysis Notebook</h1>
        <p className="text-gray-600">No valid module found. Please go to the Dashboard and create or select a card.</p>
      </div>
    );
  }

  const filteredCells = moduleObj.cells;

  function handleCellChange(updatedCell: CellData) {
    moduleObj?.updateCell(updatedCell);

    if (moduleObj) {
      manager.updateModuleCells(moduleObj.card.id, moduleObj.cells);
    }
  }

  return (
    <div className={`max-w-6xl mx-auto p-6 ${className}`}>
      <div className="mb-6">
        <h1 className="text-2xl font-bold mb-2">
          {moduleObj?.card.title || 'Nuclear Safety Analysis Notebook'}
        </h1>
        <p className="text-gray-600">
          Interactive workflow for nuclear reactor safety calculations
        </p>
      </div>

      <div className="space-y-4">
        {filteredCells.map(cell => (
          <NotebookCell
            key={cell.id}
            cell={cell}
            isActive={activeCells.includes(cell.id)}
            onToggle={() => {
              setActiveCells(prev =>
                prev.includes(cell.id)
                  ? prev.filter(id => id !== cell.id)
                  : [...prev, cell.id]
              );
            }}
            onCellChange={handleCellChange}
          />
        ))}
      </div>
    </div>
  );
};

export default Demo;