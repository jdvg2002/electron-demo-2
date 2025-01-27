export interface VariableRecord {
  id: string;
  fileId: string;
  type: 'measurement' | 'distribution';
  name: string;
  value?: number;  // for measurements
  mean?: number;   // for distributions
  stdDev?: number; // for distributions
  units?: string;
  label?: string;
  _delete?: boolean; // Flag to indicate if this variable should be deleted
}

export class VariableManager {
  private variables: Map<string, VariableRecord> = new Map();

  addVariable(record: Omit<VariableRecord, 'id'>): string {
    const id = crypto.randomUUID();
    const variableRecord: VariableRecord = { id, ...record };
    this.variables.set(id, variableRecord);
    return id;
  }

  getVariable(id: string): VariableRecord | undefined {
    return this.variables.get(id);
  }

  getVariablesForFile(fileId: string): VariableRecord[] {
    return Array.from(this.variables.values())
      .filter(variable => variable.fileId === fileId);
  }

  removeVariablesForFile(fileId: string): void {
    for (const [varId, variable] of this.variables.entries()) {
      if (variable.fileId === fileId) {
        this.variables.delete(varId);
      }
    }
  }
} 