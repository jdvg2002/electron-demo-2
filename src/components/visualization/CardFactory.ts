import { VariableRecord } from '@/backend/models/Variable';
import { GlobalManager } from '@/backend/manager/GlobalManager';
import { VisualizationCard } from './CardRenderer';

export class CardFactory {
  private static createStlCard(stlFile: File | { name: string; data: string; type: string }): VisualizationCard {
    return {
      title: '3D Model',
      content: { 
        type: 'stl', 
        file: stlFile instanceof File ? stlFile : new File(
          [Uint8Array.from(atob(stlFile.data.split(',')[1]), c => c.charCodeAt(0))],
          stlFile.name,
          { type: stlFile.type }
        )
      }
    };
  }

  private static formatTitle(label: string, name?: string): string {
    return name || `${label.split('_').map(word => 
      word.charAt(0).toUpperCase() + word.slice(1)
    ).join(' ')} Distribution`;
  }

  private static createDistributionCard(
    dist: VariableRecord, 
    isLocal: boolean
  ): VisualizationCard {
    if (!dist.mean || !dist.stdDev || !dist.label) {
      throw new Error('Invalid distribution record: missing required fields');
    }
    
    return {
      title: this.formatTitle(dist.label, dist.name),
      content: {
        type: 'distribution',
        mean: dist.mean,
        stdDev: dist.stdDev,
        label: dist.label,
        isLocal
      }
    };
  }

  static createCards(
    fileId: string,
    stlFile: File | { name: string; data: string; type: string },
    localVariables?: Map<string, VariableRecord>,
    isPreprocessing: boolean = !!localVariables
  ): VisualizationCard[] {
    const globalManager = GlobalManager.getInstance();
    const cards: VisualizationCard[] = [];
    
    // Add STL card
    cards.push(this.createStlCard(stlFile));

    // Get and process measurements
    const globalMeasurements = globalManager.getVariablesForFile(fileId)
      .filter(v => v.type === 'measurement');
    const localMeasurements = localVariables ? 
      Array.from(localVariables.values())
        .filter(v => v.fileId === fileId && v.type === 'measurement')
      : [];

    const measurementData = [...globalMeasurements, ...localMeasurements]
      .reduce((acc, m) => ({ ...acc, [m.name]: m.value }), {});

    if (Object.keys(measurementData).length > 0) {
      cards.push({
        title: 'Measurements',
        content: { type: 'measurements', data: measurementData }
      });
    }

    // Process distributions
    const globalDistributions = globalManager.getVariablesForFile(fileId)
      .filter(v => v.type === 'distribution')
      .map(dist => this.createDistributionCard(dist, false));

    const localDistributions = localVariables ? 
      Array.from(localVariables.values())
        .filter(v => v.fileId === fileId && v.type === 'distribution')
        .map(dist => this.createDistributionCard(dist, true))
      : [];

    cards.push(...globalDistributions, ...localDistributions);

    // Mark all distributions as deletable if not in preprocessing
    if (!isPreprocessing) {
      cards.forEach(card => {
        if (card.content.type === 'distribution') {
          card.content.isLocal = true;
        }
      });
    }

    return cards;
  }
} 