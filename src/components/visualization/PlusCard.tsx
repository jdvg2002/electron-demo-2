import React, { useState } from 'react';
import { Card } from '@/components/ui/card';
import { BarChart2, Ruler } from 'lucide-react';
import { DistributionSelector } from './DistributionSelector';
import { MeasurementSelector } from './MeasurementSelector';

interface PlusCardProps {
  onCreateDistribution: (mean: number, stdDev: number, name: string) => void;
  onCreateMeasurement: (name: string, value: number) => void;
}

export const PlusCard: React.FC<PlusCardProps> = React.memo(({ 
  onCreateDistribution,
  onCreateMeasurement 
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

PlusCard.displayName = 'PlusCard'; 