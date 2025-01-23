import React, { useState } from 'react';
import { Card } from '@/components/ui/card';
import { Ruler, BarChart2 } from 'lucide-react';

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
  const formatNumber = (num: number): string => {
    // Limit to 4 decimal places and remove trailing zeros
    return Number(num.toFixed(4)).toString();
  };

  const [mean, setMean] = useState(value);
  const [stdDev, setStdDev] = useState<string>(() => {
    if (currentStdDev) return formatNumber(currentStdDev);
    const defaultStdDev = value * 0.05;
    const magnitude = Math.floor(Math.log10(Math.abs(defaultStdDev) || 1));
    return formatNumber((Math.round(defaultStdDev / Math.pow(10, magnitude - 1)) * Math.pow(10, magnitude - 1)));
  });
  const [name, setName] = useState('');
  const [error, setError] = useState<string | null>(null);
  const [meanError, setMeanError] = useState<string | null>(null);

  const handleStdDevChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const newValue = e.target.value;
    setStdDev(newValue);
    
    const numValue = Number(newValue);
    if (newValue === '' || isNaN(numValue)) {
      setError('Please enter a valid number');
    } else if (numValue <= 0) {
      setError('Standard deviation must be greater than 0');
    } else {
      setError(null);
    }
  };

  const handleMeanChange = (e: React.ChangeEvent<HTMLInputElement>) => {
    const newValue = e.target.value;
    const numValue = Number(newValue);
    
    if (newValue === '' || isNaN(numValue)) {
      setMeanError('Please enter a valid number');
    } else {
      setMeanError(null);
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
              className={`w-full p-2 border rounded ${!allowMeanEdit && value !== undefined ? 'bg-gray-100' : ''} ${meanError ? 'border-red-500' : ''}`}
            />
            {meanError && <p className="text-red-500 text-sm mt-1">{meanError}</p>}
          </div>
          
          <div>
            <label className="block text-sm font-medium mb-1">Standard Deviation (σ)</label>
            <input
              type="number"
              value={stdDev}
              onChange={handleStdDevChange}
              className={`w-full p-2 border rounded ${error ? 'border-red-500' : ''}`}
              step="any"
            />
            {error && <p className="text-red-500 text-sm mt-1">{error}</p>}
          </div>

          <div className="h-40">
          <div className="w-full h-full">
              Distribution Chart (Mean: {mean}, StdDev: {currentStdDev || mean * 0.05})
            </div>
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
                const numStdDev = Number(stdDev);
                if (!error && !meanError && numStdDev > 0 && (!showNameInput || name.trim())) {
                  onAdd(mean, numStdDev, showNameInput ? name : undefined);
                  onClose();
                }
              }}
              disabled={!!error || !!meanError || Number(stdDev) <= 0 || (showNameInput && !name.trim())}
              className={`px-4 py-2 rounded ${
                error || meanError || Number(stdDev) <= 0 || (showNameInput && !name.trim())
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

const PlusCard = React.memo(({ 
  onCreateDistribution,
  onCreateMeasurement 
}: { 
  onCreateDistribution: (mean: number, stdDev: number, name: string) => void;
  onCreateMeasurement: (name: string, value: number) => void;
}) => {
  const [showSelector, setShowSelector] = useState(false);
  const [showDistributionSelector, setShowDistributionSelector] = useState(false);
  const [showMeasurementSelector, setShowMeasurementSelector] = useState(false);

  return (
    <>
      <Card 
        className="aspect-square p-2 w-[180px] overflow-hidden flex flex-col items-center justify-center cursor-pointer hover:bg-gray-50"
        onClick={() => setShowSelector(true)}
      >
        <div className="text-4xl text-gray-400">+</div>
        <div className="text-sm text-gray-400">Add a Variable</div>
      </Card>

      {showSelector && (
        <div className="fixed inset-0 bg-black/30 flex items-center justify-center z-50">
          <Card className="w-96 p-4 space-y-4 bg-white">
            <h3 className="font-semibold text-lg">Select Variable Type</h3>
            <div className="grid grid-cols-2 gap-4">
              <button
                onClick={() => {
                  setShowSelector(false);
                  setShowMeasurementSelector(true);
                }}
                className="p-4 border rounded hover:bg-gray-50 flex flex-col items-center gap-2"
              >
                <Ruler className="w-8 h-8 text-gray-600" />
                <span>Measurement</span>
              </button>
              <button
                onClick={() => {
                  setShowSelector(false);
                  setShowDistributionSelector(true);
                }}
                className="p-4 border rounded hover:bg-gray-50 flex flex-col items-center gap-2"
              >
                <BarChart2 className="w-8 h-8 text-gray-600" />
                <span>Distribution</span>
              </button>
            </div>
            <div className="flex justify-end">
              <button
                onClick={() => setShowSelector(false)}
                className="px-4 py-2 text-gray-600 hover:bg-gray-100 rounded"
              >
                Cancel
              </button>
            </div>
          </Card>
        </div>
      )}

      {showDistributionSelector && (
        <DistributionSelector
          value={10}
          allowMeanEdit={true}
          onAdd={(mean, stdDev, name) => {
            if (name) {
              onCreateDistribution(mean, stdDev, name);
            }
            setShowDistributionSelector(false);
          }}
          onClose={() => setShowDistributionSelector(false)}
          isUpdating={false}
          showNameInput={true}
        />
      )}

      {showMeasurementSelector && (
        <MeasurementSelector
          onAdd={onCreateMeasurement}
          onClose={() => setShowMeasurementSelector(false)}
        />
      )}
    </>
  );
}); 