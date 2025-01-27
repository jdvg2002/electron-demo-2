import React, { useState, useEffect, useRef, useCallback } from 'react';
import { Editor } from '@monaco-editor/react';
import { Copy, Check, Play } from 'lucide-react';
import { GlobalManager } from '../../../backend/manager/GlobalManager';

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
  const [isDragOver, setIsDragOver] = useState(false);

  // Tracks the ranges for Python lists ([1, 2, 3], etc.)
  const [listRanges, setListRanges] = useState<{ start: number; end: number; content: string }[]>([]);

  const editorRef = useRef<any>(null);
  const decorationsRef = useRef<string[]>([]);
  const [monaco, setMonaco] = useState<any>(null);

  // --------------------------------------------------------------------------
  // 1. Code for detecting Python lists
  // --------------------------------------------------------------------------
  const detectPythonLists = (pythonCode: string) => {
    const listRegex = /\[((?:[^[\]]*|\[[^[\]]*\])*)\]/g;
    const ranges: { start: number; end: number; content: string }[] = [];
    let match;
    
    while ((match = listRegex.exec(pythonCode)) !== null) {
      if (match[1].includes(',')) {
        ranges.push({
          start: match.index,
          end: match.index + match[0].length,
          content: match[0]
        });
      }
    }
    return ranges;
  };

  // --------------------------------------------------------------------------
  // 2. Code for sorting a Python list in-place
  // --------------------------------------------------------------------------
  const handleSortList = (range: { start: number; end: number; content: string }) => {
    try {
      const listContent = range.content.slice(1, -1).split(',').map(item => item.trim());
      const sortedList = listContent.sort((a, b) => {
        const numA = Number(a);
        const numB = Number(b);
        if (!isNaN(numA) && !isNaN(numB)) return numA - numB;
        return a.localeCompare(b);
      });
      
      const newListStr = `[${sortedList.join(', ')}]`;
      const newCode =
        code.substring(0, range.start) +
        newListStr +
        code.substring(range.end);
      
      onChange(newCode);

      const newRanges = detectPythonLists(newCode);
      setListRanges(newRanges);
    } catch (error) {
      console.error('Failed to sort list:', error);
    }
  };

  // --------------------------------------------------------------------------
  // 3. Code for highlighting our list ranges (decorations in Monaco)
  // --------------------------------------------------------------------------
  const getDecorations = useCallback(
    (editor: any, monacoInstance: any) => {
      return listRanges.map(range => {
        const startPos = editor.getModel().getPositionAt(range.start);
        const endPos = editor.getModel().getPositionAt(range.end);
        
        return {
          range: new monacoInstance.Range(
            startPos.lineNumber,
            startPos.column,
            endPos.lineNumber,
            endPos.column
          ),
          options: {
            isWholeLine: false,
            className: 'bg-yellow-100 cursor-pointer',
            hoverMessage: { value: 'Click to sort list' },
            stickiness: monacoInstance.editor.TrackedRangeStickiness.NeverGrowsWhenTypingAtEdges,
            minimap: {
              color: { id: 'minimap.background' },
              position: 1
            }
          }
        };
      });
    },
    [listRanges]
  );

  const updateDecorations = useCallback(() => {
    if (editorRef.current && monaco) {
      const decorations = getDecorations(editorRef.current, monaco);
      decorationsRef.current = editorRef.current.deltaDecorations(
        decorationsRef.current,
        decorations
      );
    }
  }, [monaco, getDecorations]);

  // --------------------------------------------------------------------------
  // 4. UseEffects
  // --------------------------------------------------------------------------
  // Re-run detectPythonLists every time code changes
  useEffect(() => {
    const ranges = detectPythonLists(code);
    setListRanges(ranges);
  }, [code]);

  // Whenever listRanges update, refresh decorations
  useEffect(() => {
    updateDecorations();
  }, [listRanges, updateDecorations]);

  // Attach mouseDown listener in an effect (so we don't get a stale listRanges)
  useEffect(() => {
    if (!editorRef.current) return;
    const editor = editorRef.current;
    
    // We'll create a fresh listener each time listRanges changes. 
    // Dispose the old one before adding a new one.
    const disposable = editor.onMouseDown((e: any) => {
      if (!e.target.position) {
        return;
      }

      const position = e.target.position;
      const model = editor.getModel();
      const offset = model.getOffsetAt(position);
      
      const clickedRange = listRanges.find(range => {
        const isInRange = range.start <= offset && offset <= range.end;
        return isInRange;
      });
      
      if (clickedRange) {
        handleSortList(clickedRange);
      }
    });

    // Cleanup: remove the old event listener
    return () => {
      disposable.dispose();
    };
  }, [listRanges, code, handleSortList]);

  // --------------------------------------------------------------------------
  // 5. Editor mount callback
  // --------------------------------------------------------------------------
  const editorWillMount = (monacoInstance: any) => {
    // Define a custom theme if you like
    monacoInstance.editor.defineTheme('custom-theme', {
      base: 'vs',
      inherit: true,
      rules: [],
      colors: {}
    });
  };

  // --------------------------------------------------------------------------
  // 6. Copy, Run, and other existing logic ...
  // --------------------------------------------------------------------------
  const handleCopy = async () => {
    try {
      await navigator.clipboard.writeText(code);
      setCopied(true);
      setTimeout(() => setCopied(false), 2000);
    } catch (err) {
      console.error('Failed to copy code:', err);
    }
  };

  const handleRun = async () => {
    try {
      setIsRunning(true);
      setRunOutput(null);
      setRunError(null);

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

  // --------------------------------------------------------------------------
  // 7. Render
  // --------------------------------------------------------------------------
  const handleDragOver = (e: React.DragEvent<HTMLDivElement>) => {
    e.preventDefault();
    setIsDragOver(true);
  };

  const handleDragLeave = () => {
    setIsDragOver(false);
  };

  const ensureNumpyImport = (currentCode: string): string => {
    if (!currentCode.includes('import numpy')) {
      return 'import numpy as np\n\n' + currentCode;
    }
    return currentCode;
  };

  const handleDrop = async (e: React.DragEvent<HTMLDivElement>) => {
    e.preventDefault();
    setIsDragOver(false);

    try {
      const jsonData = e.dataTransfer.getData('application/json');
      
      if (jsonData) {
        const data = JSON.parse(jsonData);
        
        if (data.type === 'csv' && data.fileId) {
          const globalManager = GlobalManager.getInstance();
          const csvData = globalManager.getCSVData(data.fileId);
          
          if (csvData) {
            const variableName = data.fileName.split('.')[0].replace(/[^a-zA-Z0-9_]/g, '_').toLowerCase();
            let newCode = ensureNumpyImport(code);
            
            // Add CSV data as Python lists
            newCode += `\n# Data from ${data.fileName}\n`;
            newCode += `${variableName}_header = [${csvData.headers.map(h => `'${h}'`).join(', ')}]\n`;
            newCode += `${variableName}_data = [\n`;
            // Quote string values in the rows
            newCode += csvData.rows.map(row => 
              `    [${row.map(cell => 
                // If the cell can be parsed as a number, don't quote it
                isNaN(Number(cell)) ? `'${cell}'` : cell
              ).join(', ')}]`
            ).join(',\n');
            newCode += '\n]\n';
            newCode += `${variableName}_array = np.array(${variableName}_data)\n`;

            onChange(newCode);
            return;
          }
        }
      }
    } catch (error) {
      console.error('Failed to process dropped data:', error);
    }
  };

  return (
    <div 
      className={`relative group ${className}`}
      onDragOver={handleDragOver}
      onDragLeave={handleDragLeave}
      onDrop={handleDrop}
    >
      <div
        className={`bg-gray-50 rounded-md font-mono text-sm overflow-hidden
                    ${isDragOver ? 'ring-2 ring-blue-500' : ''}`}
      >
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
          beforeMount={editorWillMount}
          onMount={(editor, monacoInstance) => {
            editorRef.current = editor;
            setMonaco(monacoInstance);
            // Decorations will be updated in useEffect
          }}
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

      {runOutput && (
        <div className="mt-2 p-2 bg-green-100 text-green-900 rounded">
          <strong>Output:</strong>
          <pre className="whitespace-pre-wrap">{runOutput}</pre>
        </div>
      )}
      {runError && (
        <div className="mt-2 p-2 bg-red-100 text-red-900 rounded">
          <strong>Error:</strong>
          <pre className="whitespace-pre-wrap">{runError}</pre>
        </div>
      )}
    </div>
  );
};