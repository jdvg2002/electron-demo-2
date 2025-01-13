import { GlobalFileManager, GlobalFileData } from '../models/GlobalFiles';
import { ModuleManager } from './ModuleManager';
import { Module } from '../models/Module';
import { CellData } from '../models/Cell';

export class FileModuleManager {
  private static instance: FileModuleManager;
  private globalFileManager: GlobalFileManager;
  private moduleManager: ModuleManager;
  private listeners: (() => void)[] = [];

  private constructor() {
    this.globalFileManager = GlobalFileManager.getInstance();
    this.moduleManager = ModuleManager.getInstance();

    // Forward GlobalFileManager notifications to FileModuleManager listeners
    this.globalFileManager.addListener(() => {
      this.notifyListeners();
    });
  }

  static getInstance(): FileModuleManager {
    if (!FileModuleManager.instance) {
      FileModuleManager.instance = new FileModuleManager();
    }
    return FileModuleManager.instance;
  }

  public addListener(listener: () => void): () => void {
    this.listeners.push(listener);
    return () => {
      this.listeners = this.listeners.filter(l => l !== listener);
    };
  }

  private notifyListeners(): void {
    this.listeners.forEach(listener => listener());
  }

  public async createModuleFromFile(
    stlFile: File,
    pipeMeasurements: {
      inner_diameter: number;
      outer_diameter: number;
      wall_thickness: number;
    } | null,
    originalFileName: string
  ): Promise<Module> {
    // Create global file entry
    const globalFile: GlobalFileData = {
      id: Date.now().toString(),
      stlFile: {
        name: stlFile.name,
        data: await this.fileToBase64(stlFile),
        type: stlFile.type
      },
      pipeMeasurements: pipeMeasurements || {
        inner_diameter: 0,
        outer_diameter: 0,
        wall_thickness: 0
      },
      timestamp: new Date().toISOString(),
      originalFileName: originalFileName
    };

    // Add to global file manager
    this.globalFileManager.addFile(globalFile);

    // Create and return module
    return this.moduleManager.createPreprocessingModule(globalFile);
  }

  public getFileById(globalFileId: string): GlobalFileData | undefined {
    return this.globalFileManager.getAllFiles().find(f => f.id === globalFileId);
  }

  public getUnprocessedFiles(): GlobalFileData[] {
    return this.globalFileManager.getUnprocessedFiles();
  }

  public markFileAsProcessed(globalFileId: string): void {
    this.globalFileManager.markFileAsProcessed(globalFileId);
  }

  public addFileListener(listener: () => void): () => void {
    return this.globalFileManager.addListener(listener);
  }

  public async updateModuleWithFile(
    moduleId: number, 
    globalFileId: string
  ): Promise<void> {
    const module = this.moduleManager.getModuleById(moduleId);
    const file = this.getFileById(globalFileId);
    
    if (!module || !file) return;

    const preprocessingCell = module.getPreprocessingCell();
    if (preprocessingCell) {
      const updatedCell: CellData = {
        ...preprocessingCell,
        stlFile: file.stlFile,
        pipeMeasurements: file.pipeMeasurements,
        globalFileId: file.id,
        timestamp: file.timestamp
      };

      this.moduleManager.updateModuleCells(moduleId, [
        updatedCell,
        ...module.cells.filter(c => c.type !== 'preprocessing')
      ]);
    }
  }

  public async addFileFromUpload(
    stlFile: File,
    pipeMeasurements: {
      inner_diameter: number;
      outer_diameter: number;
      wall_thickness: number;
    },
    originalFileName: string
  ): Promise<string> {
    const base64Data = await this.fileToBase64(stlFile);
    const globalFile = {
      id: Date.now().toString(),
      stlFile: {
        name: stlFile.name,
        data: base64Data,
        type: stlFile.type
      },
      pipeMeasurements,
      timestamp: new Date().toISOString(),
      originalFileName
    };

    this.globalFileManager.addFile(globalFile);
    return globalFile.id;
  }

  private async fileToBase64(file: File): Promise<string> {
    return new Promise((resolve, reject) => {
      const reader = new FileReader();
      reader.onload = () => resolve(reader.result as string);
      reader.onerror = reject;
      reader.readAsDataURL(file);
    });
  }
} 