import { Worker } from 'worker_threads';
import { cpus } from 'os';

export interface WorkerPoolTask {
  chunk: ArrayBuffer;
  chunkIndex: number;
}

export class WorkerPool {
  private workers: Worker[] = [];
  private queue: WorkerPoolTask[] = [];
  private readonly maxWorkers: number;
  private busy: boolean[] = [];

  constructor(workerScript: string, maxWorkers = cpus().length - 1) {
    this.maxWorkers = maxWorkers;
    for (let i = 0; i < this.maxWorkers; i++) {
      this.workers[i] = new Worker(workerScript);
      this.busy[i] = false;
    }
  }

  async processChunk(task: WorkerPoolTask): Promise<any> {
    return new Promise((resolve, reject) => {
      const availableWorker = this.workers.findIndex((_, index) => !this.busy[index]);
      
      if (availableWorker === -1) {
        this.queue.push(task);
        return;
      }

      this.runWorker(availableWorker, task, resolve, reject);
    });
  }

  private async runWorker(
    workerIndex: number, 
    task: WorkerPoolTask,
    resolve: (value: any) => void,
    reject: (reason: any) => void
  ) {
    this.busy[workerIndex] = true;
    
    try {
      const worker = this.workers[workerIndex];
      
      worker.once('message', (result) => {
        this.busy[workerIndex] = false;
        resolve(result);
        
        if (this.queue.length > 0) {
          const nextTask = this.queue.shift()!;
          this.runWorker(workerIndex, nextTask, resolve, reject);
        }
      });

      worker.once('error', (error) => {
        this.busy[workerIndex] = false;
        reject(error);
      });

      worker.postMessage(task);
    } catch (error) {
      this.busy[workerIndex] = false;
      reject(error);
    }
  }

  terminate() {
    this.workers.forEach(worker => worker.terminate());
  }
} 