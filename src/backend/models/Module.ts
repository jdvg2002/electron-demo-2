import { CellData } from './Cell';
import { ModuleCard } from './ModuleCard';

export class Module {
  // This ties the "dashboard card" information and the "cells" together
  // to represent a full processing module in your application.

  public card: ModuleCard;
  public cells: CellData[];

  constructor(card: ModuleCard, cells: CellData[]) {
    this.card = card;
    this.cells = cells;
  }

  // Example method to update the card data
  updateCardPosition(x: number, y: number) {
    this.card.x = x;
    this.card.y = y;
  }

  updateCardTitle(title: string) {
    this.card.title = title;
  }

  updateCardContent(content: string) {
    this.card.content = content;
  }

  // Example method to update or replace the entire cell list
  setCells(cells: CellData[]) {
    this.cells = cells;
  }

  // Example method to update an individual cell by ID
  updateCell(updatedCell: CellData) {
    const index = this.cells.findIndex((c) => c.id === updatedCell.id);
    if (index !== -1) {
      this.cells[index] = updatedCell;
    }
  }

  // You can also add more logic for retrieving certain cells
  getCellById(cellId: number): CellData | undefined {
    return this.cells.find((cell) => cell.id === cellId);
  }

  // If you want to add any further specialized logic—like clearing outputs, etc.
  clearOutputs() {
    this.cells.forEach((cell) => {
      if (cell.output) {
        cell.output = {};
      }
    });
  }
} 