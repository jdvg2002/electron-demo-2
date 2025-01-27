import React, { useState } from 'react';
import { BarChart2 } from 'lucide-react';
import { BaseCell } from './BaseCell';
import type { NotebookCellProps } from './NotebookCell';
import { PostprocessingChart } from './PostprocessingChart';
import { processStressData } from './postprocessing';

export const PostprocessingCell: React.FC<NotebookCellProps> = (props) => {
  // Initialize showChart based on whether output exists
  const [showChart, setShowChart] = useState(
    Boolean(props.cell.output?.chartData && props.cell.status === 'completed')
  );

  const handleExecute = () => {
    const externalOutput = props.previousCell?.output?.processedData?.data;
    if (!externalOutput) return;

    const dataArray = Array.isArray(externalOutput) ? externalOutput :
                     Array.isArray(externalOutput.results) ? externalOutput.results :
                     Array.isArray(externalOutput.data) ? externalOutput.data : null;
    
    if (!dataArray) return;

    const { chartData, probabilityOfFailure } = processStressData(dataArray);

    // First update with status change and store chart data
    props.onCellChange({
      ...props.cell,
      status: 'completed',
      output: {
        processedData: {
          id: crypto.randomUUID(),
          type: 'analysis_results',
          version: '1.0',
          timestamp: new Date().toISOString(),
          originalFileName: 'analysis_results.json',
          sourceEnvironment: 'postprocessing',
          data: dataArray
        },
        chartData,
        probabilityOfFailure,
        metadata: {
          analysisTimestamp: new Date().toISOString(),
          sourceAnalysis: 'postprocessing',
          displayState: {
            showChart: true
          }
        }
      }
    });

    // Then update UI
    setShowChart(true);
  };

  // Update chart visibility based on cell output
  React.useEffect(() => {
    if (props.cell.status === 'completed' && props.cell.output?.chartData) {
      setShowChart(true);
    } else {
      setShowChart(false);
    }
  }, [props.cell.status, props.cell.output?.chartData]);

  return (
    <BaseCell
      {...props}
      icon={<BarChart2 className="text-purple-500" />}
      borderColor="border-l-purple-500"
    >
      <div className="space-y-4">
        <button
          onClick={handleExecute}
          className="px-4 py-2 bg-green-500 text-white rounded hover:bg-green-600"
        >
          Show Chart
        </button>

        {showChart && props.cell.output?.chartData && (
          <PostprocessingChart
            chartData={props.cell.output.chartData}
            probabilityOfFailure={props.cell.output.probabilityOfFailure}
          />
        )}
      </div>
    </BaseCell>
  );
}; 