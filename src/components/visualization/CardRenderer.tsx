import React from 'react';
import { BarChart2 } from 'lucide-react';
import { DistributionChart } from '../charts/ReactorCharts';
import StableSTLViewer from './StableSTLViewer';

// Types
export type CardContent = 
  | { type: 'stl'; file: File }
  | { type: 'measurements'; data: Record<string, number> }
  | { type: 'distribution'; mean: number; stdDev: number; label: string; isLocal?: boolean };

export interface VisualizationCard {
  title: string;
  content: CardContent;
}

interface CardRendererProps {
  content: CardContent;
  cards: VisualizationCard[];
  onAddDistribution?: (key: string, value: number, stdDev?: number) => void;
  onChartClick?: (data: { key: string; value: number; stdDev: number }) => void;
}

const CardRenderer: React.FC<CardRendererProps> = React.memo(({ content, cards, onAddDistribution, onChartClick }) => {
  const formatNumber = (value: number): string => {
    return Math.abs(value) < 10 ? value.toFixed(2) : 
      new Intl.NumberFormat('en-US').format(Math.round(value));
  };

  switch (content.type) {
    case 'stl':
      return (
        <div className="w-full h-full -ml-2 -mr-2 -mb-2">
          <StableSTLViewer file={content.file} />
        </div>
      );

    case 'measurements':
      console.log('Rendering measurements card with data:', content.data);
      console.log('Number of measurements:', Object.keys(content.data).length);
      
      // Log the entire parent chain
      const measurementsElement = document.querySelector('[data-measurements-container]');

      return (
        <div className="h-full px-2" data-measurements-container>
          <div 
            className="h-full overflow-y-auto scrollbar-thin scrollbar-thumb-gray-300 scrollbar-track-transparent"
            onScroll={(e) => console.log('Scrolling measurements container:', e.currentTarget.scrollTop)}
          >
            <div className="flex flex-col gap-1 py-1">
              {Object.entries(content.data).map(([key, value], index) => {
                console.log(`Rendering measurement ${index + 1}/${Object.keys(content.data).length}:`, { key, value });
                const existingDistribution = cards.find(
                  card => 
                    card.content.type === 'distribution' && 
                    'label' in card.content && 
                    card.content.label === key
                );
                console.log('Found existing distribution:', existingDistribution);

                const formattedKey = key.split('_').map(word => 
                  word.charAt(0).toUpperCase() + word.slice(1)
                ).join(' ');
                console.log('Formatted key:', formattedKey);

                const element = (
                  <div 
                    key={key} 
                    className="flex justify-between items-center cursor-move"
                    draggable
                    onDragStart={(e) => {
                      const dragData = {
                        type: 'measurement',
                        label: key,
                        value: value
                      };
                      console.log('Starting drag with data:', dragData);
                      e.dataTransfer.setData('application/json', JSON.stringify(dragData));
                    }}
                    style={{ opacity: 1 }} // Force opacity
                    ref={(el) => {
                      if (el) {
                        console.log(`Measurement element mounted - ${formattedKey}:`, {
                          width: el.offsetWidth,
                          height: el.offsetHeight,
                          visible: el.offsetParent !== null
                        });
                      }
                    }}
                  >
                    <div>
                      <p 
                        className="text-xs text-gray-500 leading-tight"
                        ref={(el) => {
                          if (el) {
                            console.log(`Label element - ${formattedKey}:`, {
                              width: el.offsetWidth,
                              height: el.offsetHeight,
                              computedStyle: window.getComputedStyle(el).display
                            });
                          }
                        }}
                      >
                        {formattedKey}
                      </p>
                      <p 
                        className="font-medium text-sm leading-tight"
                        ref={(el) => {
                          if (el) {
                            console.log(`Value element - ${formattedKey}:`, {
                              width: el.offsetWidth,
                              height: el.offsetHeight,
                              computedStyle: window.getComputedStyle(el).display
                            });
                          }
                        }}
                      >
                        {formatNumber(value)} mm
                      </p>
                    </div>
                    <button
                      onClick={() => {
                        console.log('Add distribution clicked for:', { key, value, existingStdDev: existingDistribution?.content.type === 'distribution' ? existingDistribution.content.stdDev : undefined });
                        onAddDistribution?.(key, value, existingDistribution?.content.type === 'distribution' ? existingDistribution.content.stdDev : undefined);
                      }}
                      className="p-1 hover:bg-gray-100 rounded flex-shrink-0"
                    >
                      <BarChart2 className="w-3.5 h-3.5" />
                    </button>
                  </div>
                );
                console.log(`Returning element for ${formattedKey}`);
                return element;
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
            height={100}
            className="w-full h-full"
            onChartClick={() => {
              if (onChartClick && content.type === 'distribution') {
                onChartClick({
                  key: content.label,
                  value: content.mean,
                  stdDev: content.stdDev
                });
              }
            }}
          />
        </div>
      );

    default:
      return null;
  }
}, (prevProps, nextProps) => {
  if (prevProps.content.type !== nextProps.content.type) return false;
  
  if (prevProps.content.type === 'stl' && nextProps.content.type === 'stl') {
    return prevProps.content.file === nextProps.content.file;
  }
  
  return JSON.stringify(prevProps.content) === JSON.stringify(nextProps.content);
});

export default CardRenderer; 