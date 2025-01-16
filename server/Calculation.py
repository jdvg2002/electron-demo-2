from enum import Enum
from dataclasses import dataclass

class CalculationType(Enum):
    FLOW_STRESS = 'flow_stress'
    FATIGUE_CRACK_INIT = 'fatigue_crack_init'

@dataclass
class Calculation:
    """A class representing different types of calculations
    
    Attributes:
        calculation_type: The type of calculation (FLOW_STRESS)
    """
    calculation_type: CalculationType

    def __post_init__(self):
        if self.calculation_type is None:
            raise ValueError("Calculation type cannot be None")
        if not isinstance(self.calculation_type, CalculationType):
            raise ValueError(f"Calculation type must be a CalculationType enum member, got {type(self.calculation_type)}") 