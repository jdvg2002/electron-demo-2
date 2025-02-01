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
        throw error;
      }
    }
  
    /**
     * Executes external tools with specific configurations
     */
    public async runExternalTool(tool: string, projectRoot: string, analysisType: string, processedData: any = null) {
      try {
        let scriptPath;
        switch (analysisType) {
          case 'pipeFailure':
            scriptPath = 'handler.py';
            break;
          case 'fatigueCrackInit':
            scriptPath = 'handler.py';
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

        const pythonCode = `import sys
import os
import json
import traceback

try:
    script_path = os.path.join('${projectRoot}', 'server', '${scriptPath}')
    sys.path.append(os.path.dirname(script_path))

    from ${scriptPath.replace('.py', '')} import main
    preprocessed_data = ${processedData ? JSON.stringify(processedData) : 'None'}
    analysis_type = "${analysisType.replace(/([A-Z])/g, '_$1').toLowerCase().replace(/^_/, '')}"
    result = main(preprocessed_data, analysis_type)
    print(json.dumps({"data": result}))
except Exception as e:
    print(json.dumps({
        "data": {
            "status": "error",
            "results": None,
            "errorCode": f"Python execution error: {str(e)}\\nTraceback: {traceback.format_exc()}"
        }
    }))`;

        const result = await window.electronWindow.executePython(pythonCode);

        if (!result.success) {
            throw new Error(`Python execution failed: ${result.error}`);
        }

        // Parse the JSON string from stdout to get the actual data
        try {
            if (!result.stdout) {
                throw new Error('No output from Python script');
            }
            const parsedOutput = JSON.parse(result.stdout);
            if (parsedOutput.data.status === "error") {
                throw new Error(parsedOutput.data.errorCode);
            }
            return parsedOutput.data;
        } catch (e: Error | unknown) {
            throw new Error(`Invalid output format from Python script: ${e instanceof Error ? e.message : String(e)}\nOutput: ${result.stdout}`);
        }
      } catch (error) {
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
        throw error;
      }
    }
  }
  
  export default CellExecutionManager;