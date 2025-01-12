import React, { useState } from 'react';
import { cells } from '@/data/nuclearData';
import NotebookCell from '@/components/nuclear/NotebookCell';

interface DemoProps {
  className?: string;
}

const Demo = ({ className = '' }: DemoProps) => {
  const [activeCells, setActiveCells] = useState<number[]>([]);

  return (
    <div className={`max-w-6xl mx-auto p-6 ${className}`}>
      {/* Header */}
      <div className="mb-6">
        <h1 className="text-2xl font-bold mb-2">Nuclear Safety Analysis Notebook</h1>
        <p className="text-gray-600">Interactive workflow for nuclear reactor safety calculations</p>
      </div>

      {/* Cells */}
      <div className="space-y-4">
        {cells.map((cell) => (
          <NotebookCell 
            key={cell.id} 
            cell={cell}
            isActive={activeCells.includes(cell.id)}
            onToggle={() => {
              setActiveCells(prev => 
                prev.includes(cell.id) 
                  ? prev.filter(id => id !== cell.id)
                  : [...prev, cell.id]
              );
            }}
          />
        ))}
      </div>

      {/* Add Cell Button */}
      <div className="mt-6 flex justify-end">
        <button 
          onClick={() => {/* Add cell logic */}} 
          className="bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600 transition-colors"
        >
          Add Cell
        </button>
      </div>
    </div>
  );
};

// For use in Astro files:
// ---
// import Demo from '../components/nuclear/Demo';
// ---
// <Demo client:load />

export default Demo;