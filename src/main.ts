import { app, BrowserWindow, ipcMain, screen } from "electron";
import registerListeners from "./helpers/ipc/listeners-register";
import path from "path";
import { PythonShell } from 'python-shell';
import fs from 'fs';
import os from 'os';
import { WorkerPoolManager } from './backend/manager/WorkerPoolManager';

const inDevelopment = process.env.NODE_ENV === "development";

let mainWindow: BrowserWindow | null = null;
let isInitialLaunch = true;

function createWindow() {
    const preload = path.join(__dirname, "preload.js");
    
    // Get the primary display's dimensions
    const primaryDisplay = screen.getPrimaryDisplay();
    const { width: displayWidth, height: displayHeight } = primaryDisplay.workAreaSize;
    
    // Calculate window dimensions
    const windowHeight = Math.round(displayHeight * 0.95);
    const windowWidth = Math.round(windowHeight * 1.5);

    mainWindow = new BrowserWindow({
        width: windowWidth,
        height: windowHeight,
        minWidth: 800,
        minHeight: 640,
        center: true,
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
        mainWindow.loadURL(MAIN_WINDOW_VITE_DEV_SERVER_URL)
          .then(() => clearLocalStorage(mainWindow));
    } else {
        mainWindow.loadFile(
            path.join(__dirname, `../renderer/${MAIN_WINDOW_VITE_NAME}/index.html`)
        ).then(() => clearLocalStorage(mainWindow));
    }

    // Handle window close cleanup
    mainWindow.on('close', (event) => {
        event.preventDefault();
        mainWindow.webContents.executeJavaScript(`
            localStorage.removeItem('dashboardCards');
            localStorage.removeItem('dashboardNextId');
            localStorage.removeItem('dashboardWires');
        `).then(() => {
            isInitialLaunch = true; // Reset for next launch
            mainWindow.destroy();
        });
    });
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
    console.log('Starting Python conversion process...');
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
      console.error('Python path not found:', pythonPath);
      return {
        success: false,
        error: 'Python environment not properly configured'
      };
    }

    const timeout = setTimeout(() => {
      console.error('Conversion timeout after 15 minutes');
      reject(new Error('Conversion timeout - file might be too large'));
    }, 15 * 60 * 1000);
    
    console.log('Running Python script...');
    const pyshell = new PythonShell(scriptPath, {
      args: [filePath],
      mode: 'text',
      pythonPath: pythonPath,
      pythonOptions: ['-u']
    });

    let finalResult = '';
    
    pyshell.on('message', (message) => {
      if (message.startsWith('{')) {
        // This is our final JSON result
        finalResult = message;
      } else {
        // This is a progress message
        console.log('Python progress:', message);
      }
    });

    pyshell.end((err) => {
      clearTimeout(timeout);
      if (err) {
        console.error('Python conversion error:', err);
        reject(err);
      } else {
        try {
          const result = JSON.parse(finalResult);
          console.log('Python conversion completed');
          resolve(result);
        } catch (parseError) {
          reject(new Error('Failed to parse Python output'));
        }
      }
    });
  });
}

// Add this with other IPC handlers
ipcMain.handle('execute-python', async (_event, code) => {
  try {
    const scriptPath = path.join(os.tmpdir(), `temp-${Date.now()}.py`);
    await fs.promises.writeFile(scriptPath, code);
    
    const pythonPath = path.join(
      process.cwd(), 
      'bundled-python', 
      'envs', 
      'occ',
      os.platform() === 'win32' 
        ? 'python.exe' 
        : path.join('bin', 'python')
    );

    return new Promise((resolve, reject) => {
      const process = new PythonShell(scriptPath, {
        pythonPath,
        mode: 'text'
      });

      let stdout = [];
      let stderr = [];

      process.on('message', (message) => {
        stdout.push(message);
      });

      process.on('stderr', (message) => {
        stderr.push(message);
      });

      process.end((err) => {
        // Clean up temp file
        fs.unlink(scriptPath, () => {});

        if (err) {
          reject({
            success: false,
            error: stderr.join('\n') || err.message
          });
        } else {
          resolve({
            success: true,
            stdout: stdout.join('\n'),
            result: stdout[stdout.length - 1] // Last line as result
          });
        }
      });
    });
  } catch (error) {
    return {
      success: false,
      error: error.message
    };
  }
});

function clearLocalStorage(mainWindow: BrowserWindow) {
  if (!isInitialLaunch) return;
  
  mainWindow.webContents.executeJavaScript(`
    localStorage.removeItem('dashboardCards');
    localStorage.removeItem('dashboardNextId');
    localStorage.removeItem('dashboardWires');
  `).then(() => {
    isInitialLaunch = false;
  });
}

ipcMain.handle('get-project-root', () => {
  return process.cwd();
});

ipcMain.handle('init-worker-pool', async () => {
  // Initialize worker pool when needed
  return { success: true };
});

ipcMain.handle('terminate-worker-pool', async () => {
  // Cleanup worker pool
  return { success: true };
});

// Add these handlers
ipcMain.handle('process-chunk', async (_event, { chunk, chunkIndex }) => {
  try {
    const workerPool = WorkerPoolManager.getInstance();
    const result = await workerPool.processChunk(chunk, chunkIndex);
    return result;
  } catch (error) {
    console.error('Chunk processing error:', error);
    return {
      success: false,
      error: error instanceof Error ? error.message : String(error)
    };
  }
});
