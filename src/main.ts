import { app, BrowserWindow, ipcMain } from "electron";
import registerListeners from "./helpers/ipc/listeners-register";
// "electron-squirrel-startup" seems broken when packaging with vite
//import started from "electron-squirrel-startup";
import path from "path";
import { PythonShell } from 'python-shell';
import fs from 'fs';
import os from 'os';

const inDevelopment = process.env.NODE_ENV === "development";

function createWindow() {
    const preload = path.join(__dirname, "preload.js");
    const mainWindow = new BrowserWindow({
        width: 800,
        height: 600,
        webPreferences: {
            devTools: inDevelopment,
            contextIsolation: true,
            nodeIntegration: true,
            nodeIntegrationInSubFrames: false,

            preload: preload,
        },
        titleBarStyle: "hidden",
    });
    registerListeners(mainWindow);

    if (MAIN_WINDOW_VITE_DEV_SERVER_URL) {
        mainWindow.loadURL(MAIN_WINDOW_VITE_DEV_SERVER_URL);
    } else {
        mainWindow.loadFile(
            path.join(__dirname, `../renderer/${MAIN_WINDOW_VITE_NAME}/index.html`)
        );
    }
}

app.whenReady().then(createWindow);

//osX only
app.on("window-all-closed", () => {
    if (process.platform !== "darwin") {
        app.quit();
    }
});

app.on("activate", () => {
    if (BrowserWindow.getAllWindows().length === 0) {
        createWindow();
    }
});
//osX only ends

// Add this near your other IPC handlers
ipcMain.handle('convert-step', async (_event, filePath) => {
  try {
    const result = await convert_step_to_stl(filePath);
    return result;
  } catch (error) {
    console.error('Conversion error:', error);
    return {
      success: false,
      error: error.message
    };
  }
});

ipcMain.handle('save-temp-file', async (_event, fileBuffer) => {
  const tempDir = os.tmpdir();
  const tempFile = path.join(tempDir, `temp-${Date.now()}.step`);
  await fs.promises.writeFile(tempFile, Buffer.from(fileBuffer));
  console.log('Saved temp file:', tempFile);
  return tempFile;
});

// Replace the direct import with a function that calls Python
async function convert_step_to_stl(filePath: string) {
  return new Promise((resolve, reject) => {
    const scriptPath = path.join(process.cwd(), 'server', 'server.py');
    const pythonPath = path.join(
      process.cwd(), 
      'bundled-python', 
      'envs', 
      'occ',
      os.platform() === 'win32' 
        ? 'python.exe' 
        : path.join('bin', 'python')
    );
    
    if (!fs.existsSync(pythonPath)) {
      return {
        success: false,
        error: 'Python environment not properly configured'
      };
    }
    
    PythonShell.run(scriptPath, {
      args: [filePath],
      mode: 'json',
      pythonPath: pythonPath,
      pythonOptions: ['-u']
    }).then(results => {
      resolve(results[0]);
    }).catch(error => {
      reject(error);
    });
  });
}
