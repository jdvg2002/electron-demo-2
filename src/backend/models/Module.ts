import { CellData } from '@/backend/models/Cell';

/**
 * A Module is now just a data structure holding card info and cell IDs
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
  public cellIds: string[]; // Now we just store IDs, not the full cells
  public globalFileIds: string[]; // Add this at the module level

  constructor(
    card: Module['card'],
    cellIds: string[] = [],
    globalFileIds: string[] = []
  ) {
    this.card = card;
    this.cellIds = cellIds;
    this.globalFileIds = globalFileIds;
  }
} 