import { Module } from '@/backend/models/Module';
import { CellData } from '@/backend/models/Cell';
import { GlobalFileData } from '@/backend/models/GlobalFiles';

interface ModuleCard {
  id: number;
  x: number;
  y: number;
  isDragging: boolean;
  dragOffset: { x: number; y: number };
  title: string;
  content: string;
}

/**
 * Manages modules and their associated cells
 */
export class ModuleManager {
  private static instance: ModuleManager;
  private modules: Map<number, Module>;

  private constructor() {
    this.modules = new Map();
  }

  public static getInstance(): ModuleManager {
    if (!ModuleManager.instance) {
      ModuleManager.instance = new ModuleManager();
    }
    return ModuleManager.instance;
  }

  public getModuleById(id: number): Module | undefined {
    return this.modules.get(id);
  }

  public createModule(card: ModuleCard, cells: CellData[] = []): Module {
    const module = new Module(card, cells);
    this.modules.set(card.id, module);
    return module;
  }

  public updateModuleCells(moduleId: number, cells: CellData[]): void {
    const module = this.modules.get(moduleId);
    if (module) {
      module.setCells(cells);
    }
  }

  public deleteModule(moduleId: number): void {
    this.modules.delete(moduleId);
  }

  public getAllModules(): Module[] {
    return Array.from(this.modules.values());
  }

  /**
   * Adds a global file reference to all preprocessing cells across all modules
   */
  public applyGlobalFileToAllModules(globalFileId: string): void {
    this.getAllModules().forEach(module => {
      const preprocessingCells = module.cells.filter(cell => cell.type === 'preprocessing');
      preprocessingCells.forEach(cell => {
        const globalFileIds = cell.globalFileIds || [];
        if (!globalFileIds.includes(globalFileId)) {
          const updatedCell = {
            ...cell,
            globalFileIds: [...globalFileIds, globalFileId]
          };
          this.updateModuleCells(module.card.id, [
            updatedCell,
            ...module.cells.filter(c => c.id !== cell.id)
          ]);
        }
      });
    });
  }

  public createPreprocessingModuleWithGlobalFiles(files: GlobalFileData[]): Module {
    const newId = this.getAllModules().length ? 
      Math.max(...this.getAllModules().map(m => m.card.id)) + 1 : 1;
    
    const card: ModuleCard = {
      id: newId,
      x: 20 + (this.getAllModules().length % 3) * 300,
      y: 20 + Math.floor(this.getAllModules().length / 3) * 150,
      isDragging: false,
      dragOffset: { x: 0, y: 0 },
      title: files[0]?.originalFileName || `Card ${newId}`,
    };

    const cells: CellData[] = [
      {
        id: Date.now(),
        type: 'preprocessing',
        title: 'Input Preprocessing',
        globalFileIds: files.map(f => f.id),
        timestamp: new Date().toISOString()
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
      }
    ];

    return this.createModule(card, cells);
  }

  public updateModuleCard(moduleId: number, updates: Partial<ModuleCard>): void {
    const module = this.modules.get(moduleId);
    if (module) {
      module.card = {
        ...module.card,
        ...updates
      };
    }
  }
} 