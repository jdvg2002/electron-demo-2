from enum import Enum
from dataclasses import dataclass

class DistributionType(Enum):
    NORMAL = 'NORMAL'

@dataclass
class Distribution:
    """A class representing statistical distributions
    
    Attributes:
        distribution: The type of distribution (currently only NORMAL is supported)
    """
    distribution: DistributionType

    def __post_init__(self):
        if self.distribution is None:
            raise ValueError("Distribution cannot be None")
        if not isinstance(self.distribution, DistributionType):
            raise ValueError(f"Distribution must be a DistributionType enum member, got {type(self.distribution)}")