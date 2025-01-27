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

  private static createCsvCard(file: File, fileId: string): VisualizationCard {
    return {
      title: 'CSV Data',
      content: { 
        type: 'csv',
        file,
        fileName: file.name,
        fileId
      }
    };
  }

  static createCards(
    fileId: string,
    file: File | { name: string; data: string; type: string },
    localVariables?: Map<string, VariableRecord>,
    isPreprocessing: boolean = !!localVariables
  ): VisualizationCard[] {

    const globalManager = GlobalManager.getInstance();
    const cards: VisualizationCard[] = [];
    
    // Check file type
    const fileName = file instanceof File ? file.name : file.name;
    if (fileName.toLowerCase().endsWith('.csv')) {
      cards.push(this.createCsvCard(file instanceof File ? file : new File(
        [Uint8Array.from(atob(file.data.split(',')[1]), c => c.charCodeAt(0))],
        fileId
      ), fileId));
      return cards;  // Return early for CSV files
    }

    // Only add STL card for STL or STEP files
    cards.push(this.createStlCard(file));

    // Get and process measurements
    const globalMeasurements = globalManager.getVariablesForFile(fileId)
      .filter(v => v.type === 'measurement');
    const localMeasurements = localVariables ? 
      Array.from(localVariables.values())
        .filter(v => v.fileId === fileId && v.type === 'measurement')
      : [];
    
    const measurementsByComponent = [...globalMeasurements, ...localMeasurements]
      .reduce((acc, m) => {
        const component = m.component || 'General';
        if (!acc[component]) {
          acc[component] = [];
        }
        acc[component].push(m);
        return acc;
      }, {} as Record<string, VariableRecord[]>);

    
    // Create measurement cards per component
    Object.entries(measurementsByComponent).forEach(([component, measurements]) => {
      
      const measurementData = measurements.reduce((acc, m) => {
        const key = m.name.split(' - ')[1] || m.name;
        return { ...acc, [key]: m.value };
      }, {});
      
      
      cards.push({
        title: `${component} Measurements`,
        content: { type: 'measurements', data: measurementData }
      });
    });

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