import { Module } from '@/backend/models/Module';
import { CellData } from '@/backend/models/Cell';
import { GlobalManager } from '@/backend/manager/GlobalManager';

/**
 * Represents the card (front-end) portion of a Module.
 * Typically includes positioning and display info.
 */
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
 * Light interface for passing global files into a newly-created Module.
 * (Used by createPreprocessingModuleWithGlobalFiles)
 */
interface GlobalFileData {
  id: string;
  // Extend with other properties if needed
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

  /**
   * Retrieve a single module by its unique id
   */
  public getModuleById(id: number): Module | undefined {
    return this.modules.get(id);
  }

  /**
   * Return all modules as an array
   */
  public getAllModules(): Module[] {
    return Array.from(this.modules.values());
  }

  /**
   * Create a new module and store it in the internal registry
   */
  public createModule(card: ModuleCard, cells: CellData[] = []): Module {
    const module = new Module(card, cells);
    this.modules.set(card.id, module);
    return module;
  }

  /**
   * Allows the front-end to create a "preprocessing" type module,
   * automatically attaching any passed-in global files.
   */
  public createPreprocessingModuleWithGlobalFiles(files: GlobalFileData[]): Module {
    // Generate new module ID
    const newId = this.getAllModules().length 
      ? Math.max(...this.getAllModules().map(m => m.card.id)) + 1 
      : 1;
    
    const card: ModuleCard = {
      id: newId,
      x: 20 + (this.getAllModules().length % 3) * 300,
      y: 20 + Math.floor(this.getAllModules().length / 3) * 150,
      isDragging: false,
      dragOffset: { x: 0, y: 0 },
      title: `Module ${newId}`,
      content: '',
    };

    // Basic cells for a "preprocessing → external → postprocessing" pipeline
    const baseTimestamp = Date.now();
    const cells: CellData[] = [
      {
        id: baseTimestamp.toString(),
        type: 'preprocessing',
        title: 'Input Preprocessing',
        status: 'pending',
        code: '#Add variables and calculations here\n',
        globalFileIds: files.map(f => f.id),
        localVariables: new Map(),
        input: {},
        output: {},
      },
      {
        id: (baseTimestamp + 1).toString(),
        type: 'external',
        title: 'External Analysis',
        tool: 'nuclear_analysis',
        status: 'pending',
        code: '#Add variables and calculations here\n',
        input: {},
        output: {},
      },
      {
        id: (baseTimestamp + 2).toString(),
        type: 'postprocessing',
        title: 'Results Analysis',
        status: 'pending',
        code: '#Add variables and calculations here\n',
        input: {},
        output: {},
      }
    ];

    return this.createModule(card, cells);
  }

  /**
   * Updates the cells of a specific module
   */
  public updateModuleCells(moduleId: number, cells: CellData[]): void {
    const module = this.modules.get(moduleId);
    if (module) {
      module.setCells(cells);
    }
  }

  /**
   * Updates the card (front-end display info) of a specific module
   */
  public updateModuleCard(moduleId: number, updates: Partial<ModuleCard>): void {
    const module = this.modules.get(moduleId);
    if (module) {
      module.card = { ...module.card, ...updates };
    }
  }

  /**
   * Removes a module from the registry entirely
   */
  public deleteModule(moduleId: number): void {
    this.modules.delete(moduleId);
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
} 