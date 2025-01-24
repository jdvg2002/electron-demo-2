import { CellData } from '@/backend/models/Cell';

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

  public setCells(cells: CellData[]): void {
    this.cells = cells;
  }

  public updateCell(updatedCell: CellData): void {
    const index = this.cells.findIndex(cell => cell.id === updatedCell.id);
    if (index !== -1) {
      this.cells[index] = updatedCell;
    }
  }

  public addCell(cell: CellData): void {
    this.cells.push(cell);
  }

  public removeCell(cellId: number): void {
    this.cells = this.cells.filter(cell => cell.id !== cellId);
  }
} 