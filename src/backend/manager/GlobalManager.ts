import { VariableRecord } from '../Variable';
import { FileRecord } from '../File';

export class GlobalManager {
  private static instance: GlobalManager;
  private files: Map<string, FileRecord> = new Map();
  private variables: Map<string, VariableRecord> = new Map();
  private listeners: Set<() => void> = new Set();

  private constructor() {}

  static getInstance(): GlobalManager {
    if (!GlobalManager.instance) {
      GlobalManager.instance = new GlobalManager();
    }
    return GlobalManager.instance;
  }

  async addFileFromUpload(
    file: File,
    originalFileName: string
  ): Promise<string> {
    return new Promise((resolve, reject) => {
      const reader = new FileReader();
      
      reader.onload = () => {
        try {
          const id = crypto.randomUUID();
          const fileData: FileRecord = {
            id,
            type: file.type,
            version: '1.0',
            timestamp: new Date().toISOString(),
            originalFileName: originalFileName,
            sourceEnvironment: 'web-upload',
            data: reader.result as string,
          };
          
          this.files.set(id, fileData);
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

  addVariable(record: Omit<VariableRecord, 'id'>): string {
    const id = crypto.randomUUID();
    const variableRecord: VariableRecord = { id, ...record };
    
    if (!this.files.has(record.fileId)) {
      throw new Error(`File with ID ${record.fileId} not found`);
    }

    this.variables.set(id, variableRecord);
    this.notifyListeners();
    return id;
  }

  addMeasurement(
    fileId: string,
    name: string,
    value: number,
    units: string = 'mm'
  ): string {
    return this.addVariable({
      fileId,
      type: 'measurement',
      name,
      value,
      units
    });
  }

  addDistribution(
    fileId: string,
    label: string,
    mean: number,
    stdDev: number,
    name?: string
  ): string {
    const id = this.addVariable({
      fileId,
      type: 'distribution',
      name: name || label,
      label,
      mean,
      stdDev
    });
    
    // Force an immediate update
    requestAnimationFrame(() => this.notifyListeners());
    
    return id;
  }

  getFileById(id: string): FileRecord | undefined {
    return this.files.get(id);
  }

  getVariablesForFile(fileId: string): VariableRecord[] {
    return Array.from(this.variables.values())
      .filter(variable => variable.fileId === fileId);
  }

  getMeasurementsForFile(fileId: string): VariableRecord[] {
    return this.getVariablesForFile(fileId)
      .filter(variable => variable.type === 'measurement');
  }

  getDistributionsForFile(fileId: string): VariableRecord[] {
    return this.getVariablesForFile(fileId)
      .filter(variable => variable.type === 'distribution');
  }

  getAllFiles(): FileRecord[] {
    return Array.from(this.files.values());
  }

  removeFile(id: string): void {
    this.files.delete(id);
    // Remove all variables associated with this file
    for (const [varId, variable] of this.variables.entries()) {
      if (variable.fileId === id) {
        this.variables.delete(varId);
      }
    }
    this.notifyListeners();
  }

  addListener(callback: () => void): () => void {
    this.listeners.add(callback);
    return () => this.listeners.delete(callback);
  }

  private notifyListeners(): void {
    this.listeners.forEach(callback => callback());
  }

  public removeVariable(id: string): void {
    this.variables.delete(id);
    // Force an immediate update
    requestAnimationFrame(() => this.notifyListeners());
  }
} 