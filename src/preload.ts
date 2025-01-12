import { contextBridge, ipcRenderer } from 'electron';

contextBridge.exposeInMainWorld('electronWindow', {
  minimize: () => ipcRenderer.invoke('window-minimize'),
  maximize: () => ipcRenderer.invoke('window-maximize'),
  close: () => ipcRenderer.invoke('window-close'),
  saveTempFile: (buffer: ArrayBuffer) => ipcRenderer.invoke('save-temp-file', buffer)
});

contextBridge.exposeInMainWorld('stepConverter', {
  convertStep: (filePath: string) => ipcRenderer.invoke('convert-step', filePath)
});
