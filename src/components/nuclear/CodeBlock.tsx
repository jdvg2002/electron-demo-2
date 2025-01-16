import { Editor, loader } from '@monaco-editor/react';
import React, { useState, useRef, useEffect } from 'react';
import { Copy, Check } from 'lucide-react';

interface CodeBlockProps {
  code: string;
  language?: string;
  className?: string;
  showCopy?: boolean;
  onChange?: (value: string | undefined) => void;
  readOnly?: boolean;
  onEditorMount?: (editor: any) => void;
}

const CodeBlock = ({ 
  code, 
  language = 'python',
  className = '',
  showCopy = true,
  onChange,
  readOnly = false,
  onEditorMount
}: CodeBlockProps) => {
  const [copied, setCopied] = useState(false);
  const editorRef = useRef<any>(null);
  const lastCursorPosition = useRef<any>(null);

  const handleCopy = async () => {
    try {
      await navigator.clipboard.writeText(code);
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    } catch (err) {
      console.error('Failed to copy code:', err);
    }
  };

  const handleEditorDidMount = (editor: any, monaco: any) => {
    editorRef.current = editor;
    
    if (onEditorMount) {
      onEditorMount(editor);
    }
    
    // Store cursor position on change
    editor.onDidChangeCursorPosition((e: any) => {
      lastCursorPosition.current = e.position;
    });

    setTimeout(() => {
      editor.layout();
    }, 100);
  };

  const updateEditorContent = (newValue: string) => {
    if (editorRef.current) {
      const editor = editorRef.current;
      const position = lastCursorPosition.current;
      
      editor.setValue(newValue);
      
      // Restore cursor position if we have one
      if (position) {
        editor.setPosition(position);
        editor.revealPositionInCenter(position);
      }
    }
  };

  useEffect(() => {
    updateEditorContent(code);
  }, [code]);

  const handleEditorWillMount = (monaco: any) => {
    // Optional: Configure Monaco instance before mounting
    monaco.editor.defineTheme('customTheme', {
      base: 'vs',
      inherit: true,
      rules: [],
      colors: {}
    });
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
          value={code}
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
          onMount={handleEditorDidMount}
          beforeMount={handleEditorWillMount}
          loading={<div className="p-4 text-gray-500">Loading editor...</div>}
        />
      </div>
    </div>
  );
};

export default CodeBlock;