import React, { useMemo } from 'react';
import { StlViewer } from 'react-stl-viewer';
import { DistributionChart } from '../charts/ReactorCharts';
import { Card } from '@/components/ui/card';

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
}

const CardRenderer: React.FC<{ content: CardContent }> = React.memo(({ content }) => {
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
      console.log('STL content:', {
        file: content.file,
        size: content.file.size,
        type: content.file.type
      });
      
      const url = URL.createObjectURL(content.file);
      console.log('Created URL:', url);
      setObjectUrl(url);
      return () => {
        console.log('Cleaning up URL:', url);
        URL.revokeObjectURL(url);
      };
    }
  }, [content]);

  switch (content.type) {
    case 'stl':
      console.log('Rendering STL with URL:', objectUrl);
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
        <div className="grid grid-rows-3 h-full gap-4 -ml-2 -mr-2 -mb-2">
          {Object.entries(content.data).map(([key, value]) => (
            <div key={key} className="flex flex-col justify-center px-4">
              <p className="text-sm text-gray-500">
                {key.split('_').map(word => 
                  word.charAt(0).toUpperCase() + word.slice(1)
                ).join(' ')}
              </p>
              <p className="font-medium">{formatNumber(value)} mm</p>
            </div>
          ))}
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
  index: number;
}>(({ card, index }) => {
  const isStlViewer = card.content.type === 'stl';
  
  return (
    <Card className="aspect-square p-2 min-w-[150px] overflow-hidden">
      <h3 className="font-medium mb-1 px-2 text-sm">{card.title}</h3>
      <div className="h-[calc(100%-1.5rem)] w-full">
        <CardRenderer content={card.content} />
      </div>
    </Card>
  );
});

const VisualizationGrid: React.FC<VisualizationGridProps> = ({ 
  cards,
  cardsPerRow = 7
}) => {
  return (
    <div className="w-full grid gap-3 auto-rows-fr"
      style={{ 
        gridTemplateColumns: `repeat(${cardsPerRow}, minmax(150px, 1fr))`
      }}>
      {cards.map((card, index) => (
        <VisualizationCard 
          key={index} 
          card={card} 
          index={index}
        />
      ))}
    </div>
  );
};

// Helper function to create visualization cards from STEP file data
export const createVisualizationCards = (
  stlFile: File | { name: string; data: string; type: string },
  measurements: Record<string, number>
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

  // Add distribution charts for each measurement
  Object.entries(measurements).forEach(([key, value]) => {
    cards.push({
      title: `${key.split('_').map(word => 
        word.charAt(0).toUpperCase() + word.slice(1)
      ).join(' ')} Distribution`,
      content: {
        type: 'distribution',
        mean: value,
        stdDev: value * 0.05,
        label: key
      }
    });
  });

  return cards;
};

export default VisualizationGrid; 