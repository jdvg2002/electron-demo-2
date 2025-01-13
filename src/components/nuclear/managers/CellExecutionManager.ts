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
    public async runPreprocessingCode(code: string) {
      try {
        const result = await window.electronWindow.executePython(code);
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
    public async runExternalTool(tool: string, projectRoot: string) {
      try {
        const result = await window.electronWindow.executePython(`
          import sys
          import os
          
          script_path = os.path.join('${projectRoot}', 'server', 'fatigue_crack_init.py')
          print(f"Executing script at: {script_path}")
          
          sys.path.append(os.path.dirname(script_path))
          
          from fatigue_crack_init import main
          main()
        `);
  
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