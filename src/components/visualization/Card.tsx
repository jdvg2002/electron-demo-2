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
  return (
    <UICard className="aspect-square p-2 w-[180px] overflow-hidden relative">
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
      <div className="h-[calc(100%-2rem)] w-full">
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