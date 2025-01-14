import React, { useMemo, useState, useCallback, useEffect } from 'react';
import { StlViewer } from 'react-stl-viewer';
import { DistributionChart } from '../charts/ReactorCharts';
import { Card } from '@/components/ui/card';
import { BarChart2 } from 'lucide-react';
import { DistributionSelector } from './DistributionSelector';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';

// Define possible card content types
type CardContent = 
  | { type: 'stl'; file: File }
  | { type: 'measurements'; data: Record<string, number> }
  | { type: 'distribution'; mean: number; stdDev: number; label: string };

interface VisualizationCard {
  title: string;
  content: CardContent;
}

interface VisualizationGridProps {
  cards: VisualizationCard[];
  cardsPerRow?: number;
  fileId: string;
}

interface CardRendererProps {
  content: CardContent;
  cards: VisualizationCard[];
  onAddDistribution?: (key: string, value: number, stdDev?: number) => void;
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
          <StlViewer
            style={{ width: '100%', height: '100%' }}
            orbitControls
            shadows
            url={URL.createObjectURL(content.file)}
            modelProps={{
              scale: 1.25,
              rotationX: 0,
              rotationY: 0,
              rotationZ: 0
            }}
          />
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
                  <div key={key} className="flex justify-between items-center">
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
        <div className="w-full h-full -ml-2 -mr-2 -mb-2">
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
}>(({ card, cards, index, onAddDistribution }) => {
  const isStlViewer = card.content.type === 'stl';
  
  return (
    <Card className="aspect-square p-2 w-[180px] overflow-hidden">
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

const PlusCard = React.memo(({ onCreateDistribution }: { onCreateDistribution: (mean: number, stdDev: number, name: string) => void }) => {
  const [showSelector, setShowSelector] = useState(false);

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
        <DistributionSelector
          value={10}
          allowMeanEdit={true}
          onAdd={(mean, stdDev, name) => {
            if (name) {
              onCreateDistribution(mean, stdDev, name);
            }
            setShowSelector(false);
          }}
          onClose={() => setShowSelector(false)}
          isUpdating={false}
          showNameInput={true}
        />
      )}
    </>
  );
});

const VisualizationGrid: React.FC<VisualizationGridProps> = ({ 
  cards: initialCards, 
  cardsPerRow = 3,
  fileId 
}) => {
  const [cards, setCards] = useState(initialCards);
  const [selectedMeasurement, setSelectedMeasurement] = useState<{
    key: string;
    value: number;
    stdDev?: number;
  } | null>(null);

  const globalFileManager = useMemo(() => GlobalFileManager.getInstance(), []);

  const handleAddDistribution = useCallback((key: string, value: number, stdDev?: number) => {
    setSelectedMeasurement({ key, value, stdDev });
  }, []);

  const handleNewDistribution = useCallback((mean: number, stdDev: number, name: string) => {
    // Convert the name to the key format: lowercase with underscores
    const key = name.toLowerCase()
        .replace(/\s+distribution$/i, '')  // Remove 'distribution' suffix if present
        .replace(/\s+/g, '_');  // Replace spaces with underscores
    
    const fullName = `${name} Distribution`;

    // Save to GlobalFileManager with the full name
    globalFileManager.addDistribution(
      fileId,
      key,
      mean,
      stdDev,
      fullName
    );

    // Create new distribution card
    const newCard: VisualizationCard = {
      title: fullName,
      content: {
        type: 'distribution',
        mean,
        stdDev,
        label: key
      }
    };

    setCards(prevCards => [...prevCards, newCard]);
  }, [fileId, globalFileManager]);

  const handleDistributionCreated = useCallback((mean: number, stdDev: number) => {
    if (selectedMeasurement) {
      const name = selectedMeasurement.key.split('_')
        .map(word => word.charAt(0).toUpperCase() + word.slice(1))
        .join(' ') + ' Distribution';

      // Save to GlobalFileManager with the generated name
      globalFileManager.addDistribution(
        fileId,
        selectedMeasurement.key,
        mean,
        stdDev,
        name
      );

      // Create new distribution card
      const newCard: VisualizationCard = {
        title: name,
        content: {
          type: 'distribution',
          mean,
          stdDev,
          label: selectedMeasurement.key
        }
      };

      setCards(prevCards => [...prevCards, newCard]);
      setSelectedMeasurement(null);
    }
  }, [selectedMeasurement, fileId, globalFileManager]);

  return (
    <>
      <div
        className="grid gap-4 justify-start"
        style={{
          gridTemplateColumns: 'repeat(auto-fill, 180px)',
        }}
      >
        {cards.map((card, index) => (
          <VisualizationCard
            key={index}
            card={card}
            cards={cards}
            index={index}
            onAddDistribution={handleAddDistribution}
          />
        ))}
        <PlusCard onCreateDistribution={handleNewDistribution} />
      </div>

      {selectedMeasurement && (
        <DistributionSelector
          value={selectedMeasurement.value}
          currentStdDev={selectedMeasurement.stdDev}
          onAdd={handleDistributionCreated}
          onClose={() => setSelectedMeasurement(null)}
          isUpdating={cards.some(
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

// Helper function to create visualization cards from STEP file data
export const createVisualizationCards = (
  stlFile: File | { name: string; data: string; type: string },
  measurements: Record<string, number>,
  distributions?: Record<string, DistributionData>
): VisualizationCard[] => {
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
    },
    {
      title: 'Measurements',
      content: { type: 'measurements', data: measurements }
    }
  ];

  if (distributions) {
    Object.values(distributions).forEach(dist => {
      cards.push({
        title: dist.name || `${dist.label.split('_').map(word => 
          word.charAt(0).toUpperCase() + word.slice(1)
        ).join(' ')} Distribution`,
        content: {
          type: 'distribution',
          mean: dist.mean,
          stdDev: dist.stdDev,
          label: dist.label
        }
      });
    });
  }

  return cards;
};

export default VisualizationGrid; 