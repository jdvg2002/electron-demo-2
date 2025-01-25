import { Module } from '@/backend/models/Module';
import { CellManager } from '@/backend/manager/CellManager';
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
  private cellManager: CellManager;
  private globalManager: GlobalManager;
  private listeners: Set<() => void> = new Set();

  private constructor() {
    this.modules = new Map();
    this.cellManager = CellManager.getInstance();
    this.globalManager = GlobalManager.getInstance();
  }

  public static getInstance(): ModuleManager {
    if (!ModuleManager.instance) {
      ModuleManager.instance = new ModuleManager();
    }
    return ModuleManager.instance;
  }

  /**
   * Create a new module
   */
  public createModule(): Module {
    const newId = this.getAllModules().length 
      ? Math.max(...this.getAllModules().map(m => m.card.id)) + 1 
      : 1;
    
    const card = {
      id: newId,
      x: 20 + (this.getAllModules().length % 3) * 300,
      y: 20 + Math.floor(this.getAllModules().length / 3) * 150,
      isDragging: false,
      dragOffset: { x: 0, y: 0 },
      title: `Module ${newId}`,
      content: '',
    };

    // 3. Get current global files
    const globalFileIds = this.globalManager.getAllFiles().map(f => f.id);

    // 4. Create required cells
    const cellIds = [
      this.cellManager.createCell(newId, 'preprocessing').id,
      this.cellManager.createCell(newId, 'external', { tool: 'nuclear_analysis' }).id,
      this.cellManager.createCell(newId, 'postprocessing').id
    ];
    
    console.log('Created cells for module:', {
      moduleId: newId,
      cellIds: cellIds
    });

    // 5. Create and store module with global files
    const module = new Module(card, cellIds, globalFileIds);
    this.modules.set(newId, module);
    this.notifyListeners();
    
    return module;
  }

  /**
   * Update module card properties only (position, title, etc)
   */
  public updateModuleCard(
    moduleId: number, 
    updates: Partial<Omit<Module['card'], 'id'>>
  ): void {
    const module = this.modules.get(moduleId);
    if (module) {
      module.card = { ...module.card, ...updates };
      this.notifyListeners();
    }
  }

  /**
   * Delete a module and its associated cells
   */
  public deleteModule(moduleId: number): void {
    const module = this.modules.get(moduleId);
    if (module) {
      // Delete all associated cells first
      module.cellIds.forEach(cellId => {
        this.cellManager.removeCell(moduleId, cellId);
      });
      this.modules.delete(moduleId);
      this.notifyListeners();
    }
  }

  public getModuleById(id: number): Module | undefined {
    return this.modules.get(id);
  }

  public getAllModules(): Module[] {
    return Array.from(this.modules.values());
  }

  public addListener(callback: () => void): () => void {
    this.listeners.add(callback);
    return () => this.listeners.delete(callback);
  }

  private notifyListeners(): void {
    this.listeners.forEach(callback => callback());
  }
} 