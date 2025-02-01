import React, { useState, useCallback } from 'react';
import { DistributionSelector } from './DistributionSelector';
import { GlobalManager } from '@/backend/manager/GlobalManager';
import { VariableRecord } from '@/backend/models/Variable';
import { PlusCard } from './PlusCard';
import { VisualizationCard } from './CardRenderer';
import { Card as CardComponent } from './Card';

interface VisualizationGridProps {
  cards: VisualizationCard[];
  cardsPerRow?: number;
  fileId: string;
  onAddVariable: (variable: Omit<VariableRecord, 'id'>) => void;
  onDeleteVariable?: (label: string) => void;
}

const VisualizationGrid: React.FC<VisualizationGridProps> = React.memo(({ 
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

      // Create the variable record
      const variableRecord: VariableRecord = {
        type: 'distribution',
        name: `${name} Distribution`,
        label: selectedMeasurement.key,
        mean,
        stdDev,
        fileId,
        id: selectedMeasurement.key
      };

      // Check if this is an update or new distribution
      const existingDistribution = initialCards.find(
        card => 
          card.content.type === 'distribution' && 
          card.content.label === selectedMeasurement.key
      );

      if (existingDistribution) {
        // Use the GlobalManager's updateDistribution method
        GlobalManager.getInstance().updateDistribution(fileId, variableRecord);
      } else {
        // Create new distribution
        onAddVariable(variableRecord);
      }

      setSelectedMeasurement(null);
    }
  }, [selectedMeasurement, fileId, initialCards, onAddVariable]);

  const handleNewDistribution = useCallback((mean: number, stdDev: number, name: string) => {
    const key = name.toLowerCase()
      .replace(/\s+distribution$/i, '')
      .replace(/\s+/g, '_');
    
    onAddVariable({
      type: 'distribution',
      name: name.endsWith('Distribution') ? name : `${name} Distribution`,
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
          <CardComponent
            key={`${card.title}-${index}-${card.content.type === 'distribution' ? card.content.label : ''}`}
            card={card}
            cards={initialCards}
            index={index}
            onAddDistribution={handleAddDistribution}
            onDeleteVariable={onDeleteVariable}
            onChartClick={setSelectedMeasurement}
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
}, (prevProps, nextProps) => {
  if (prevProps.fileId !== nextProps.fileId) {
    return false;
  }
  
  if (prevProps.cards.length !== nextProps.cards.length) {
    return false;
  }
  
  return prevProps.cards.every((card, index) => {
    const nextCard = nextProps.cards[index];
    if (card.content.type === 'distribution' && nextCard.content.type === 'distribution') {
      return (
        card.content.label === nextCard.content.label &&
        card.content.mean === nextCard.content.mean &&
        card.content.stdDev === nextCard.content.stdDev
      );
    }
    return true;
  });
});

VisualizationGrid.displayName = 'VisualizationGrid';

export default VisualizationGrid; 