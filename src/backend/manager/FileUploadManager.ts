import { GlobalManager } from '@/backend/manager/GlobalManager';
import { VariableRecord } from '../models/Variable';
import { STLLoader } from 'three/examples/jsm/loaders/STLLoader';
import { CellData } from '@/backend/models/Cell';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { v4 as uuidv4 } from 'uuid';

export interface ParsedFileResult {
  fileId: string;
  fileType: 'stl' | 'step' | 'local' | 'csv';
  measurements: Record<string, number>;
  rawFile: File;
  originalFileName: string;
  timestamp: string;
  cell?: CellData;
}

export interface FileUploadState {
  files: ParsedFileResult[];
  measurements: Record<string, VariableRecord[]>;
  distributions: Record<string, VariableRecord[]>;
  isLoading: boolean;
  error: string | null;
}

export class FileUploadManager {
  private static instance: FileUploadManager;
  private globalManager: GlobalManager;
  private moduleManager: ModuleManager;

  private constructor() {
    this.globalManager = GlobalManager.getInstance();
    this.moduleManager = ModuleManager.getInstance();
  }

  static getInstance(): FileUploadManager {
    if (!FileUploadManager.instance) {
      FileUploadManager.instance = new FileUploadManager();
    }
    return FileUploadManager.instance;
  }

  async uploadFile(file: File, cell?: CellData): Promise<ParsedFileResult> {
    const fileType = file.name.toLowerCase();
    
    if (fileType.endsWith('.stl')) {
      return this.handleStlUpload(file, cell);
    } 
    else if (fileType.endsWith('.step') || fileType.endsWith('.stp')) {
      return this.handleStepUpload(file, cell);
    }
    else if (fileType.endsWith('.csv')) {
      return this.handleCsvUpload(file, cell);
    }
    else {
      throw new Error('Unsupported file type');
    }
  }

  private async handleStlUpload(file: File, cell?: CellData): Promise<ParsedFileResult> {
    const timestamp = new Date().toISOString();
    const fileId = `stl_${timestamp}_${file.name}`;
    const measurements = await this.extractSTLMeasurements(file);

    // Store in GlobalFileManager
    await this.globalManager.addFileFromUpload(file, file.name);

    // Update cell if provided
    if (cell) {
      const reader = new FileReader();
      const base64data = await new Promise<string>((resolve) => {
        reader.onload = () => resolve(reader.result as string);
        reader.readAsDataURL(file);
      });
    }

    // After file is uploaded, add it to all existing modules
    const modules = this.moduleManager.getAllModules();
    modules.forEach(module => {
      if (!module.globalFileIds.includes(fileId)) {
        module.globalFileIds.push(fileId);
      }
    });
    
    // Notify listeners of the change
    this.moduleManager.notifyListeners();

    return {
      fileId,
      fileType: 'stl',
      measurements,
      rawFile: file,
      originalFileName: file.name,
      timestamp,
      cell
    };
  }

  private async handleStepUpload(file: File, cell?: CellData): Promise<ParsedFileResult> {
    const buffer = await file.arrayBuffer();
    const tempPath = await window.electronWindow.saveTempFile(buffer);
    const result = await window.stepConverter.convertStep(tempPath);

    if (!result.success) {
      throw new Error(result.error || 'Failed to convert STEP file');
    }

    if (!result.stl_data) {
      throw new Error('No STL data received from conversion');
    }

    // Decode base64 STL data to binary
    const binaryString = atob(result.stl_data);
    const bytes = new Uint8Array(binaryString.length);
    for (let i = 0; i < binaryString.length; i++) {
        bytes[i] = binaryString.charCodeAt(i);
    }
    
    const stlBlob = new Blob([bytes], { type: 'model/stl' });
    const newFileName = file.name.replace(/\.(step|stp)$/i, '.stl');
    const stlFile = new File([stlBlob], newFileName, { type: 'model/stl' });
    
    const timestamp = new Date().toISOString();
    const fileId = await this.globalManager.addFileFromUpload(stlFile, file.name);

    // Add measurements from STEP conversion
    if (result.pipe_measurements) {
        this.globalManager.addMeasurementBatch(
            fileId,
            result.pipe_measurements.map(componentMeasurements => {
                const { Component, ...measurements } = componentMeasurements;
                return Object.entries(measurements).map(([name, value]) => ({
                    name: `${Component} - ${name}`,
                    value: value as number,
                    component: Component
                }));
            }).flat()
        );
    }

    // After file is uploaded, add it to all existing modules
    const modules = this.moduleManager.getAllModules();
    modules.forEach(module => {
        if (!module.globalFileIds.includes(fileId)) {
            module.globalFileIds.push(fileId);
        }
    });
    
    // Notify listeners of the change
    this.moduleManager.notifyListeners();

    return {
        fileId,
        fileType: 'step',
        measurements: result.pipe_measurements || {},
        rawFile: stlFile,
        originalFileName: file.name,
        timestamp,
        cell
    };
  }

  private async handleCsvUpload(file: File, cell?: CellData): Promise<ParsedFileResult> {
    try {
      const text = await file.text();
      const rows = text.split('\n').map(row => row.split(',').map(cell => cell.trim()));
      const headers = rows[0];
      const data = rows.slice(1).filter(row => row.length === headers.length);

      const fileId = await this.globalManager.addFileFromUpload(file, file.name);
      this.globalManager.addCSVData(fileId, {
        headers,
        rows: data
      });

      return {
        fileId,
        fileType: 'csv',
        measurements: {},
        rawFile: file,
        originalFileName: file.name,
        timestamp: new Date().toISOString(),
        cell
      };
    } catch (error) {
      console.error('Error handling CSV upload:', error);
      throw error;
    }
  }

  private async extractSTLMeasurements(file: File): Promise<Record<string, number>> {
    return new Promise((resolve) => {
      const reader = new FileReader();
      reader.onload = (event) => {
        if (!event.target?.result) {
          resolve({});
          return;
        }

        const loader = new STLLoader();
        const geometry = loader.parse(event.target.result as ArrayBuffer);
        
        // Calculate basic measurements
        const bbox = geometry.boundingBox;
        if (!bbox) {
          geometry.computeBoundingBox();
        }
        
        const measurements: Record<string, number> = {
          'Width': Math.abs(bbox!.max.x - bbox!.min.x),
          'Height': Math.abs(bbox!.max.y - bbox!.min.y),
          'Depth': Math.abs(bbox!.max.z - bbox!.min.z),
          'Volume': geometry.getAttribute('position').count / 3, // Approximate
        };

        resolve(measurements);
      };
      
      reader.readAsArrayBuffer(file);
    });
  }

  removeFile(fileId: string): void {
    this.globalManager.removeFile(fileId);
  }

  addMeasurement(fileId: string, measurement: Omit<VariableRecord, 'id'>): void {
    if (measurement.type !== 'measurement') return;
    
    this.globalManager.addMeasurement(
      fileId,
      measurement.name ?? measurement.label,
      measurement.value ?? 0,
      measurement.units
    );
  }

  addDistribution(fileId: string, distribution: Omit<VariableRecord, 'id'>): void {
    if (distribution.type !== 'distribution') return;
    
    this.globalManager.addDistribution(
      fileId,
      distribution.label ?? distribution.name,
      distribution.mean ?? 0,
      distribution.stdDev ?? 0,
      distribution.name ?? distribution.label
    );
  }

  getFilesState(): FileUploadState {
    const files = this.globalManager.getAllFiles();
    const state: FileUploadState = {
      files: [],
      measurements: {},
      distributions: {},
      isLoading: false,
      error: null
    };

    files.forEach(file => {
      state.measurements[file.id] = this.globalManager.getMeasurementsForFile(file.id);
      state.distributions[file.id] = this.globalManager.getDistributionsForFile(file.id);
      
      state.files.push({
        fileId: file.id,
        fileType: file.originalFileName.toLowerCase().endsWith('.stl') ? 'stl' : 'step',
        measurements: {},
        rawFile: new File(
          [Uint8Array.from(atob(file.data.split(',')[1]), c => c.charCodeAt(0))],
          file.originalFileName,
          { type: 'model/stl' }
        ),
        originalFileName: file.originalFileName,
        timestamp: file.timestamp
      });
    });

    return state;
  }
} 