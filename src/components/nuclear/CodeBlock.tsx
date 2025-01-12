import { Editor } from '@monaco-editor/react';
import React, { useState } from 'react';
import { Copy, Check } from 'lucide-react';

interface CodeBlockProps {
  code: string;
  language?: string;
  className?: string;
  showCopy?: boolean;
  onChange?: (value: string | undefined) => void;
  readOnly?: boolean;
}

const CodeBlock = ({ 
  code, 
  language = 'python',
  className = '',
  showCopy = true,
  onChange,
  readOnly = false
}: CodeBlockProps) => {
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
        {showCopy && (
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
        )}
        <Editor
          height="200px"
          defaultValue={code}
          language={language}
          theme="vs-light"
          options={{
            minimap: { enabled: false },
            lineNumbers: 'on',
            readOnly: readOnly,
            scrollBeyondLastLine: false,
            fontSize: 14,
            tabSize: 2,
            automaticLayout: true,
          }}
          onChange={onChange}
        />
      </div>
    </div>
  );
};

export default CodeBlock;