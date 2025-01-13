export interface GlobalFileData {
  id: string;
  stlFile: {
    name: string;
    data: string;  // Base64 encoded STL data
    type: string;
  };
  pipeMeasurements: {
    inner_diameter: number;
    outer_diameter: number;
    wall_thickness: number;
  };
  timestamp: string;
  originalFileName: string;
}

export class GlobalFileManager {
  private static instance: GlobalFileManager;
  private files: GlobalFileData[] = [];
  private listeners: (() => void)[] = [];

  private constructor() {}

  static getInstance(): GlobalFileManager {
    if (!GlobalFileManager.instance) {
      GlobalFileManager.instance = new GlobalFileManager();
    }
    return GlobalFileManager.instance;
  }

  addFile(file: GlobalFileData) {
    this.files.push(file);
    this.notifyListeners();
  }

  removeFile(id: string) {
    this.files = this.files.filter(f => f.id !== id);
    this.notifyListeners();
  }

  getAllFiles(): GlobalFileData[] {
    return [...this.files];
  }

  clearFiles() {
    this.files = [];
    this.notifyListeners();
  }

  addListener(listener: () => void) {
    this.listeners.push(listener);
    return () => {
      this.listeners = this.listeners.filter(l => l !== listener);
    };
  }

  private notifyListeners() {
    this.listeners.forEach(listener => listener());
  }
} 