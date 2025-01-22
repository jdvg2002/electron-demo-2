export interface FileRecord {
    id: string;
    type: string;
    version: string;
    timestamp: string;
    originalFileName: string;
    sourceEnvironment: string;
    data?: any;
  }