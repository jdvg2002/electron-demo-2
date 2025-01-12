import { exec } from 'child_process';
import path from 'path';
import fs from 'fs';
import os from 'os';

const pythonDir = path.join(process.cwd(), 'bundled-python');
const isWindows = os.platform() === 'win32';
const isMacArm = process.platform === 'darwin' && process.arch === 'arm64';

async function bundlePython() {
    if (!fs.existsSync(pythonDir)) {
        console.log('Downloading and installing miniconda...');
        const condaInstaller = isWindows 
            ? 'Miniconda3-latest-Windows-x86_64.exe' 
            : isMacArm
                ? 'Miniconda3-latest-MacOSX-arm64.sh'
                : process.platform === 'darwin'
                    ? 'Miniconda3-latest-MacOSX-x86_64.sh'
                    : 'Miniconda3-latest-Linux-x86_64.sh';
        
        const installerUrl = `https://repo.anaconda.com/miniconda/${condaInstaller}`;
        
        await execCommand(`curl -L ${installerUrl} -o miniconda-installer${isWindows ? '.exe' : '.sh'}`);
        
        if (isWindows) {
            await execCommand(`start /wait "" miniconda-installer.exe /S /D=${pythonDir}`);
        } else {
            await execCommand(`bash miniconda-installer.sh -b -p "${pythonDir}"`);
        }
        
        console.log('Installing dependencies...');
        const conda = path.join(pythonDir, isWindows ? 'Scripts' : 'bin', isWindows ? 'conda.exe' : 'conda');
        
        // Initialize conda
        await execCommand(`"${conda}" init`);
        
        console.log('Creating conda environment...');
        await execCommand(`"${conda}" create -y -n occ python=3.9`);
        
        console.log('Installing packages...');
        const activatePath = path.join(pythonDir, isWindows ? 'Scripts' : 'bin', isWindows ? 'activate.bat' : 'activate');
        
        // Verify environment creation
        const envPath = path.join(pythonDir, 'envs', 'occ');
        if (!fs.existsSync(envPath)) {
            throw new Error(`Failed to create conda environment at ${envPath}`);
        }
        
        console.log('Environment created at:', envPath);
        
        // Install packages using conda with specific channel order
        await execCommand(`"${conda}" config --add channels conda-forge`);
        await execCommand(`"${conda}" config --set channel_priority strict`);
        
        // Activate environment and install pythonocc-core
        if (isWindows) {
            await execCommand(`"${activatePath}" occ && "${conda}" install -y pythonocc-core`);
        } else {
            await execCommand(`source "${activatePath}" occ && "${conda}" install -y pythonocc-core`);
        }
        
        // Verify python executable
        const pythonExe = path.join(envPath, isWindows ? 'python.exe' : 'bin/python');
        if (!fs.existsSync(pythonExe)) {
            throw new Error(`Python executable not found at ${pythonExe}`);
        }
        
        console.log('Python executable found at:', pythonExe);
        
        // Clean up installer
        fs.unlinkSync(isWindows ? 'miniconda-installer.exe' : 'miniconda-installer.sh');
    }
}

function execCommand(command: string): Promise<void> {
    return new Promise((resolve, reject) => {
        exec(command, (error, stdout, stderr) => {
            if (error) {
                console.error(`Error: ${error}`);
                console.error(`stderr: ${stderr}`);
                reject(error);
                return;
            }
            console.log(`stdout: ${stdout}`);
            resolve();
        });
    });
}

bundlePython().catch(console.error); 