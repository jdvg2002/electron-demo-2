import React, { useState } from 'react';
import { Editor } from '@monaco-editor/react';
import { Copy, Check, Play } from 'lucide-react';

interface CodeEditorProps {
  code: string;
  onChange: (code: string) => void;
  className?: string;
}

export const CodeEditor: React.FC<CodeEditorProps> = ({
  code,
  onChange,
  className = ''
}) => {
  const [copied, setCopied] = useState(false);
  const [isRunning, setIsRunning] = useState(false);
  const [runOutput, setRunOutput] = useState<string | null>(null);
  const [runError, setRunError] = useState<string | null>(null);

  const handleCopy = async () => {
    try {
      await navigator.clipboard.writeText(code);
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    } catch (err) {
      console.error('Failed to copy code:', err);
    }
  };

  // Updated function to run Python code via Electron IPC
  // leveraging window.electronWindow instead of window.electronAPI
  const handleRun = async () => {
    try {
      setIsRunning(true);
      setRunOutput(null);
      setRunError(null);

      // Updated to use contextBridge-exposed "electronWindow"
      if (window?.electronWindow?.executePython) {
        const result = await window.electronWindow.executePython(code);
        if (result.success) {
          setRunOutput(result.stdout || 'No output');
          setRunError(null);
        } else {
          setRunError(result.error || 'Unknown error');
        }
      } else {
        throw new Error('window.electronWindow not available');
      }
    } catch (err: any) {
      console.error('Failed to run code:', err);
      setRunError(err.message);
    } finally {
      setIsRunning(false);
    }
  };

  return (
    <div className={`relative group ${className}`}>
      <div className="bg-gray-50 rounded-md font-mono text-sm overflow-hidden">
        <div className="flex items-center justify-end p-2">
          <button
            onClick={handleCopy}
            className="mr-2 px-2 py-1 rounded-md bg-white/80 
                     opacity-0 group-hover:opacity-100 transition-opacity
                     hover:bg-gray-100"
            aria-label={copied ? 'Copied!' : 'Copy code'}
          >
            {copied ? (
              <Check className="w-4 h-4 text-green-500" />
            ) : (
              <Copy className="w-4 h-4 text-gray-500" />
            )}
          </button>
          {/* Run button remains the same */}
          <button
            onClick={handleRun}
            className={`px-2 py-1 rounded-md bg-white/80 
                       opacity-0 group-hover:opacity-100 transition-opacity
                       hover:bg-gray-100 ${isRunning ? 'cursor-not-allowed' : ''}`}
            disabled={isRunning}
            aria-label="Run code"
          >
            <Play className="w-4 h-4 text-blue-500" />
          </button>
        </div>

        <Editor
          height={Math.min(Math.max(code.split('\n').length * 22, 50), 400) + 'px'}
          value={code}
          language="python"
          theme="vs-light"
          options={{
            minimap: { enabled: false },
            lineNumbers: 'on',
            scrollBeyondLastLine: false,
            fontSize: 14,
            tabSize: 2,
            automaticLayout: true,
          }}
          onChange={(value) => {
            if (value !== undefined) {
              onChange(value);
            }
          }}
        />
      </div>

      {/* Show run output if present */}
      {runOutput && (
        <div className="mt-2 p-2 bg-green-100 text-green-900 rounded">
          <strong>Output:</strong>
          <pre className="whitespace-pre-wrap">{runOutput}</pre>
        </div>
      )}
      {/* Show run error if present */}
      {runError && (
        <div className="mt-2 p-2 bg-red-100 text-red-900 rounded">
          <strong>Error:</strong>
          <pre className="whitespace-pre-wrap">{runError}</pre>
        </div>
      )}
    </div>
  );
}; 