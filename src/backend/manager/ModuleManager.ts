import { Module } from '../models/Module';
import { ModuleCard } from '../models/ModuleCard';
import { CellData } from '../models/Cell';

export class ModuleManager {
  private modules: Module[] = [];
  private wires: Array<{
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
  }> = [];

  private static instance: ModuleManager | null = null;

  private constructor() {
    // this.loadFromLocalStorage();
  }

  public static getInstance(): ModuleManager {
    if (!ModuleManager.instance) {
      ModuleManager.instance = new ModuleManager();
    }
    return ModuleManager.instance;
  }

  public getAllModules(): Module[] {
    return this.modules;
  }

  public getModuleById(id: number): Module | undefined {
    return this.modules.find(m => m.card.id === id);
  }

  public createModule(card: ModuleCard, cells: CellData[]): Module {
    const newModule = new Module(card, cells);
    this.modules.push(newModule);
    return newModule;
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