import React, { useState } from 'react';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { CellData } from '@/backend/models/Cell';
import { Module } from '@/backend/models/Module';
import NotebookCell from './cell/NotebookCell';
import { useCellManager } from '@/hooks/useCellManager';

interface DemoProps {
  className?: string;
  cardId?: number;
}

const Demo = ({ className = '', cardId }: DemoProps) => {
  const manager = ModuleManager.getInstance();
  const [activeCells, setActiveCells] = useState<string[]>([]);
  const { cells, updateCell } = useCellManager(cardId);

  let moduleObj: Module | undefined;
  if (cardId) {
    moduleObj = manager.getModuleById(cardId);
    if (!moduleObj) {
      moduleObj = manager.createModule();
    }
  }

  if (!moduleObj) {
    return (
      <div className={`max-w-6xl mx-auto p-6 ${className}`}>
        <h1 className="text-2xl font-bold mb-2">Nuclear Safety Analysis Notebook</h1>
        <p className="text-gray-600">No valid module found. Please go to the Dashboard and create or select a card.</p>
      </div>
    );
  }

  const handleCellChange = (cellId: string, updates: Partial<CellData>) => {
    console.log('Demo: Cell Change:', {
      moduleId: moduleObj?.card.id,
      cellId,
      updates
    });
    updateCell(cellId, updates);
  };

  return (
    <div className={`max-w-6xl mx-auto p-6 ${className}`}>
      <div className="mb-6">
        <h1 className="text-2xl font-bold mb-2">
          {moduleObj.card.title || 'Nuclear Safety Analysis Notebook'}
        </h1>
        <p className="text-gray-600">
          Interactive workflow for nuclear reactor safety calculations
        </p>
      </div>

      <div className="space-y-4">
        {cells.map((cell, index) => (
          <NotebookCell
            key={cell.id}
            cell={cell}
            previousCell={index > 0 ? cells[index - 1] : undefined}
            nextCell={index < cells.length - 1 ? cells[index + 1] : undefined}
            isActive={activeCells.includes(cell.id)}
            onToggle={() => {
              setActiveCells(prev =>
                prev.includes(cell.id)
                  ? prev.filter(id => id !== cell.id)
                  : [...prev, cell.id]
              );
            }}
            onCellChange={(updates) => handleCellChange(cell.id, updates)}
          />
        ))}
      </div>
    </div>
  );
};

export default Demo;