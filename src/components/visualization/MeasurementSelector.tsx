import React, { useState } from 'react';
import { Card } from '@/components/ui/card';

export interface MeasurementSelectorProps {
  onAdd: (name: string, value: number) => void;
  onClose: () => void;
}

export const MeasurementSelector: React.FC<MeasurementSelectorProps> = ({
  onAdd,
  onClose,
}) => {
  const [name, setName] = useState('');
  const [value, setValue] = useState<string>('0');
  const [error, setError] = useState<string | null>(null);

  const handleValueChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const newValue = e.target.value;
    setValue(newValue);
    
    const numValue = Number(newValue);
    if (newValue === '' || isNaN(numValue)) {
      setError('Please enter a valid number');
    } else if (numValue <= 0) {
      setError('Value must be greater than 0');
    } else {
      setError(null);
    }
  };

  return (
    <div className="fixed inset-0 bg-black/30 flex items-center justify-center z-50">
      <Card className="w-96 p-4 space-y-4 bg-white">
        <h3 className="font-semibold text-lg">Add Measurement</h3>
        
        <div className="space-y-4">
          <div>
            <label className="block text-sm font-medium mb-1">Measurement Name</label>
            <input
              type="text"
              value={name}
              onChange={(e) => setName(e.target.value)}
              className="w-full p-2 border rounded"
              placeholder="Enter measurement name"
            />
          </div>

          <div>
            <label className="block text-sm font-medium mb-1">Value (mm)</label>
            <input
              type="number"
              value={value}
              onChange={handleValueChange}
              className={`w-full p-2 border rounded ${error ? 'border-red-500' : ''}`}
              step="any"
            />
            {error && <p className="text-red-500 text-sm mt-1">{error}</p>}
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
                const numValue = Number(value);
                if (!error && numValue > 0 && name.trim()) {
                  onAdd(name.trim(), numValue);
                  onClose();
                }
              }}
              disabled={!!error || Number(value) <= 0 || !name.trim()}
              className={`px-4 py-2 rounded ${
                error || Number(value) <= 0 || !name.trim()
                  ? 'bg-gray-300 cursor-not-allowed'
                  : 'bg-blue-500 hover:bg-blue-600 text-white'
              }`}
            >
              Add Measurement
            </button>
          </div>
        </div>
      </Card>
    </div>
  );
};
