import React, { useMemo, useState, useCallback, useEffect } from 'react';
import { Canvas } from '@react-three/fiber'
import { OrbitControls, Stage } from '@react-three/drei'
import { useLoader } from '@react-three/fiber'
import { STLLoader } from 'three/examples/jsm/loaders/STLLoader'
import { DistributionChart } from '../charts/ReactorCharts';
import { Card } from '@/components/ui/card';
import { BarChart2, X, Ruler } from 'lucide-react';
import { DistributionSelector, MeasurementSelector } from './DistributionSelector';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';
import { VariableRecord } from '@/backend/Variable';

// Define possible card content types
type CardContent = 
  | { type: 'stl'; file: File }
  | { type: 'measurements'; data: Record<string, number> }
  | { type: 'distribution'; mean: number; stdDev: number; label: string; isLocal?: boolean };

interface VisualizationCard {
  title: string;
  content: CardContent;
}

interface VisualizationGridProps {
  cards: VisualizationCard[];
  cardsPerRow?: number;
  fileId: string;
  onAddVariable: (variable: Omit<VariableRecord, 'id'>) => void;
  onDeleteVariable?: (label: string) => void;
}

interface CardRendererProps {
  content: CardContent;
  cards: VisualizationCard[];
  onAddDistribution?: (key: string, value: number, stdDev?: number) => void;
}

const Model = ({ url }: { url: string }) => {
  const geometry = useLoader(STLLoader, url)
  return (
    <mesh geometry={geometry}>
      <meshStandardMaterial color="#b8b8b8" />
    </mesh>
  )
}

const CardRenderer: React.FC<CardRendererProps> = React.memo(({ content, cards, onAddDistribution }) => {
  const formatNumber = (value: number): string => {
    return Math.abs(value) < 10 ? value.toFixed(2) : 
      new Intl.NumberFormat('en-US').format(Math.round(value));
  };

  // For STL files, memoize the URL creation
  const stlUrl = useMemo(() => {
    if (content.type === 'stl') {
      return URL.createObjectURL(content.file);
    }
    return null;
  }, [content.type === 'stl' ? content.file : null]);

  // Cleanup URL when component unmounts
  React.useEffect(() => {
    return () => {
      if (stlUrl) {
        URL.revokeObjectURL(stlUrl);
      }
    };
  }, [stlUrl]);

  // Create and manage URL for STL files
  const [objectUrl, setObjectUrl] = React.useState<string | null>(null);

  React.useEffect(() => {
    if (content.type === 'stl') {
      
      const url = URL.createObjectURL(content.file);
      setObjectUrl(url);
      return () => {
        URL.revokeObjectURL(url);
      };
    }
  }, [content]);

  switch (content.type) {
    case 'stl':
      if (!objectUrl) return <div>Loading...</div>;
      return (
        <div className="w-full h-full -ml-2 -mr-2 -mb-2">
          <Canvas>
            <Stage environment="city" intensity={0.6}>
              <Model url={objectUrl} />
            </Stage>
            <OrbitControls 
              makeDefault
              minPolarAngle={0}
              maxPolarAngle={Math.PI / 1.75}
            />
          </Canvas>
        </div>
      );

    case 'measurements':
      return (
        <div className="h-full px-2">
          <div className="h-full overflow-y-auto scrollbar-thin scrollbar-thumb-gray-300 scrollbar-track-transparent">
            <div className="flex flex-col gap-1 py-1">
              {Object.entries(content.data).map(([key, value]) => {
                const existingDistribution = cards.find(
                  card => 
                    card.content.type === 'distribution' && 
                    'label' in card.content && 
                    card.content.label === key
                );

                return (
                  <div 
                    key={key} 
                    className="flex justify-between items-center cursor-move"
                    draggable
                    onDragStart={(e) => {
                      e.dataTransfer.setData('application/json', JSON.stringify({
                        type: 'measurement',
                        label: key,
                        value: value
                      }));
                    }}
                  >
                    <div>
                      <p className="text-xs text-gray-500 leading-tight">
                        {key.split('_').map(word => 
                          word.charAt(0).toUpperCase() + word.slice(1)
                        ).join(' ')}
                      </p>
                      <p className="font-medium text-sm leading-tight">{formatNumber(value)} mm</p>
                    </div>
                    <button
                      onClick={() => onAddDistribution?.(key, value, existingDistribution?.content.type === 'distribution' ? existingDistribution.content.stdDev : undefined)}
                      className="p-1 hover:bg-gray-100 rounded flex-shrink-0"
                    >
                      <BarChart2 className="w-3.5 h-3.5" />
                    </button>
                  </div>
                );
              })}
            </div>
          </div>
        </div>
      );

    case 'distribution':
      return (
        <div 
          className="w-full h-full -ml-2 -mr-2 -mb-2 cursor-move"
          draggable
          onDragStart={(e) => {
            e.dataTransfer.setData('application/json', JSON.stringify({
              type: 'distribution',
              label: content.label,
              mean: content.mean,
              stdDev: content.stdDev
            }));
          }}
        >
          <DistributionChart
            mean={content.mean}
            stdDev={content.stdDev}
            type="normal"
            data={[]}
            height="100%"
            className="w-full h-full"
            onChartClick={() => {
              if (onAddDistribution) {
                onAddDistribution(content.label, content.mean, content.stdDev);
              }
            }}
          />
        </div>
      );

    default:
      return null;
  }
}, (prevProps, nextProps) => {
  // Custom comparison for memoization
  if (prevProps.content.type !== nextProps.content.type) return false;
  
  if (prevProps.content.type === 'stl' && nextProps.content.type === 'stl') {
    return prevProps.content.file === nextProps.content.file;
  }
  
  return JSON.stringify(prevProps.content) === JSON.stringify(nextProps.content);
});

// Memoize the VisualizationCard component
const VisualizationCard = React.memo<{ 
  card: VisualizationCard;
  cards: VisualizationCard[];
  index: number;
  onAddDistribution?: (key: string, value: number, stdDev?: number) => void;
  onDeleteVariable?: (label: string) => void;
}>(({ card, cards, index, onAddDistribution, onDeleteVariable }) => {
  const isStlViewer = card.content.type === 'stl';
  
  return (
    <Card className="aspect-square p-2 w-[180px] overflow-hidden relative">
      {card.content.type === 'distribution' && card.content.isLocal && onDeleteVariable && (
        <button
          onClick={(e) => {
            e.stopPropagation();
            onDeleteVariable(card.content.label);
          }}
          className="absolute top-2 right-2 p-1 hover:bg-gray-100 rounded-full z-10"
        >
          <X className="w-3 h-3 text-gray-500" />
        </button>
      )}
      <h3 className="font-medium mb-2 px-2 text-sm">{card.title}</h3>
      <div className="h-[calc(100%-2rem)] w-full">
        <CardRenderer 
          content={card.content}
          cards={cards}
          onAddDistribution={onAddDistribution}
        />
      </div>
    </Card>
  );
});

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

export const createVisualizationCards = (
  fileId: string,
  stlFile: File | { name: string; data: string; type: string },
  localVariables?: Map<string, VariableRecord>
): VisualizationCard[] => {
  const globalFileManager = GlobalFileManager.getInstance();
  
  // Get global variables
  const globalMeasurements = globalFileManager.getMeasurementsForFile(fileId);
  const globalDistributions = globalFileManager.getDistributionsForFile(fileId);
  
  // Get local variables for this file (with null check)
  const localMeasurements = localVariables ? 
    Array.from(localVariables.values())
      .filter(v => v.fileId === fileId && v.type === 'measurement')
    : [];
    
  const localDistributions = localVariables ? 
    Array.from(localVariables.values())
      .filter(v => v.fileId === fileId && v.type === 'distribution')
    : [];

  // Combine measurements
  const measurementData = [...globalMeasurements, ...localMeasurements]
    .reduce((acc, m) => ({ ...acc, [m.name]: m.value }), {});

  const cards: VisualizationCard[] = [
    {
      title: '3D Model',
      content: { 
        type: 'stl', 
        file: stlFile instanceof File ? stlFile : new File(
          [Uint8Array.from(atob(stlFile.data.split(',')[1]), c => c.charCodeAt(0))],
          stlFile.name,
          { type: stlFile.type }
        )
      }
    }
  ];

  if (Object.keys(measurementData).length > 0) {
    cards.push({
      title: 'Measurements',
      content: { type: 'measurements', data: measurementData }
    });
  }

  // Add global distributions
  globalDistributions.forEach(dist => {
    cards.push({
      title: dist.name || `${dist.label.split('_').map(word => 
        word.charAt(0).toUpperCase() + word.slice(1)
      ).join(' ')} Distribution`,
      content: {
        type: 'distribution',
        mean: dist.mean,
        stdDev: dist.stdDev,
        label: dist.label,
        isLocal: false // This indicates it's a global distribution
      }
    });
  });

  // Add local distributions
  localDistributions.forEach(dist => {
    cards.push({
      title: dist.name || `${dist.label.split('_').map(word => 
        word.charAt(0).toUpperCase() + word.slice(1)
      ).join(' ')} Distribution`,
      content: {
        type: 'distribution',
        mean: dist.mean,
        stdDev: dist.stdDev,
        label: dist.label,
        isLocal: true // This indicates it's a local distribution
      }
    });
  });

  // If we're not in a preprocessing cell (no localVariables provided), 
  // mark all distributions as deletable
  if (!localVariables) {
    cards.forEach(card => {
      if (card.content.type === 'distribution') {
        card.content.isLocal = true; // Make all distributions deletable in FileUploadSection
      }
    });
  }

  return cards;
};

const VisualizationGrid: React.FC<VisualizationGridProps> = ({ 
  cards: initialCards, 
  cardsPerRow = 3,
  fileId,
  onAddVariable,
  onDeleteVariable 
}) => {
  const [selectedMeasurement, setSelectedMeasurement] = useState<{
    key: string;
    value: number;
    stdDev?: number;
  } | null>(null);

  const handleAddDistribution = useCallback((key: string, value: number, stdDev?: number) => {
    setSelectedMeasurement({ key, value, stdDev });
  }, []);

  const handleDistributionCreated = useCallback((mean: number, stdDev: number) => {
    if (selectedMeasurement) {
      const name = selectedMeasurement.key.split('_')
        .map(word => word.charAt(0).toUpperCase() + word.slice(1))
        .join(' ');

      onAddVariable({
        type: 'distribution',
        name: `${name} Distribution`,
        label: selectedMeasurement.key,
        mean,
        stdDev,
        fileId
      });

      setSelectedMeasurement(null);
    }
  }, [selectedMeasurement, onAddVariable, fileId]);

  const handleNewDistribution = useCallback((mean: number, stdDev: number, name: string) => {
    const key = name.toLowerCase()
      .replace(/\s+distribution$/i, '')
      .replace(/\s+/g, '_');
    
    const fullName = name.endsWith('Distribution') ? name : `${name} Distribution`;

    onAddVariable({
      type: 'distribution',
      name: fullName,
      label: key,
      mean,
      stdDev,
      fileId
    });
  }, [fileId, onAddVariable]);

  const handleNewMeasurement = useCallback((name: string, value: number) => {
    const key = name.toLowerCase().replace(/\s+/g, '_');
    
    onAddVariable({
      type: 'measurement',
      name,
      label: key,
      value,
      fileId
    });
  }, [fileId, onAddVariable]);

  return (
    <>
      <div
        className="grid gap-4 justify-start"
        style={{
          gridTemplateColumns: 'repeat(auto-fill, 180px)',
        }}
      >
        {initialCards.map((card, index) => (
          <VisualizationCard
            key={`${card.title}-${index}-${card.content.type === 'distribution' ? card.content.label : ''}`}
            card={card}
            cards={initialCards}
            index={index}
            onAddDistribution={handleAddDistribution}
            onDeleteVariable={onDeleteVariable}
          />
        ))}
        <PlusCard 
          onCreateDistribution={handleNewDistribution}
          onCreateMeasurement={handleNewMeasurement}
        />
      </div>

      {selectedMeasurement && (
        <DistributionSelector
          value={selectedMeasurement.value}
          currentStdDev={selectedMeasurement.stdDev}
          onAdd={handleDistributionCreated}
          onClose={() => setSelectedMeasurement(null)}
          isUpdating={initialCards.some(
            card => 
              card.content.type === 'distribution' && 
              'label' in card.content && 
              card.content.label === selectedMeasurement.key
          )}
        />
      )}
    </>
  );
};

export default VisualizationGrid; 