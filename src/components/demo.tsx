import React, { useState } from 'react';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { CellData } from '@/backend/models/Cell';
import { Module } from '@/backend/models/Module';
import NotebookCell from './cell/NotebookCell';
import { CellManager } from '@/backend/manager/CellManager';

interface DemoProps {
  className?: string;
  cardId?: number;
}

const Demo = ({ className = '', cardId }: DemoProps) => {
  const manager = ModuleManager.getInstance();
  const [activeCells, setActiveCells] = useState<string[]>([]);

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

  const handleCellChange = (updatedCell: CellData) => {
    if (!moduleObj) return;

    console.log('Demo: Cell Change:', {
      moduleId: moduleObj.card.id,
      cellId: updatedCell.id,
      newCode: updatedCell.code
    });

    // Use CellManager directly to update the cell
    CellManager.getInstance().updateCell(
      moduleObj.card.id,
      updatedCell.id,
      updatedCell
    );
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
        {CellManager.getInstance().getCellsForModule(moduleObj.card.id).map(cell => {
          console.log('Rendering cell:', {
            moduleId: moduleObj.card.id,
            cellId: cell.id,
            type: cell.type
          });
          return (
            <NotebookCell
              key={cell.id}
              cell={cell}
              isActive={activeCells.includes(cell.id)}
              onToggle={() => {
                console.log('Demo: Cell Toggle:', {
                  cellId: cell.id,
                  currentlyActive: activeCells.includes(cell.id)
                });
                
                setActiveCells(prev =>
                  prev.includes(cell.id)
                    ? prev.filter(id => id !== cell.id)
                    : [...prev, cell.id]
                );
              }}
              onCellChange={handleCellChange}
              availableCells={CellManager.getInstance().getCellsForModule(moduleObj.card.id)}
            />
          );
        })}
      </div>
    </div>
  );
};

export default Demo;