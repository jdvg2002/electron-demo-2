import React, { useState } from 'react';
import { cells } from '@/data/nuclearData';
import NotebookCell from '@/components/nuclear/NotebookCell';
import { useParams } from '@tanstack/react-router';

const Demo = ({ className = '' }: { className?: string }) => {
  const { cardId } = useParams({ from: '/demo/$cardId' });
  const [activeCells, setActiveCells] = useState<number[]>([]);

  // Create fully populated cells for each card
  const defaultCells = [
    {
      id: parseInt(cardId || '0') * 3 + 1,
      type: 'preprocessing' as const,
      title: 'Input Preprocessing',
      code: 'import numpy as np\n\n# Process reactor data\ndef process_data(input):\n    return np.mean(input)',
      output: {
        visualizations: [
          {
            title: "Temperature Distribution",
            description: "Distribution of normalized temperature values",
            type: "temperature"
          },
          {
            title: "Neutron Flux Map",
            description: "2D visualization of neutron flux distribution",
            type: "flux"
          }
        ],
        file: {
          name: "preprocessed_reactor_data.inp",
          size: "2.4 MB",
          format: "INP",
          timestamp: new Date().toISOString()
        }
      }
    },
    {
      id: parseInt(cardId || '0') * 3 + 2,
      type: 'external' as const,
      title: 'External Tool Execution',
      status: 'ready',
      tool: 'REACTOR_SIM_V2.1',
      input: {
        file: "preprocessed_reactor_data.inp",
        status: 'validated',
        checksum: "sha256:8f4e9b..."
      }
    },
    {
      id: parseInt(cardId || '0') * 3 + 3,
      type: 'postprocessing' as const,
      title: 'Output Analysis',
      code: 'import pandas as pd\n\n# Analyze results\ndef analyze_results(data):\n    return pd.DataFrame(data).describe()',
      output: {
        visualizations: [
          {
            title: "Thermal Safety Margins",
            description: "Core temperature distribution relative to safety limits",
            type: "safety"
          },
          {
            title: "Coolant Flow Status",
            description: "Coolant flow rates and temperature gradients",
            type: "coolant"
          }
        ],
        file: {
          name: "safety_analysis_report.pdf",
          size: "4.2 MB",
          format: "PDF",
          timestamp: new Date().toISOString()
        },
        summary: {
          status: "PASS",
          key_metrics: [
            { label: "Peak Temperature Margin", value: "42.3°C", status: "safe" },
            { label: "Max Neutron Flux", value: "2.4E15 n/cm²·s", status: "safe" },
            { label: "Min Coolant Flow", value: "103.2 kg/s", status: "warning" },
            { label: "Overall Safety Rating", value: "A-", status: "safe" }
          ]
        }
      }
    }
  ];

  // Use default cells instead of filtering from cells array
  const filteredCells = cardId ? defaultCells : cells;

  return (
    <div className={`max-w-6xl mx-auto p-6 ${className}`}>
      {/* Header */}
      <div className="mb-6">
        <h1 className="text-2xl font-bold mb-2">
          {cardId ? `Card ${cardId} Analysis` : 'Nuclear Safety Analysis Notebook'}
        </h1>
        <p className="text-gray-600">Interactive workflow for nuclear reactor safety calculations</p>
      </div>

      {/* Cells */}
      <div className="space-y-4">
        {filteredCells.map((cell) => (
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

export default Demo;