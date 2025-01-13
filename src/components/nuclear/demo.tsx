import React, { useState } from 'react';
import NotebookCell from '@/components/nuclear/NotebookCell';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { CellData } from '@/backend/models/Cell';
import { Module } from '@/backend/models/Module';

interface DemoProps {
  className?: string;
  cardId?: number;
}

const Demo = ({ className = '', cardId }: DemoProps) => {
  const manager = ModuleManager.getInstance();
  const [activeCells, setActiveCells] = useState<number[]>([]);

  let moduleObj: Module | undefined;
  if (cardId) {
    moduleObj = manager.getModuleById(cardId);
  }

  const defaultCells: CellData[] = [
    {
      id: parseInt(cardId || '0') * 3 + 1,
      type: 'preprocessing',
      title: 'Input Preprocessing',
      code: 'import numpy as np\n\n# Process reactor data\ndef process_data(input):\n    return np.mean(input)',
      output: {
        visualizations: [
          {
            title: 'Temperature Distribution',
            description: 'Distribution of normalized temperature values',
            type: 'temperature'
          },
          {
            title: 'Neutron Flux Map',
            description: '2D visualization of neutron flux distribution',
            type: 'flux'
          }
        ],
        file: {
          name: 'preprocessed_reactor_data.inp',
          size: '2.4 MB',
          format: 'INP',
          timestamp: new Date().toISOString()
        }
      }
    },
    {
      id: parseInt(cardId || '0') * 3 + 2,
      type: 'external',
      title: 'External Tool Execution',
      status: 'ready',
      tool: 'REACTOR_SIM_V2.1',
      input: {
        file: 'preprocessed_reactor_data.inp',
        status: 'validated',
        checksum: 'sha256:8f4e9b...'
      },
      output: {}
    },
    {
      id: parseInt(cardId || '0') * 3 + 3,
      type: 'postprocessing',
      title: 'Output Analysis',
      code: 'import pandas as pd\n\n# Analyze results\ndef analyze_results(data):\n    return pd.DataFrame(data).describe()',
      output: {
        visualizations: [
          {
            title: 'Thermal Safety Margins',
            description: 'Core temperature distribution relative to safety limits',
            type: 'safety'
          },
          {
            title: 'Coolant Flow Status',
            description: 'Coolant flow rates and temperature gradients',
            type: 'coolant'
          }
        ],
        file: {
          name: 'safety_analysis_report.pdf',
          size: '4.2 MB',
          format: 'PDF',
          timestamp: new Date().toISOString()
        },
        summary: {
          status: 'PASS',
          key_metrics: [
            { label: 'Peak Temperature Margin', value: '42.3°C', status: 'safe' },
            { label: 'Max Neutron Flux', value: '2.4E15 n/cm²·s', status: 'safe' },
            { label: 'Min Coolant Flow', value: '103.2 kg/s', status: 'warning' },
            { label: 'Overall Safety Rating', value: 'A-', status: 'safe' }
          ]
        }
      }
    }
  ];

  if (!moduleObj && cardId) {
    const parsedId = parseInt(cardId, 10);
    moduleObj = manager.createModule(
      {
        id: parsedId,
        x: 100,
        y: 100,
        isDragging: false,
        dragOffset: { x: 0, y: 0 },
        title: `Card ${parsedId}`,
        content: 'New module created automatically!'
      },
      defaultCells
    );
  }

  if (moduleObj && moduleObj.cells.length === 0) {
    moduleObj.setCells(defaultCells);
    manager.updateModuleCells(moduleObj.card.id, defaultCells);
  }

  if (!moduleObj) {
    return (
      <div className={`max-w-6xl mx-auto p-6 ${className}`}>
        <h1 className="text-2xl font-bold mb-2">Nuclear Safety Analysis Notebook</h1>
        <p className="text-gray-600">No valid module found. Please go to the Dashboard and create or select a card.</p>
      </div>
    );
  }

  const filteredCells = moduleObj.cells;

  function handleCellChange(updatedCell: CellData) {
    moduleObj?.updateCell(updatedCell);

    if (moduleObj) {
      manager.updateModuleCells(moduleObj.card.id, moduleObj.cells);
    }
  }

  return (
    <div className={`max-w-6xl mx-auto p-6 ${className}`}>
      <div className="mb-6">
        <h1 className="text-2xl font-bold mb-2">
          {cardId ? `Card ${cardId} Analysis` : 'Nuclear Safety Analysis Notebook'}
        </h1>
        <p className="text-gray-600">
          Interactive workflow for nuclear reactor safety calculations
        </p>
      </div>

      <div className="space-y-4">
        {filteredCells.map(cell => (
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
            onCellChange={handleCellChange}
          />
        ))}
      </div>

      <div className="mt-6 flex justify-end">
        <button
          onClick={() => {
            const newId = Math.max(...moduleObj!.cells.map(c => c.id)) + 1;
            const newCell: CellData = {
              id: newId,
              type: 'preprocessing',
              title: 'New Cell',
              code: '# Placeholder code',
              output: {}
            };
            moduleObj?.setCells([...moduleObj.cells, newCell]);
            manager.updateModuleCells(moduleObj.card.id, moduleObj.cells);
          }}
          className="bg-blue-500 text-white px-4 py-2 rounded hover:bg-blue-600 transition-colors"
        >
          Add Cell
        </button>
      </div>
    </div>
  );
};

export default Demo;