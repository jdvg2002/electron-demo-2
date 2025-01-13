interface Window {
  electronWindow: {
    executePython: (code: string) => Promise<{
      success: boolean;
      stdout?: string;
      result?: string;
      error?: string;
    }>;
    // ... other methods
  };
} 