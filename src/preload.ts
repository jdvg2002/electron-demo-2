import { contextBridge, ipcRenderer } from 'electron';

interface ElectronWindow {
  minimize: () => Promise<void>;
  maximize: () => Promise<void>;
  close: () => Promise<void>;
  saveTempFile: (buffer: ArrayBuffer) => Promise<void>;
  executePython: (code: string) => Promise<{
    success: boolean;
    stdout?: string;
    result?: string;
    error?: string;
  }>;
  getProjectRoot: () => Promise<string>;
  processChunk: (data: { chunk: ArrayBuffer, chunkIndex: number }) => Promise<void>;
}

contextBridge.exposeInMainWorld('electronWindow', {
  minimize: () => ipcRenderer.invoke('window-minimize'),
  maximize: () => ipcRenderer.invoke('window-maximize'),
  close: () => ipcRenderer.invoke('window-close'),
  saveTempFile: (buffer: ArrayBuffer) => ipcRenderer.invoke('save-temp-file', buffer),
  executePython: (code: string) => ipcRenderer.invoke('execute-python', code),
  getProjectRoot: () => ipcRenderer.invoke('get-project-root'),
  processChunk: (data: { chunk: ArrayBuffer, chunkIndex: number }) => 
    ipcRenderer.invoke('process-chunk', data)
});

contextBridge.exposeInMainWorld('stepConverter', {
  convertStep: (filePath: string) => ipcRenderer.invoke('convert-step', filePath)
});

contextBridge.exposeInMainWorld('stepWorker', {
  initializeWorkerPool: () => ipcRenderer.invoke('init-worker-pool'),
  terminateWorkerPool: () => ipcRenderer.invoke('terminate-worker-pool')
});

contextBridge.exposeInMainWorld('cleanup', {
  clearStorage: () => ipcRenderer.invoke('cleanup:storage')
});