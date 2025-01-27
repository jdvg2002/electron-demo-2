import sys
import math
sys.path.append('/Applications/FreeCAD.app/Contents/Resources/lib')
sys.path.append('/Applications/FreeCAD.app/Contents/Resources/lib/python3.11/site-packages')

import os
os.environ['PATH_TO_FREECAD_LIBDIR'] = '/Applications/FreeCAD.app/Contents/Resources/lib'

import FreeCAD
import Import

def find_cylinder_centers(shape):
    cylinder_data = []
    for face in shape.Faces:
        if face.Surface.TypeId == 'Part::GeomCylinder':
            cylinder = face.Surface
            # Convert Vector to tuple for dictionary key
            center_tuple = (cylinder.Center.x, cylinder.Center.y, cylinder.Center.z)
            cylinder_data.append((cylinder.Radius, center_tuple))
    
    # Group by center point
    centers = {}
    tolerance = 0.1  # mm
    for radius, center in cylinder_data:
        found = False
        for existing_center in centers.keys():
            # Check distance between points
            dx = center[0] - existing_center[0]
            dy = center[1] - existing_center[1]
            dz = center[2] - existing_center[2]
            distance = (dx*dx + dy*dy + dz*dz)**0.5
            if distance < tolerance:
                centers[existing_center].append(radius)
                found = True
                break
        if not found:
            centers[center] = [radius]
    
    return centers

def analyze_hole_pattern(shape, main_center):
    hole_pattern = []
    for face in shape.Faces:
        if face.Surface.TypeId == 'Part::GeomCylinder':
            if abs(face.Surface.Radius - 11.15) < 0.01:  # This is a hole
                center = face.Surface.Center
                # Calculate height relative to main center
                height = center.z - main_center[2]
                # Calculate radius and angle from main center
                dx = center.x - main_center[0]
                dy = center.y - main_center[1]
                radius = (dx*dx + dy*dy)**0.5
                angle = math.degrees(math.atan2(dy, dx))
                hole_pattern.append((height, radius, angle))
    
    # Sort by height
    return sorted(hole_pattern, key=lambda x: x[0], reverse=True)

def analyze_component(obj):
    print(f"\nAnalyzing {obj.Label}:")
    shape = obj.Shape
    
    # Get concentric cylinders
    centers = find_cylinder_centers(shape)
    print("\nCylindrical features:")
    for center, radii in centers.items():
        print(f"Center at {center}")
        print(f"Has cylinders with radii: {sorted(radii)}")
    
    # Get any conical faces
    print("\nConical features:")
    for face in shape.Faces:
        if face.Surface.TypeId == 'Part::GeomCone':
            cone = face.Surface
            print(f"Cone from {cone.Center} to {cone.Apex}")
            length = (cone.Apex - cone.Center).Length
            print(f"Cone length: {length:.2f}mm")
    
    # Get overall dimensions
    bbox = shape.BoundBox
    print(f"\nOverall dimensions:")
    print(f"Length (X): {bbox.XLength:.2f}mm")
    print(f"Width (Y): {bbox.YLength:.2f}mm")
    print(f"Height (Z): {bbox.ZLength:.2f}mm")
    
    # If we found any holes, analyze their pattern
    main_centers = [center for center, radii in centers.items() 
                   if any(r > 30 for r in radii)]  # Look for centers with large radii
    
    if main_centers:
        main_center = main_centers[0]  # Use the first major center found
        holes = analyze_hole_pattern(shape, main_center)
        if holes:
            print("\nHole pattern:")
            for height, radius, angle in holes:
                print(f"Hole at height {height:6.2f}mm, radius {radius:6.2f}mm, angle {angle:6.1f}°")
    
    print("-" * 80)

def is_flange(shape):
    # Get all cylinder centers and their radii
    centers = find_cylinder_centers(shape)
    
    # Characteristics that suggest a flange:
    flange_characteristics = {
        'has_concentric_cylinders': False,
        'has_bolt_pattern': False,
        'bolt_count': 0,
        'main_diameters': [],
        'bolt_diameter': None
    }
    
    # Look for concentric cylinders (main body)
    for center, radii in centers.items():
        unique_radii = sorted(set([round(r, 2) for r in radii]))
        if len(unique_radii) >= 2:  # At least 2 different radii at same center
            large_radii = [r for r in unique_radii if r > 15]  # Larger than 30mm diameter
            if large_radii:
                flange_characteristics['has_concentric_cylinders'] = True
                flange_characteristics['main_diameters'] = [r * 2 for r in large_radii]
    
    # Look for bolt pattern (similar small cylinders)
    bolt_holes = []
    for center, radii in centers.items():
        # Look for repeated small radii (likely bolt holes)
        small_radii = [r for r in radii if r < 15]  # Less than 30mm diameter
        if small_radii:
            avg_radius = sum(small_radii) / len(small_radii)
            if not flange_characteristics['bolt_diameter']:
                flange_characteristics['bolt_diameter'] = avg_radius * 2
            bolt_holes.append(center)
    
    if len(bolt_holes) >= 3:  # At least 3 holes to form a pattern
        flange_characteristics['has_bolt_pattern'] = True
        flange_characteristics['bolt_count'] = len(bolt_holes)
    
    # Determine if it's likely a flange
    is_likely_flange = (flange_characteristics['has_concentric_cylinders'] and 
                       flange_characteristics['has_bolt_pattern'])
    
    return is_likely_flange, flange_characteristics

def is_bend(shape):
    # Characteristics that suggest a bend:
    bend_characteristics = {
        'has_toroidal_face': False,
        'has_consistent_diameter': False,
        'bend_angle': None,
        'bend_radius': None,
        'pipe_diameter': None,
        'wall_thickness': None
    }
    
    # Look for toroidal faces (the curved section of the bend)
    toroid_radii = []
    for face in shape.Faces:
        if face.Surface.TypeId == 'Part::GeomToroid':
            bend_characteristics['has_toroidal_face'] = True
            toroid_radii.append(face.Surface.MinorRadius)
    
    if bend_characteristics['has_toroidal_face']:
        # Sort radii to find inner and outer diameter
        unique_radii = sorted(set([round(r, 2) for r in toroid_radii]))
        if len(unique_radii) == 2:  # We have inner and outer radius
            bend_characteristics['has_consistent_diameter'] = True
            bend_characteristics['wall_thickness'] = unique_radii[1] - unique_radii[0]
            bend_characteristics['pipe_diameter'] = unique_radii[0] * 2  # Inner diameter
            
            # Get bend radius (to centerline)
            for face in shape.Faces:
                if face.Surface.TypeId == 'Part::GeomToroid':
                    bend_characteristics['bend_radius'] = face.Surface.MajorRadius
                    break
            
            # Try to determine bend angle from planar faces
            planar_faces = [f for f in shape.Faces if f.Surface.TypeId == 'Part::GeomPlane']
            if len(planar_faces) >= 2:
                # Get normals of end faces
                normals = [f.normalAt(0,0) for f in planar_faces]
                if len(normals) >= 2:
                    # Calculate angle between first two normals
                    dot_product = normals[0].dot(normals[1])
                    bend_characteristics['bend_angle'] = math.degrees(math.acos(abs(dot_product)))
    
    # Determine if it's likely a bend
    is_likely_bend = (bend_characteristics['has_toroidal_face'] and 
                     bend_characteristics['has_consistent_diameter'])
    
    return is_likely_bend, bend_characteristics

def is_pipe(shape):
    # Characteristics that suggest a pipe:
    pipe_characteristics = {
        'has_concentric_cylinders': False,
        'has_consistent_diameter': False,
        'inner_diameter': None,
        'outer_diameter': None,
        'wall_thickness': None,
        'length': None
    }
    
    # Get all cylinder centers and their radii
    centers = find_cylinder_centers(shape)
    
    # Look for pairs of concentric cylinders
    for center, radii in centers.items():
        unique_radii = sorted(set([round(r, 2) for r in radii]))
        if len(unique_radii) == 2:  # We need exactly 2 different radii for inner/outer
            inner_radius = unique_radii[0]
            outer_radius = unique_radii[1]
            
            # Check if the difference makes sense for a pipe wall
            wall_thickness = outer_radius - inner_radius
            if 1 < wall_thickness < 20:  # Reasonable wall thickness range in mm
                pipe_characteristics['has_concentric_cylinders'] = True
                pipe_characteristics['has_consistent_diameter'] = True
                pipe_characteristics['inner_diameter'] = inner_radius * 2
                pipe_characteristics['outer_diameter'] = outer_radius * 2
                pipe_characteristics['wall_thickness'] = wall_thickness
                
                # Get length from bounding box
                bbox = shape.BoundBox
                pipe_characteristics['length'] = max(bbox.XLength, bbox.YLength, bbox.ZLength)
    
    # Determine if it's likely a pipe
    is_likely_pipe = (pipe_characteristics['has_concentric_cylinders'] and 
                     pipe_characteristics['has_consistent_diameter'])
    
    return is_likely_pipe, pipe_characteristics

def main():
    # Create new document and import STEP
    doc = FreeCAD.newDocument()
    Import.insert("/Users/emanuel/electron-demo-2/PP-(012)2400.STEP", doc.Name)
    
    print("\nAnalyzing components:")
    print("-" * 50)
    
    # Handle both grouped and ungrouped components
    components = []
    for obj in doc.RootObjects:
        if hasattr(obj, 'Group'):
            components.extend(obj.Group)
        else:
            components.append(obj)
    
    for obj in components:
        is_likely_flange, flange_chars = is_flange(obj.Shape)
        is_likely_bend, bend_chars = is_bend(obj.Shape)
        is_likely_pipe, pipe_chars = is_pipe(obj.Shape)
        
        if is_likely_flange:
            print(f"\nComponent {obj.Label} appears to be a flange:")
            print(f"Main diameters: {[f'{d:.1f}mm' for d in flange_chars['main_diameters']]}")
            print(f"Bolt hole diameter: {flange_chars['bolt_diameter']:.1f}mm")
            print(f"Number of bolt holes: {flange_chars['bolt_count']}")
        
        elif is_likely_bend:
            print(f"\nComponent {obj.Label} appears to be a pipe bend:")
            print(f"Pipe inner diameter: {bend_chars['pipe_diameter']:.1f}mm")
            print(f"Wall thickness: {bend_chars['wall_thickness']:.1f}mm")
            if bend_chars['bend_angle']:
                print(f"Bend angle: {bend_chars['bend_angle']:.1f}°")
            if bend_chars['bend_radius']:
                print(f"Bend radius: {bend_chars['bend_radius']:.1f}mm")
        
        elif is_likely_pipe:
            print(f"\nComponent {obj.Label} appears to be a pipe:")
            print(f"Inner diameter: {pipe_chars['inner_diameter']:.1f}mm")
            print(f"Outer diameter: {pipe_chars['outer_diameter']:.1f}mm")
            print(f"Wall thickness: {pipe_chars['wall_thickness']:.1f}mm")
            print(f"Length: {pipe_chars['length']:.1f}mm")
        
        else:
            print(f"\nComponent {obj.Label} is not a recognized type")

if __name__ == "__main__":
    main()