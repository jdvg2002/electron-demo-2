from dataclasses import dataclass
from Distribution import Distribution

@dataclass
class Variable:
    """
    Class representing a variable with its uncertainty parameters
    
    Attributes:
        name: variable name
        value: Nominal/mean value
        distribution: Type of distribution (currently only NORMAL supported)
        uncertainty: Uncertainty value (std dev for normal distribution)
    """
    name: str
    value: float
    distribution: Distribution
    uncertainty: float
    
    def __post_init__(self):
        # Validate other fields
        if not isinstance(self.name, str):
            raise ValueError(f"Name must be a string, got {type(self.name)}")
        if len(self.name) >= 16:
            raise ValueError(f"Name must be less than 16 characters, got {len(self.name)}")
        if not isinstance(self.value, (int, float)):
            raise ValueError(f"Value must be a number, got {type(self.value)}")
        if not isinstance(self.uncertainty, (int, float)):
            raise ValueError(f"Uncertainty must be a number, got {type(self.uncertainty)}")