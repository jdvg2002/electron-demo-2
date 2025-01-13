import { Module } from '../models/Module';
import { ModuleCard } from '../models/ModuleCard';
import { CellData } from '../models/Cell';
import { GlobalFileData } from '../models/GlobalFiles';

export class ModuleManager {
  private static instance: ModuleManager;
  private modules: Module[] = [];
  private wires: any[] = [];

  private constructor() {}

  static getInstance(): ModuleManager {
    if (!ModuleManager.instance) {
      ModuleManager.instance = new ModuleManager();
    }
    return ModuleManager.instance;
  }

  createModule(card: ModuleCard, cells: CellData[] = []): Module {
    const module = new Module(card, cells);
    this.modules.push(module);
    return module;
  }

  // Create a complete module with all three cell types
  createPreprocessingModule(fileData: GlobalFileData): Module {
    const newId = this.modules.length ? Math.max(...this.modules.map(m => m.card.id)) + 1 : 1;
    
    // Create the card
    const card: ModuleCard = {
      id: newId,
      x: 20 + (this.modules.length % 3) * 300,
      y: 20 + Math.floor(this.modules.length / 3) * 150,
      isDragging: false,
      dragOffset: { x: 0, y: 0 },
      title: fileData.originalFileName,
      content: 'Nuclear Analysis Module'
    };

    // Create all three cells
    const cells: CellData[] = [
      {
        id: Date.now(),
        type: 'preprocessing',
        title: 'Input Preprocessing',
        stlFile: fileData.stlFile,
        pipeMeasurements: fileData.pipeMeasurements,
        globalFileId: fileData.id,
        timestamp: fileData.timestamp
      },
      {
        id: Date.now() + 1,
        type: 'external',
        title: 'External Analysis',
        tool: 'nuclear_analysis',
        status: 'pending'
      },
      {
        id: Date.now() + 2,
        type: 'postprocessing',
        title: 'Results Analysis',
        code: '# Analyze results here\n'
      }
    ];

    return this.createModule(card, cells);
  }

  getAllModules(): Module[] {
    return [...this.modules];
  }

  public getModuleById(id: number): Module | undefined {
    return this.modules.find(m => m.card.id === id);
  }

  public updateModule(moduleId: number, updatedCard?: ModuleCard, updatedCells?: CellData[]) {
    const existingModule = this.getModuleById(moduleId);
    if (!existingModule) return;

    if (updatedCard) {
      existingModule.card = updatedCard;
    }
    if (updatedCells) {
      existingModule.cells = updatedCells;
    }
  }

  public deleteModule(moduleId: number) {
    this.modules = this.modules.filter((m) => m.card.id !== moduleId);
  }

  public updateModuleCard(moduleId: number, partialCard: Partial<ModuleCard>) {
    const existingModule = this.getModuleById(moduleId);
    if (!existingModule) return;

    existingModule.card = { ...existingModule.card, ...partialCard };
  }

  public updateModuleCells(moduleId: number, newCells: CellData[]) {
    const existingModule = this.getModuleById(moduleId);
    if (!existingModule) return;

    existingModule.cells = newCells;
  }

  public getAllWires() {
    return this.wires;
  }

  public setWires(newWires: typeof this.wires) {
    this.wires = newWires;
  }

  public addWire(wire: {
    id: number;
    startCard: number;
    endCard: number;
    startX: number;
    startY: number;
    endX: number;
    endY: number;
    startRelX: number;
    startRelY: number;
    endRelX: number;
    endRelY: number;
  }) {
    this.wires.push(wire);
  }
} 