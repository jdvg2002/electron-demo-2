import React from 'react';
import { Canvas } from '@react-three/fiber';
import { useGLTF } from '@react-three/drei';
import { OrbitControls, Stage } from '@react-three/drei';
import { Suspense } from 'react';

const Model = React.memo(({ url }: { url: string }) => {
  const { scene } = useGLTF(url);
  return <primitive object={scene} />;
});

const StableGLTFViewer: React.FC<{ file: File }> = ({ file }) => {
  const [url, setUrl] = React.useState<string | null>(null);

  React.useEffect(() => {
    if (!file) return;

    // Create blob URL with binary MIME type
    const objectUrl = URL.createObjectURL(
      new Blob([file], { type: 'model/gltf-binary' })
    );
    setUrl(objectUrl);
    
    return () => {
      if (objectUrl) {
        URL.revokeObjectURL(objectUrl);
      }
    };
  }, [file]);

  if (!url) {
    return <div>Loading...</div>;
  }

  return (
    <div style={{ width: '100%', height: '100%' }}>
      <Canvas>
        <Suspense fallback={null}>
          <Stage environment="city" intensity={0.6}>
            <Model url={url} />
          </Stage>
          <OrbitControls makeDefault />
        </Suspense>
      </Canvas>
    </div>
  );
};

Model.displayName = 'GLTFModel';
StableGLTFViewer.displayName = 'StableGLTFViewer';

export default StableGLTFViewer; 