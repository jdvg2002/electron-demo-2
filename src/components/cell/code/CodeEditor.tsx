import React, { useState, useEffect, useRef, useCallback } from 'react';
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
    console.log('Detecting lists in code:', pythonCode);
    const listRegex = /\[((?:[^[\]]*|\[[^[\]]*\])*)\]/g;
    const ranges: { start: number; end: number; content: string }[] = [];
    let match;
    
    while ((match = listRegex.exec(pythonCode)) !== null) {
      console.log('Found potential list match:', match[0]);
      // Only consider matches that look like Python lists (comma-separated values)
      if (match[1].includes(',')) {
        ranges.push({
          start: match.index,
          end: match.index + match[0].length,
          content: match[0]
        });
        console.log('Added range:', {
          start: match.index,
          end: match.index + match[0].length,
          content: match[0]
        });
      }
    }
    console.log('Detected ranges:', ranges);
    return ranges;
  };

  // --------------------------------------------------------------------------
  // 2. Code for sorting a Python list in-place
  // --------------------------------------------------------------------------
  const handleSortList = (range: { start: number; end: number; content: string }) => {
    try {
      console.log('Starting sort with range:', range);
      
      // Parse the list content (remove brackets and split by commas)
      const listContent = range.content.slice(1, -1).split(',').map(item => item.trim());
      console.log('Parsed list content:', listContent);
      
      // Sort numbers numerically; otherwise sort strings alphabetically
      const sortedList = listContent.sort((a, b) => {
        const numA = Number(a);
        const numB = Number(b);
        if (!isNaN(numA) && !isNaN(numB)) return numA - numB;
        return a.localeCompare(b);
      });
      console.log('Sorted list:', sortedList);
      
      const newListStr = `[${sortedList.join(', ')}]`;
      console.log('New list string:', newListStr);
      
      // Create the new code by replacing the old list with the sorted one
      const newCode =
        code.substring(0, range.start) +
        newListStr +
        code.substring(range.end);
      console.log('New complete code:', newCode);
      
      // Update the editor content
      onChange(newCode);
      console.log('Called onChange with new code');

      // Force refresh decorations for updated code
      const newRanges = detectPythonLists(newCode);
      console.log('New detected ranges:', newRanges);
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
      console.log('Creating decorations for ranges:', listRanges);
      return listRanges.map(range => {
        const startPos = editor.getModel().getPositionAt(range.start);
        const endPos = editor.getModel().getPositionAt(range.end);
        console.log('Position conversion:', {
          range,
          startPos,
          endPos
        });
        
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
    console.log('Updating decorations, editor ref:', editorRef.current);
    if (editorRef.current && monaco) {
      const decorations = getDecorations(editorRef.current, monaco);
      console.log('Created decorations:', decorations);
      decorationsRef.current = editorRef.current.deltaDecorations(
        decorationsRef.current,
        decorations
      );
      console.log('Applied decorations:', decorationsRef.current);
    }
  }, [monaco, getDecorations]);

  // --------------------------------------------------------------------------
  // 4. UseEffects
  // --------------------------------------------------------------------------
  // Re-run detectPythonLists every time code changes
  useEffect(() => {
    console.log('Code changed, detecting lists');
    const ranges = detectPythonLists(code);
    console.log('Setting list ranges:', ranges);
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
      console.log('Mouse down event:', e);
      if (!e.target.position) {
        console.log('No position in click target');
        return;
      }

      const position = e.target.position;
      const model = editor.getModel();
      const offset = model.getOffsetAt(position);
      console.log('Click position:', position, 'offset:', offset);
      console.log('Current list ranges:', listRanges);
      
      const clickedRange = listRanges.find(range => {
        const isInRange = range.start <= offset && offset <= range.end;
        console.log('Checking range:', range, 'isInRange:', isInRange);
        return isInRange;
      });
      
      console.log('Found clicked range:', clickedRange);

      if (clickedRange) {
        console.log('Handling sort for range:', clickedRange);
        handleSortList(clickedRange);
      }
    });

    // Cleanup: remove the old event listener
    return () => {
      console.log('Disposing previous mouseDown listener');
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
  const handleDragOver = (e: React.DragEvent) => {
    e.preventDefault();
  };
  const handleDragLeave = (e: React.DragEvent) => {
    e.preventDefault();
  };
  const handleDrop = (e: React.DragEvent) => {
    e.preventDefault();
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
            console.log('Editor mounted');
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