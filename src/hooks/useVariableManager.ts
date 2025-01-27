import { useCallback, useMemo } from 'react';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { GlobalManager } from '@/backend/manager/GlobalManager';
import { VariableRecord } from '@/backend/models/Variable';
import { CellManager } from '@/backend/manager/CellManager';

export function useVariableManager(cellId: string) {
  // Get managers
  const moduleManager = ModuleManager.getInstance();
  const globalManager = GlobalManager.getInstance();
  const cellManager = CellManager.getInstance();

  // Find the module containing this cell
  const getModule = useCallback(() => {
    return moduleManager.getAllModules().find(m => m.cellIds.includes(cellId));
  }, [cellId]);

  // Get global variables for the module
  const getGlobalVariables = useCallback(() => {
    const module = getModule();
    if (!module) return new Map<string, VariableRecord>();

    return module.globalFileIds.reduce((acc, fileId) => {
      const variables = globalManager.getVariablesForFile(fileId);
      variables.forEach((value, key) => acc.set(key, value));
      return acc;
    }, new Map<string, VariableRecord>());
  }, [getModule]);

  // Combine global and local variables
  const combinedVariables = useMemo(() => {
    const module = getModule();
    if (!module) return new Map<string, VariableRecord>();

    // Get global variables
    const globalVars = getGlobalVariables();

    // Get local variables from the cell
    const cell = cellManager.getCellsForModule(module.card.id)
      .find(c => c.id === cellId);
    const localVars = cell?.localVariables || new Map<string, VariableRecord>();

    // Combine them (local variables override global ones if there's a naming conflict)
    return new Map([...globalVars, ...localVars]);
  }, [cellId, getGlobalVariables, getModule]);

  const module = getModule();
  const cell = module ? cellManager.getCellsForModule(module.card.id)
    .find(c => c.id === cellId) : null;
  const localVariables = cell?.localVariables || new Map();

  return {
    variables: combinedVariables,
    module,
    getGlobalVariables,
    localVariables
  };
} 