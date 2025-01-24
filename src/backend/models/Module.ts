import { CellData } from '@/backend/models/Cell';

/**
 * A Module holds a "card" object for frontend positioning/details,
 * and a list of cells that describe various steps or transformations.
 */
export class Module {
  public card: {
    id: number;
    x: number;
    y: number;
    isDragging: boolean;
    dragOffset: { x: number; y: number };
    title: string;
    content: string;
  };
  public cells: CellData[];

  constructor(
    card: Module['card'],
    cells: CellData[] = []
  ) {
    this.card = card;
    this.cells = cells;
  }

  /**
   * Replace all cells in this module
   */
  public setCells(cells: CellData[]): void {
    this.cells = cells;
  }

  /**
   * Update a specific cell by ID
   */
  public updateCell(updatedCell: CellData): void {
    const index = this.cells.findIndex(cell => cell.id === updatedCell.id);
    if (index !== -1) {
      this.cells[index] = updatedCell;
    }
  }

  /**
   * Add a new cell to the module
   */
  public addCell(cell: CellData): void {
    this.cells.push(cell);
  }

  /**
   * Remove a cell from the module by ID
   */
  public removeCell(cellId: string): void {
    this.cells = this.cells.filter(cell => cell.id !== cellId);
  }
} 