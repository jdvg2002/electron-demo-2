import { ModuleManager } from './ModuleManager';
import { GlobalFileData } from '../models/GlobalFiles';

interface FileData {
  id: string;
  stlFile: {
    data: string;
    name: string;
    type: string;
  };
  pipeMeasurements: {
    inner_diameter: number;
    outer_diameter: number;
    wall_thickness: number;
  };
  originalFileName: string;
  timestamp: string;
  processed: boolean;
}

export class FileModuleManager {
  private static instance: FileModuleManager;
  private files: Map<string, FileData>;
  private listeners: Set<() => void>;
  private moduleManager: ModuleManager;

  private constructor() {
    this.files = new Map();
    this.listeners = new Set();
    this.moduleManager = ModuleManager.getInstance();
  }

  public static getInstance(): FileModuleManager {
    if (!FileModuleManager.instance) {
      FileModuleManager.instance = new FileModuleManager();
    }
    return FileModuleManager.instance;
  }

  public addListener(callback: () => void): () => void {
    this.listeners.add(callback);
    return () => this.listeners.delete(callback);
  }

  private notifyListeners(): void {
    this.listeners.forEach(callback => callback());
  }

  public async addFileFromUpload(
    file: File,
    measurements: FileData['pipeMeasurements'],
    originalFileName: string
  ): Promise<string> {
    return new Promise((resolve, reject) => {
      const reader = new FileReader();
      
      reader.onload = () => {
        try {
          const id = crypto.randomUUID();
          const fileData: FileData = {
            id,
            stlFile: {
              data: reader.result as string,
              name: file.name,
              type: file.type
            },
            pipeMeasurements: measurements,
            originalFileName,
            timestamp: new Date().toISOString(),
            processed: false
          };
          
          this.files.set(id, fileData);
          this.moduleManager.applyGlobalFileToAllModules(id);
          this.notifyListeners();
          resolve(id);
        } catch (error) {
          reject(error);
        }
      };

      reader.onerror = () => reject(reader.error);
      reader.readAsDataURL(file);
    });
  }

  public async createModuleFromFile(
    stlFile: File,
    measurements: FileData['pipeMeasurements'],
    originalFileName: string
  ): Promise<string> {
    return this.addFileFromUpload(stlFile, measurements, originalFileName);
  }

  public getFileById(id: string): FileData | undefined {
    return this.files.get(id);
  }

  public getUnprocessedFiles(): FileData[] {
    return Array.from(this.files.values())
      .filter(file => !file.processed);
  }

  public markFileAsProcessed(id: string): void {
    const file = this.files.get(id);
    if (file) {
      file.processed = true;
      this.files.set(id, file);
      this.notifyListeners();
    }
  }

  public deleteFile(id: string): void {
    this.files.delete(id);
    this.notifyListeners();
  }
} 