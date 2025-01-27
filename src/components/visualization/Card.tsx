import React from 'react';
import { Card as UICard } from '@/components/ui/card';
import { X } from 'lucide-react';
import CardRenderer from './CardRenderer';
import type { VisualizationCard } from './CardRenderer';

interface CardProps {
  card: VisualizationCard;
  cards: VisualizationCard[];
  index: number;
  onAddDistribution?: (key: string, value: number, stdDev?: number) => void;
  onDeleteVariable?: (label: string) => void;
  onChartClick?: (data: { key: string; value: number; stdDev: number }) => void;
}

export const Card = React.memo<CardProps>(({
  card,
  cards,
  onAddDistribution,
  onDeleteVariable,
  onChartClick
}) => {
  const renderCount = React.useRef(0);
  const [isVisible, setIsVisible] = React.useState(false);
  const cardRef = React.useRef<HTMLDivElement>(null);

  React.useEffect(() => {
    renderCount.current += 1;

    // Use a layout effect equivalent for the visibility update
    const timer = setTimeout(() => {
      if (cardRef.current) {
        const computedStyle = window.getComputedStyle(cardRef.current);
        
        setIsVisible(true);
      }
    }, 0);

    return () => clearTimeout(timer);
  }, [card.title]);

  return (
    <UICard 
      ref={cardRef}
      className="aspect-square p-2 w-[180px] overflow-hidden relative"
    >
      {card.content.type === 'distribution' && card.content.isLocal && onDeleteVariable && (
        <button
          onClick={(e) => {
            e.stopPropagation();
            if (card.content.type === 'distribution') {
              onDeleteVariable(card.content.label);
            }
          }}
          className="absolute top-2 right-2 p-1 hover:bg-gray-100 rounded-full z-10"
        >
          <X className="w-3 h-3 text-gray-500" />
        </button>
      )}
      <h3 className="font-medium mb-2 px-2 text-sm">{card.title}</h3>
      <div 
        className={`h-[calc(100%-2rem)] w-full transition-opacity duration-150 ${
          isVisible ? 'opacity-100' : 'opacity-0'
        }`}
        style={{ 
          willChange: 'opacity',
          contain: 'layout style paint'
        }}
      >
        <CardRenderer 
          content={card.content}
          cards={cards}
          onAddDistribution={onAddDistribution}
          onChartClick={onChartClick}
        />
      </div>
    </UICard>
  );
});

Card.displayName = 'Card'; 