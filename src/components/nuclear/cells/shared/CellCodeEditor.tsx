import React from 'react';
import CodeBlock from '../../CodeBlock';

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
  return (
    <CodeBlock 
      code={code}
      language="python"
      showCopy={true}
      onChange={(value) => value !== undefined && onChange(value)}
      readOnly={readOnly}
    />
  );
};

export default CellCodeEditor; 