const { parentPort } = require('worker_threads');

let currentChunkIndex = 0;

parentPort?.on('message', async (task) => {
  try {
    const { chunk, chunkIndex } = task;
    currentChunkIndex = chunkIndex;
    console.log(`Worker starting chunk ${chunkIndex}, size: ${chunk.byteLength} bytes`);
    
    // Convert ArrayBuffer to string for processing
    const decoder = new TextDecoder();
    const chunkText = decoder.decode(chunk);
    console.log(`Chunk ${chunkIndex} decoded, length: ${chunkText.length} chars`);
    
    // Process STEP file chunk
    const entities = parseStepChunk(chunkText);
    console.log(`Chunk ${chunkIndex} processed, found ${entities.length} entities`);
    
    parentPort?.postMessage({
      chunkIndex,
      entities,
      success: true
    });
    console.log(`Chunk ${chunkIndex} result sent back`);
  } catch (error) {
    console.error(`Error processing chunk ${currentChunkIndex}:`, error);
    parentPort?.postMessage({
      chunkIndex: currentChunkIndex,
      error: error instanceof Error ? error.message : String(error),
      success: false
    });
  }
});

function parseStepChunk(chunkText) {
  const entities = [];
  const lines = chunkText.split('\n');
  
  for (const line of lines) {
    if (line.startsWith('#')) {
      const [id, ...rest] = line.split('=').map(s => s.trim());
      entities.push({
        id: id.substring(1), // Remove '#'
        data: rest.join('=')
      });
    }
  }
  
  return entities;
}

module.exports = {}; 