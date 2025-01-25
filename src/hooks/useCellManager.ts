import { useState, useEffect, useCallback } from 'react';
import { CellManager } from '@/backend/manager/CellManager';
import { CellData } from '@/backend/models/Cell';

export function useCellManager(moduleId?: number) {
  const [cells, setCells] = useState<CellData[]>(() => 
    moduleId ? CellManager.getInstance().getCellsForModule(moduleId) : []
  );

  useEffect(() => {
    const manager = CellManager.getInstance();
    
    // Update cells when moduleId changes
    if (moduleId) {
      setCells(manager.getCellsForModule(moduleId));
    }

    // Subscribe to cell changes
    return manager.addListener(() => {
      if (moduleId) {
        setCells(manager.getCellsForModule(moduleId));
      }
    });
  }, [moduleId]);

  const createCell = useCallback((
    type: 'preprocessing' | 'external' | 'postprocessing',
    initialData?: Partial<CellData>
  ) => {
    if (!moduleId) throw new Error('No moduleId provided to useCellManager');
    return CellManager.getInstance().createCell(moduleId, type, initialData);
  }, [moduleId]);

  const updateCell = useCallback((
    cellId: string,
    updates: Partial<CellData>
  ) => {
    if (!moduleId) throw new Error('No moduleId provided to useCellManager');
    CellManager.getInstance().updateCell(moduleId, cellId, updates);
  }, [moduleId]);

  const removeCell = useCallback((cellId: string) => {
    if (!moduleId) throw new Error('No moduleId provided to useCellManager');
    CellManager.getInstance().removeCell(moduleId, cellId);
  }, [moduleId]);

  const createDefaultCells = useCallback(() => {
    if (!moduleId) throw new Error('No moduleId provided to useCellManager');
    return CellManager.getInstance().createDefaultCellsForModule(moduleId);
  }, [moduleId]);

  return {
    cells,
    createCell,
    updateCell,
    removeCell,
    createDefaultCells
  };
} 