import React, { useState } from 'react';
import { Editor } from '@monaco-editor/react';
import { Copy, Check } from 'lucide-react';

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

  const handleCopy = async () => {
    try {
      await navigator.clipboard.writeText(code);
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    } catch (err) {
      console.error('Failed to copy code:', err);
    }
  };

  return (
    <div className={`relative group ${className}`}>
      <div className="bg-gray-50 rounded-md font-mono text-sm overflow-hidden">
        <button
          onClick={handleCopy}
          className="absolute top-2 right-2 p-2 z-10 rounded-md bg-white/80 
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

        <Editor
          height="200px"
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
    </div>
  );
}; 