import { Worker } from 'worker_threads';
import { cpus } from 'os';
import path from 'path';
import fs from 'fs';

export class WorkerPoolManager {
  private workers: Worker[] = [];
  private queue: any[] = [];
  private busy: boolean[] = [];
  private static instance: WorkerPoolManager;

  private constructor() {
    const maxWorkers = cpus().length - 1;
    const workerScript = this.findWorkerScript();
    
    if (!workerScript) {
      throw new Error('Worker script not found');
    }
    
    for (let i = 0; i < maxWorkers; i++) {
      this.workers[i] = new Worker(workerScript);
      this.busy[i] = false;
    }
  }

  private findWorkerScript(): string | null {
    const possiblePaths = [
      // Development path
      path.join(process.cwd(), 'src', 'backend', 'workers', 'stepChunkWorker.ts'),
      // Production path
      path.join(process.cwd(), 'dist', 'backend', 'workers', 'stepChunkWorker.js')
    ];

    for (const scriptPath of possiblePaths) {
      if (fs.existsSync(scriptPath)) {
        console.log('Found worker script at:', scriptPath);
        return scriptPath;
      }
    }

    console.error('Worker script not found in paths:', possiblePaths);
    return null;
  }

  static getInstance(): WorkerPoolManager {
    if (!WorkerPoolManager.instance) {
      WorkerPoolManager.instance = new WorkerPoolManager();
    }
    return WorkerPoolManager.instance;
  }

  async processChunk(chunk: ArrayBuffer, chunkIndex: number): Promise<any> {
    console.log(`WorkerPoolManager processing chunk ${chunkIndex}, size: ${chunk.byteLength}`);
    return new Promise((resolve, reject) => {
      const availableWorker = this.workers.findIndex((_, index) => !this.busy[index]);
      
      if (availableWorker === -1) {
        console.log(`No workers available, queueing chunk ${chunkIndex}`);
        this.queue.push({ data: { chunk, chunkIndex }, resolve, reject });
        return;
      }

      console.log(`Assigning chunk ${chunkIndex} to worker ${availableWorker}`);
      this.runWorker(availableWorker, { chunk, chunkIndex }, resolve, reject);
    });
  }

  private runWorker(workerIndex: number, task: any, resolve: Function, reject: Function) {
    this.busy[workerIndex] = true;
    const worker = this.workers[workerIndex];
    console.log(`Worker ${workerIndex} starting task for chunk ${task.chunkIndex}`);

    worker.once('message', (result) => {
      console.log(`Worker ${workerIndex} completed chunk ${task.chunkIndex}`);
      this.busy[workerIndex] = false;
      resolve(result);
      
      if (this.queue.length > 0) {
        const nextTask = this.queue.shift()!;
        console.log(`Worker ${workerIndex} taking next task from queue (${this.queue.length} remaining)`);
        this.runWorker(workerIndex, nextTask.data, nextTask.resolve, nextTask.reject);
      }
    });

    worker.once('error', (error) => {
      console.error(`Worker ${workerIndex} error:`, error);
      this.busy[workerIndex] = false;
      reject(error);
    });

    worker.postMessage(task);
  }
} 