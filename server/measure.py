import FreeCAD
import FreeCADGui
import Part
import Import
import sys

def measure_parts(stepfile):
    # 1. Create (or reuse) a FreeCAD document
    doc_name = "MyStepDoc"
    # If a doc with this name already exists, reuse it, else create new
    if FreeCAD.activeDocument() and FreeCAD.activeDocument().Name == doc_name:
        doc = FreeCAD.activeDocument()
    else:
        doc = FreeCAD.newDocument(doc_name)

    # 2. Import the STEP file. FreeCAD automatically creates separate
    #    "Part__Feature" objects if the STEP has multiple solids/parts.
    Import.open(stepfile)

    # 3. Each top-level "part" is now in doc.Objects. 
    #    They might be "Part__Feature" or "App::Part" or "Body" objects, etc.
    #    We'll measure bounding boxes for each:

    results = []
    for obj in doc.Objects:
        # We skip any non-Part or special objects if needed
        if hasattr(obj, 'Shape'):
            shape = obj.Shape
            if shape is not None and not shape.isNull():
                bound = shape.BoundBox
                dx = bound.XLength
                dy = bound.YLength
                dz = bound.ZLength
                results.append((obj.Name, dx, dy, dz))

    return results

def main():
    if len(sys.argv) < 2:
        print("Usage: freecadcmd measure.py your_assembly.step")
        sys.exit(1)
    stepfile = sys.argv[1]
    results = measure_parts(stepfile)
    for (objname, dx, dy, dz) in results:
        print(f"Object {objname}: bounding box dx={dx:.3f}, dy={dy:.3f}, dz={dz:.3f}")

if __name__ == "__main__":
    main()
