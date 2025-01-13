from enum import Enum
from dataclasses import dataclass

class MeshType(Enum):
    PIPE = 'PIPE'

@dataclass
class Mesh:
    """A class representing different types of meshes
    
    Attributes:
        mesh_type: The type of mesh (PIPE)
    """
    mesh_type: MeshType

    def __post_init__(self):
        if self.mesh_type is None:
            raise ValueError("Mesh type cannot be None")
        if not isinstance(self.mesh_type, MeshType):
            raise ValueError(f"Mesh type must be a MeshType enum member, got {type(self.mesh_type)}") 