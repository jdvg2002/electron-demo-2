/**
 * Manages the execution of different types of cells, providing a centralized
 * interface for running code and external tools.
 */
export class CellExecutionManager {
    private static instance: CellExecutionManager;
  
    private constructor() {}
  
    public static getInstance(): CellExecutionManager {
      if (!CellExecutionManager.instance) {
        CellExecutionManager.instance = new CellExecutionManager();
      }
      return CellExecutionManager.instance;
    }
  
    /**
     * Executes Python code for preprocessing cells
     */
    public async runPreprocessingCode(code: string, inputData: any = null) {
      try {
        // Prepare the Python code with the input data
        const executionCode = `
import json
input_data = json.loads('''${JSON.stringify(inputData)}''')

${code}

# Execute the process_data function with the input data
result = process_data(input_data)
print(json.dumps({"result": result}))
`;

        const result = await window.electronWindow.executePython(executionCode);
        if (!result.success) {
          throw new Error(result.error);
        }
        return result;
      } catch (error) {
        console.error("Preprocessing execution failed:", error);
        throw error;
      }
    }
  
    /**
     * Executes external tools with specific configurations
     */
    public async runExternalTool(tool: string, projectRoot: string, analysisType: string) {
      try {
        let scriptPath;
        switch (analysisType) {
          case 'pipeFailure':
            scriptPath = 'handler.py';
            break;
          case 'fatigueCrackInit':
            scriptPath = 'fatigue_crack_init.py';
            break;
          case 'ansys':
            scriptPath = 'ansys_fracture.py';
            break;
          case 'relap':
            scriptPath = 'relap_analysis.py';
            break;
          default:
            throw new Error('Invalid analysis type');
        }

        const result = await window.electronWindow.executePython(
          `import sys
import os

script_path = os.path.join('${projectRoot}', 'server', '${scriptPath}')
sys.path.append(os.path.dirname(script_path))

from ${scriptPath.replace('.py', '')} import main
main()`
        );

        if (!result.success) {
          throw new Error(result.error);
        }
        return result;
      } catch (error) {
        console.error("External tool execution failed:", error);
        throw error;
      }
    }
  
    /**
     * Executes Python code for postprocessing cells
     */
    public async runPostprocessingCode(code: string) {
      try {
        const result = await window.electronWindow.executePython(code);
        if (!result.success) {
          throw new Error(result.error);
        }
        return result;
      } catch (error) {
        console.error("Postprocessing execution failed:", error);
        throw error;
      }
    }
  }
  
  export default CellExecutionManager;