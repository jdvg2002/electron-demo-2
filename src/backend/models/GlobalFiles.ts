export interface DistributionData {
  label: string;
  mean: number;
  stdDev: number;
  timestamp: string;
}

export interface GlobalFileData {
  id: string;
  stlFile: {
    data: string;
    name: string;
    type: string;
  };
  pipeMeasurements: Record<string, number>;
  distributions?: Record<string, DistributionData>;
  originalFileName: string;
  timestamp: string;
}

export class GlobalFileManager {
  private static instance: GlobalFileManager;
  private files: Map<string, GlobalFileData> = new Map();
  private listeners: Set<() => void> = new Set();

  private constructor() {}

  static getInstance(): GlobalFileManager {
    if (!GlobalFileManager.instance) {
      GlobalFileManager.instance = new GlobalFileManager();
    }
    return GlobalFileManager.instance;
  }

  async addFileFromUpload(
    file: File,
    measurements: GlobalFileData['pipeMeasurements'],
    originalFileName: string
  ): Promise<string> {
    return new Promise((resolve, reject) => {
      const reader = new FileReader();
      
      reader.onload = () => {
        try {
          const id = crypto.randomUUID();
          const fileData: GlobalFileData = {
            id,
            stlFile: {
              data: reader.result as string,
              name: file.name,
              type: file.type
            },
            pipeMeasurements: measurements,
            originalFileName,
            timestamp: new Date().toISOString(),
            distributions: {} // Initialize empty distributions object
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

  addDistribution(
    fileId: string,
    label: string,
    mean: number,
    stdDev: number
  ): void {
    const file = this.files.get(fileId);
    if (!file) {
      console.warn(`File with ID ${fileId} not found`);
      return;
    }

    if (!file.distributions) {
      file.distributions = {};
    }

    file.distributions[label] = {
      label,
      mean,
      stdDev,
      timestamp: new Date().toISOString()
    };

    this.files.set(fileId, file);
    this.notifyListeners();
  }

  getFileById(id: string): GlobalFileData | undefined {
    return this.files.get(id);
  }

  getAllFiles(): GlobalFileData[] {
    return Array.from(this.files.values());
  }

  removeFile(id: string): void {
    this.files.delete(id);
    this.notifyListeners();
  }

  addListener(callback: () => void): () => void {
    this.listeners.add(callback);
    return () => this.listeners.delete(callback);
  }

  private notifyListeners(): void {
    this.listeners.forEach(callback => callback());
  }
} 