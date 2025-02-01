import React from 'react';
import { Canvas } from '@react-three/fiber'
import { OrbitControls, Stage } from '@react-three/drei'
import { useLoader } from '@react-three/fiber'
import { STLLoader } from 'three/examples/jsm/loaders/STLLoader'
import { Suspense } from 'react';
import * as THREE from 'three';

const Model = React.memo(({ file }: { file: File }) => {
  const [geometry, setGeometry] = React.useState<THREE.BufferGeometry | null>(null);
  
  React.useEffect(() => {
    const loader = new STLLoader();
    const reader = new FileReader();
    
    reader.onload = (event) => {
      if (event.target?.result) {
        const geometry = loader.parse(event.target.result as ArrayBuffer);
        setGeometry(geometry);
      }
    };
    
    reader.readAsArrayBuffer(file);
  }, [file]);

  if (!geometry) return null;
  
  return (
    <mesh geometry={geometry} scale={[0.1, 0.1, 0.1]}>
      <meshStandardMaterial color="#b8b8b8" />
    </mesh>
  );
});

interface StableSTLViewerProps {
  file: File;
}

const StableSTLViewer = React.memo(({ file }: StableSTLViewerProps) => {
  // Ensure file is valid before rendering
  if (!file || !(file instanceof File)) {
    return null;
  }

  return (
    <div className="w-full h-full">
      <Suspense fallback={<div>Loading model...</div>}>
        <Canvas>
          <Stage environment="city" intensity={0.6}>
            <Model file={file} />
          </Stage>
          <OrbitControls 
            makeDefault
            minPolarAngle={0}
            maxPolarAngle={Math.PI / 1.75}
          />
        </Canvas>
      </Suspense>
    </div>
  );
});

export default StableSTLViewer; 