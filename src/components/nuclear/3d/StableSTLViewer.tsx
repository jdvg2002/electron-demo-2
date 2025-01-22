import React from 'react';
import { Canvas } from '@react-three/fiber'
import { OrbitControls, Stage } from '@react-three/drei'
import { useLoader } from '@react-three/fiber'
import { STLLoader } from 'three/examples/jsm/loaders/STLLoader'
import { Suspense } from 'react';

// Create a stable reference for storing URLs
const urlCache = new Map<string, string>();

const Model = React.memo(({ url }: { url: string }) => {
  const geometry = useLoader(STLLoader, url)
  return (
    <mesh geometry={geometry}>
      <meshStandardMaterial color="#b8b8b8" />
    </mesh>
  )
});

interface StableSTLViewerProps {
  file: File;
}

const StableSTLViewer = React.memo(({ file }: StableSTLViewerProps) => {
  const [objectUrl, setObjectUrl] = React.useState<string | null>(null);

  React.useEffect(() => {
    // Generate a unique key for this file
    const fileKey = `${file.name}-${file.size}-${file.lastModified}`;
    
    // Check if we already have a URL for this file
    let url = urlCache.get(fileKey);
    
    if (!url) {
      // Only create a new URL if we don't have one cached
      url = URL.createObjectURL(file);
      urlCache.set(fileKey, url);
    }
    
    setObjectUrl(url);

    // Cleanup function
    return () => {
      // Only revoke the URL when the component is fully unmounted
      // and the file has changed
      if (!urlCache.has(fileKey)) {
        URL.revokeObjectURL(url!);
      }
    };
  }, [file.name, file.size, file.lastModified]);

  if (!objectUrl) return null;

  return (
    <div className="w-full h-full">
      <Suspense fallback={<div>Loading model...</div>}>
        <Canvas>
          <Stage environment="city" intensity={0.6}>
            <Model url={objectUrl} />
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

// Add a cleanup method that can be called when needed
StableSTLViewer.clearUrlCache = () => {
  urlCache.forEach(url => URL.revokeObjectURL(url));
  urlCache.clear();
};

StableSTLViewer.displayName = 'StableSTLViewer';

export default StableSTLViewer; 