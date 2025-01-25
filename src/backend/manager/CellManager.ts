import { CellData } from '@/backend/models/Cell';

type CellType = 'preprocessing' | 'external' | 'postprocessing';

interface CellRegistry {
  [moduleId: number]: {
    [cellId: string]: CellData;
  };
}

export class CellManager {
  private static instance: CellManager;
  private cells: CellRegistry = {};
  private listeners: Set<() => void> = new Set();
  private lastCellId = 0;

  private constructor() {}

  public static getInstance(): CellManager {
    if (!CellManager.instance) {
      CellManager.instance = new CellManager();
    }
    return CellManager.instance;
  }

  /**
   * Create a new cell for a specific module
   */
  public createCell(
    moduleId: number,
    type: CellType,
    initialData: Partial<CellData> = {}
  ): CellData {
    this.lastCellId++;
    const newId = `cell_${moduleId}_${type}_${this.lastCellId}`;
    
    const newCell: CellData = {
      id: newId,
      type,
      title: this.getDefaultTitleForType(type),
      status: 'pending',
      code: '',
      input: {},
      output: {},
      ...initialData
    };

    // Initialize module's cell registry if it doesn't exist
    if (!this.cells[moduleId]) {
      this.cells[moduleId] = {};
    }

    this.cells[moduleId][newId] = newCell;
    this.notifyListeners();
    return newCell;
  }

  /**
   * Update an existing cell
   */
  public updateCell(
    moduleId: number,
    cellId: string,
    updates: Partial<CellData>
  ): void {
    if (!this.cells[moduleId]?.[cellId]) {
      throw new Error(`Cell ${cellId} not found in module ${moduleId}`);
    }

    this.cells[moduleId][cellId] = {
      ...this.cells[moduleId][cellId],
      ...updates
    };

    this.notifyListeners();
  }

  /**
   * Remove a cell from a module
   */
  public removeCell(moduleId: number, cellId: string): void {
    if (this.cells[moduleId]) {
      delete this.cells[moduleId][cellId];
      this.notifyListeners();
    }
  }

  /**
   * Get all cells for a specific module
   */
  public getCellsForModule(moduleId: number): CellData[] {
    return Object.values(this.cells[moduleId] || {});
  }

  public addListener(callback: () => void): () => void {
    this.listeners.add(callback);
    return () => this.listeners.delete(callback);
  }

  private getDefaultTitleForType(type: CellType): string {
    switch (type) {
      case 'preprocessing':
        return 'Input Preprocessing';
      case 'external':
        return 'External Analysis';
      case 'postprocessing':
        return 'Results Analysis';
      default:
        return 'New Cell';
    }
  }

  private notifyListeners(): void {
    this.listeners.forEach(callback => callback());
  }
} 