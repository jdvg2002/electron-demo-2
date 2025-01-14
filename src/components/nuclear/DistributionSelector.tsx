import React, { useState } from 'react';
import { Card } from '@/components/ui/card';
import { DistributionChart } from '../charts/ReactorCharts';

interface DistributionSelectorProps {
  value?: number;
  currentStdDev?: number;
  onAdd: (mean: number, stdDev: number, name?: string) => void;
  onClose: () => void;
  isUpdating?: boolean;
  showNameInput?: boolean;
  allowMeanEdit?: boolean;
}

export const DistributionSelector: React.FC<DistributionSelectorProps> = ({
  value = 0,
  currentStdDev,
  onAdd,
  onClose,
  isUpdating = false,
  showNameInput = false,
  allowMeanEdit = false
}) => {
  const [mean, setMean] = useState(value);
  const [stdDev, setStdDev] = useState(() => {
    if (currentStdDev) return currentStdDev;
    const defaultStdDev = value * 0.05;
    const magnitude = Math.floor(Math.log10(Math.abs(defaultStdDev) || 1));
    return Number((Math.round(defaultStdDev / Math.pow(10, magnitude - 1)) * Math.pow(10, magnitude - 1)).toFixed(10));
  });
  const [name, setName] = useState('');
  const [error, setError] = useState<string | null>(null);

  const handleStdDevChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const newValue = e.target.value;
    
    if (newValue === '') {
      setStdDev(0);
      setError('Standard deviation cannot be empty');
      return;
    }

    const numValue = Number(newValue);
    if (isNaN(numValue)) {
      setError('Please enter a valid number');
      return;
    }

    if (numValue <= 0) {
      setError('Standard deviation must be greater than 0');
      return;
    }

    setStdDev(numValue);
    setError(null);
  };

  const handleMeanChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const numValue = Number(e.target.value);
    if (!isNaN(numValue)) {
      setMean(numValue);
    }
  };

  return (
    <div className="fixed inset-0 bg-black/30 flex items-center justify-center z-50">
      <Card className="w-96 p-4 space-y-4 bg-white">
        <h3 className="font-semibold text-lg">
          {isUpdating ? 'Update' : 'Add'} Uncertainty Distribution
        </h3>
        
        <div className="space-y-4">
          {showNameInput && (
            <div>
              <label className="block text-sm font-medium mb-1">Distribution Name</label>
              <input
                type="text"
                value={name}
                onChange={(e) => setName(e.target.value)}
                className="w-full p-2 border rounded"
                placeholder="Enter distribution name"
                required
              />
            </div>
          )}

          <div>
            <label className="block text-sm font-medium mb-1">Mean (μ)</label>
            <input
              type="number"
              value={mean}
              onChange={handleMeanChange}
              disabled={!allowMeanEdit && value !== undefined}
              className={`w-full p-2 border rounded ${!allowMeanEdit && value !== undefined ? 'bg-gray-100' : ''}`}
            />
          </div>
          
          <div>
            <label className="block text-sm font-medium mb-1">Standard Deviation (σ)</label>
            <input
              type="number"
              value={stdDev || ''}
              onChange={handleStdDevChange}
              className={`w-full p-2 border rounded ${error ? 'border-red-500' : ''}`}
              min="0"
              step="any"
            />
            {error && <p className="text-red-500 text-sm mt-1">{error}</p>}
          </div>

          <div className="h-40">
            <DistributionChart
              mean={mean}
              stdDev={stdDev || mean * 0.05}
              type="normal"
              data={[]}
              className="w-full h-full"
            />
          </div>

          <div className="flex justify-end gap-2">
            <button
              onClick={onClose}
              className="px-4 py-2 text-gray-600 hover:bg-gray-100 rounded"
            >
              Cancel
            </button>
            <button
              onClick={() => {
                if (!error && stdDev > 0 && (!showNameInput || name.trim())) {
                  onAdd(mean, stdDev, showNameInput ? name : undefined);
                  onClose();
                }
              }}
              disabled={!!error || stdDev <= 0 || (showNameInput && !name.trim())}
              className={`px-4 py-2 rounded ${
                error || stdDev <= 0 || (showNameInput && !name.trim())
                  ? 'bg-gray-300 cursor-not-allowed'
                  : 'bg-blue-500 hover:bg-blue-600 text-white'
              }`}
            >
              {isUpdating ? 'Update Distribution' : 'Add Distribution'}
            </button>
          </div>
        </div>
      </Card>
    </div>
  );
}; 