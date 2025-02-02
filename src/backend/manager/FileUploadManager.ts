import { GlobalManager } from '@/backend/manager/GlobalManager';
import { VariableRecord } from '../models/Variable';
import { CellData } from '@/backend/models/Cell';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { GLTFLoader } from 'three/examples/jsm/loaders/GLTFLoader';
import * as THREE from 'three';

export interface ParsedFileResult {
  fileId: string;
  fileType: 'gltf' | 'step' | 'local' | 'csv' | 'glb';
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

interface PipeMeasurement {
    Component: string;
    inner_diameter: number;
    outer_diameter: number;
    wall_thickness: number;
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
    
    if (fileType.endsWith('.gltf')) {
      return this.handleGltfUpload(file, cell);
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

  private async handleGltfUpload(file: File, cell?: CellData): Promise<ParsedFileResult> {
    const timestamp = new Date().toISOString();
    const fileId = `gltf_${timestamp}_${file.name}`;
    const measurements = await this.extractGltfMeasurements(file);

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

    // Add to modules and notify listeners
    const modules = this.moduleManager.getAllModules();
    modules.forEach(module => {
      if (!module.globalFileIds.includes(fileId)) {
        module.globalFileIds.push(fileId);
      }
    });
    
    this.moduleManager.notifyListeners();

    return {
      fileId,
      fileType: 'gltf',
      measurements,
      rawFile: file,
      originalFileName: file.name,
      timestamp,
      cell
    };
  }

  private async handleStepUpload(file: File, cell?: CellData): Promise<ParsedFileResult> {
    const metrics = {
        startTime: performance.now(),
        steps: {} as Record<string, number>
    };

    try {
        console.log(`Starting STEP conversion for ${file.name} (${(file.size / (1024 * 1024)).toFixed(2)}MB)`);
        
        // Buffer creation
        const bufferStartTime = performance.now();
        const buffer = await file.arrayBuffer();
        metrics.steps.bufferCreation = performance.now() - bufferStartTime;
        
        // Save temp file
        const tempStartTime = performance.now();
        const tempPath = await window.electronWindow.saveTempFile(buffer);
        metrics.steps.tempFileSave = performance.now() - tempStartTime;
        
        // STEP conversion
        const conversionStartTime = performance.now();
        const result = await window.stepConverter.convertStep(tempPath);
        metrics.steps.stepConversion = performance.now() - conversionStartTime;

        if (!result.success) {
            throw new Error(result.error || 'Failed to convert STEP file');
        }

        if (!result.gltf_data) {
            throw new Error('No GLTF data received from conversion');
        }

        // GLTF processing
        const gltfStartTime = performance.now();
        const binaryString = atob(result.gltf_data);
        const bytes = new Uint8Array(binaryString.length);
        for (let i = 0; i < binaryString.length; i++) {
            bytes[i] = binaryString.charCodeAt(i);
        }
        
        const gltfBlob = new Blob([bytes], { type: 'model/gltf' });
        const newFileName = file.name.replace(/\.(step|stp)$/i, '.gltf');
        const gltfFile = new File([gltfBlob], newFileName, { type: 'model/gltf' });
        metrics.steps.gltfProcessing = performance.now() - gltfStartTime;
        
        const timestamp = new Date().toISOString();
        const fileId = await this.globalManager.addFileFromUpload(gltfFile, file.name);

        // Log performance metrics
        const totalTime = performance.now() - metrics.startTime;
        console.log('File Upload Performance Metrics:');
        console.log(`Total time: ${(totalTime / 1000).toFixed(2)}s`);
        Object.entries(metrics.steps).forEach(([step, time]) => {
            console.log(`${step}: ${(time / 1000).toFixed(2)}s`);
        });

        // Log Python-side metrics if available
        if (result.performance_metrics) {
            console.log('Python-side Performance Metrics:', result.performance_metrics);
        }

        // Process measurements if available
        if (result.pipe_measurements) {
            this.globalManager.addMeasurementBatch(
                fileId,
                Array.isArray(result.pipe_measurements) ? result.pipe_measurements.map((componentMeasurements: PipeMeasurement) => {
                    const { Component, ...measurements } = componentMeasurements;
                    return Object.entries(measurements).map(([name, value]): Omit<VariableRecord, 'id'> => ({
                        name: `${Component} - ${name}`,
                        value: value as number,
                        component: Component,
                        type: 'measurement' as const,
                        fileId
                    }));
                }).flat() : []
            );
        }

        return {
            fileId,
            fileType: 'glb',
            measurements: result.pipe_measurements || {},
            rawFile: gltfFile,
            originalFileName: file.name,
            timestamp,
            cell
        };

    } catch (error) {
        console.error('Error in handleStepUpload:', error);
        throw error;
    }
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

  private async extractGltfMeasurements(file: File): Promise<Record<string, number>> {
    return new Promise((resolve) => {
      const reader = new FileReader();
      reader.onload = (event) => {
        if (!event.target?.result) {
          resolve({});
          return;
        }

        const loader = new GLTFLoader();
        loader.parse(event.target.result as ArrayBuffer, '', 
          (gltf) => {
            const bbox = new THREE.Box3().setFromObject(gltf.scene);
            const size = new THREE.Vector3();
            bbox.getSize(size);
            
            const measurements: Record<string, number> = {
              'Width': size.x,
              'Height': size.y,
              'Depth': size.z,
            };
            resolve(measurements);
          },
          (error) => {
            console.error('Error parsing GLTF:', error);
            resolve({});
          }
        );
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
        fileType: file.originalFileName.toLowerCase().endsWith('.gltf') ? 'gltf' : 'step',
        measurements: {},
        rawFile: new File(
          [Uint8Array.from(atob(file.data.split(',')[1]), c => c.charCodeAt(0))],
          file.originalFileName,
          { type: 'model/gltf' }
        ),
        originalFileName: file.originalFileName,
        timestamp: file.timestamp
      });
    });

    return state;
  }
} 