export interface DragOffset {
  x: number;
  y: number;
}

export interface ModuleCard {
  id: number;
  x: number;
  y: number;
  isDragging: boolean;
  dragOffset: DragOffset;
  title: string;
  content: string;
  // Add more fields if needed to store any extra config
} 