import React, { useState } from 'react';
import CodeBlock from './CodeBlock';

interface CellCodeEditorProps {
  code: string;
  onChange: (value: string) => void;
  readOnly?: boolean;
}

/**
 * Shared code editor component used across different cell types
 */
const CellCodeEditor: React.FC<CellCodeEditorProps> = ({
  code,
  onChange,
  readOnly = false
}) => {
  const [isDraggingOver, setIsDraggingOver] = useState(false);

  const handleDrop = (e: React.DragEvent) => {
    e.preventDefault();
    setIsDraggingOver(false);
    const data = e.dataTransfer.getData('application/json');
    if (!data) return;

    try {
      const dropData = JSON.parse(data);
      let snippet = '';

      switch (dropData.type) {
        case 'measurement':
          snippet = `${dropData.label} = ${dropData.value}`;
          break;
        case 'distribution':
          snippet = `${dropData.label} (mean=${dropData.mean}, stdDev=${dropData.stdDev})`;
          break;
        default:
          return;
      }

      // Insert at the end for now
      const newCode = code + snippet;
      onChange(newCode);
    } catch (err) {
      console.error('Invalid drop data:', err);
    }
  };

  const handleDragOver = (e: React.DragEvent) => {
    e.preventDefault();
    setIsDraggingOver(true);
  };

  const handleDragLeave = (e: React.DragEvent) => {
    e.preventDefault();
    setIsDraggingOver(false);
  };

  return (
    <div 
      onDrop={handleDrop}
      onDragOver={handleDragOver}
      onDragLeave={handleDragLeave}
      className={`relative ${isDraggingOver ? 'ring-2 ring-blue-400 ring-opacity-50' : ''}`}
    >
      <CodeBlock 
        code={code}
        language="python"
        showCopy={true}
        onChange={(value) => value !== undefined && onChange(value)}
        readOnly={readOnly}
      />
      {isDraggingOver && (
        <div className="absolute inset-0 bg-blue-100 bg-opacity-20 pointer-events-none" />
      )}
    </div>
  );
};

export default CellCodeEditor; 