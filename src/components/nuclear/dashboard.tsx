import React, { useState, useEffect } from 'react';
import { Card } from '@/components/ui/card';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { motion, AnimatePresence } from 'framer-motion';
import Demo from './demo';
import FileUploadSection from './FileUploadSection';
import { GlobalFileManager } from '@/backend/models/GlobalFiles';
import { CellData } from '@/backend/models/Cell';

const DraggableCardsCanvas = () => {
  const manager = ModuleManager.getInstance();
  const fileManager = GlobalFileManager.getInstance();
  const [modules, setModules] = useState(manager.getAllModules());
  const [wires, setWires] = useState([]);
  const [isWiring, setIsWiring] = useState(false);
  const [activeWire, setActiveWire] = useState<{
    startCard: number;
    startX: number;
    startY: number;
    startRelX: number;
    startRelY: number;
    mouseX?: number;
    mouseY?: number;
  } | null>(null);

  const [editingCard, setEditingCard] = useState<number | null>(null);
  const [recentlyDragged, setRecentlyDragged] = useState(false);
  const [dragStart, setDragStart] = useState<{ x: number; y: number } | null>(null);
  const [pendingDragCard, setPendingDragCard] = useState<number | null>(null);
  const [expandedCard, setExpandedCard] = useState<number | null>(null);
  const [dashboardTitle, setDashboardTitle] = useState("Analysis");

  // Reflect changes from manager if storing wires/modules somewhere else
  useEffect(() => {
    const storedModules = manager.getAllModules();
    setModules([...storedModules]);
  }, []);

  useEffect(() => {
    // Keep wires in internal state synchronized
    // Comment out or remove wire-related code for now
    // manager.setWires(wires);
  }, [wires]);

  useEffect(() => {
    const handleGlobalMouseUp = () => {
      setDragStart(null);
      setPendingDragCard(null);
      const anyDragging = modules.some(m => m.card.isDragging);
      if (anyDragging) {
        setRecentlyDragged(true);
        setTimeout(() => setRecentlyDragged(false), 100);
      }
      modules.forEach(m => m.card.isDragging = false);
      setModules([...modules]);
    };

    window.addEventListener('mouseup', handleGlobalMouseUp);
    return () => window.removeEventListener('mouseup', handleGlobalMouseUp);
  }, [modules]);

  const handleMouseMove = (e: React.MouseEvent<HTMLDivElement>) => {
    if (dragStart && pendingDragCard) {
      const dx = Math.abs(e.clientX - dragStart.x);
      const dy = Math.abs(e.clientY - dragStart.y);

      // Only start dragging if mouse has moved more than 3 pixels
      if (dx > 3 || dy > 3) {
        const draggingModule = modules.find(m => m.card.id === pendingDragCard);
        if (draggingModule) {
          draggingModule.card.isDragging = true;
          setModules([...modules]);
        }
      }
    }

    const canvasRect = e.currentTarget.getBoundingClientRect();
    const mouseX = e.clientX - canvasRect.left;
    const mouseY = e.clientY - canvasRect.top;

    if (activeWire) {
      setActiveWire({
        ...activeWire,
        mouseX,
        mouseY,
      });
    }

    const draggingModule = modules.find(m => m.card.isDragging);
    if (draggingModule) {
      const canvasRect = e.currentTarget.getBoundingClientRect();
      const cardWidth = 256; // w-64 = 16rem = 256px
      const cardHeight = 100; // Approximate height of card
      
      // Calculate new position with boundaries
      let newX = e.clientX - canvasRect.left - draggingModule.card.dragOffset.x;
      let newY = e.clientY - canvasRect.top - draggingModule.card.dragOffset.y;
      
      // Constrain to canvas boundaries
      newX = Math.max(0, Math.min(newX, canvasRect.width - cardWidth));
      newY = Math.max(0, Math.min(newY, canvasRect.height - cardHeight));

      // Update module position directly on the card object
      draggingModule.card.x = newX;
      draggingModule.card.y = newY;
      
      // Update wires immediately before re-rendering modules
      updateConnectedWirePositions(draggingModule.card.id, newX, newY, e.currentTarget);
      
      // Update modules state
      setModules([...modules]);
    }
  };

  const handleMouseUp = () => {
    // Only handle canvas-specific cleanup if needed
  };

  const updateConnectedWirePositions = (
    cardId: number,
    newX: number,
    newY: number,
    canvasElement: HTMLDivElement
  ) => {
    const updated = wires.map(wire => {
      if (wire.startCard === cardId || wire.endCard === cardId) {
        // Get the card's dimensions from its element
        const cardElement = canvasElement.querySelector(`[data-card-id="${cardId}"]`) as HTMLDivElement;
        if (!cardElement) return wire;

        // Use the actual dimensions of the card
        const cardRect = {
          x: newX,
          y: newY,
          width: cardElement.offsetWidth,
          height: cardElement.offsetHeight
        };

        if (wire.startCard === cardId) {
          // Update start position using relative coordinates
          return {
            ...wire,
            startX: cardRect.x + (wire.startRelX * cardRect.width),
            startY: cardRect.y + (wire.startRelY * cardRect.height)
          };
        } else {
          // Update end position using relative coordinates
          return {
            ...wire,
            endX: cardRect.x + (wire.endRelX * cardRect.width),
            endY: cardRect.y + (wire.endRelY * cardRect.height)
          };
        }
      }
      return wire;
    });

    setWires(updated);
  };

  const handleMouseDown = (e: React.MouseEvent<HTMLDivElement>, cardId: number) => {
    if (editingCard !== null || isWiring) return;
    
    const found = modules.find(m => m.card.id === cardId);
    if (!found) return;

    setDragStart({ x: e.clientX, y: e.clientY });
    setPendingDragCard(cardId);

    const rect = (e.currentTarget as HTMLDivElement).getBoundingClientRect();
    const offsetX = e.clientX - rect.left;
    const offsetY = e.clientY - rect.top;

    found.card.dragOffset = { x: offsetX, y: offsetY };
    setModules([...modules]);
  };

  const handleCardClick = (
    e: React.MouseEvent<HTMLDivElement>,
    cardId: number
  ) => {
    if (isWiring) {
      // Get the canvas element and pass it to wireLogic
      const canvasElement = e.currentTarget.closest('[data-canvas]') as HTMLDivElement;
      if (canvasElement) {
        wireLogic(e, cardId, canvasElement);
      }
      return;
    }
    const found = modules.find(m => m.card.id === cardId);
    if (!found) return;

    if (found.card.isDragging || modules.some(m => m.card.isDragging) || recentlyDragged) {
      return;
    }
    if (editingCard !== null) return;

    setExpandedCard(cardId);
  };

  const handleClose = () => {
    setExpandedCard(null);
  };

  const wireLogic = (
    e: React.MouseEvent<HTMLDivElement>, 
    cardId: number, 
    canvasRef: HTMLDivElement
  ) => {
    console.log('Wire Logic Called:', { 
      cardId, 
      isWiring, 
      activeWire: activeWire ? { ...activeWire } : null,
      existingWires: wires.length 
    });

    // If we're not in wiring mode, don't do anything
    if (!isWiring) {
      console.log('Not in wiring mode, returning');
      return;
    }

    const canvasRect = canvasRef.getBoundingClientRect();
    const cardElement = e.currentTarget as HTMLDivElement;
    const cardRect = cardElement.getBoundingClientRect();
    
    const mouseX = e.clientX - canvasRect.left;
    const mouseY = e.clientY - canvasRect.top;

    const localCardRect = {
      x: cardRect.left - canvasRect.left,
      y: cardRect.top - canvasRect.top,
      width: cardRect.width,
      height: cardRect.height
    };
    const snapPoint = getSnapPoint(localCardRect, mouseX, mouseY);

    if (!activeWire) {
      console.log('Starting new wire from card:', cardId);
      setActiveWire({
        startCard: cardId,
        startX: snapPoint.x,
        startY: snapPoint.y,
        startRelX: snapPoint.relX,
        startRelY: snapPoint.relY
      });
    } else {
      console.log('Completing wire:', { 
        startCard: activeWire.startCard, 
        endCard: cardId 
      });
      
      // Get source module's postprocessing cell data
      const sourceModule = modules.find(m => m.card.id === activeWire.startCard);
      const destinationModule = modules.find(m => m.card.id === cardId);
      
      if (sourceModule && destinationModule) {
        const postprocessingCell = sourceModule.cells.find(
          cell => cell.type === 'postprocessing' && cell.output?.postProcessedData
        );
        
        const preprocessingCell = destinationModule.cells.find(
          cell => cell.type === 'preprocessing'
        );

        if (postprocessingCell?.output?.postProcessedData && preprocessingCell) {
          // Update the preprocessing cell with the input data
          const updatedCell: CellData = {
            ...preprocessingCell,
            input: {
              sourceModuleId: sourceModule.card.id,
              inputData: {
                type: 'wired_input',
                version: '1.0',
                timestamp: new Date().toISOString(),
                data: postprocessingCell.output.postProcessedData,
                metadata: {
                  sourceModule: sourceModule.card.title,
                  sourceCell: postprocessingCell.title
                }
              }
            }
          };

          // Update the module's cells
          destinationModule.updateCell(updatedCell);
          manager.updateModuleCells(destinationModule.card.id, destinationModule.cells);
        }
      }

      // Create the wire as before
      const newWire = {
        id: wires.length,
        startCard: activeWire.startCard,
        endCard: cardId,
        startX: activeWire.startX,
        startY: activeWire.startY,
        endX: snapPoint.x,
        endY: snapPoint.y,
        startRelX: activeWire.startRelX,
        startRelY: activeWire.startRelY,
        endRelX: snapPoint.relX,
        endRelY: snapPoint.relY
      };
      setWires([...wires, newWire]);
      setActiveWire(null);
      setIsWiring(false);
    }
  };

  const getSnapPoint = (
    cardRect: { x: number; y: number; width: number; height: number },
    mouseX: number,
    mouseY: number
  ) => {
    const distToLeft = Math.abs(mouseX - cardRect.x);
    const distToRight = Math.abs(mouseX - (cardRect.x + cardRect.width));
    const distToTop = Math.abs(mouseY - cardRect.y);
    const distToBottom = Math.abs(mouseY - (cardRect.y + cardRect.height));
    const minDist = Math.min(distToLeft, distToRight, distToTop, distToBottom);

    if (minDist === distToLeft) {
      return {
        x: cardRect.x,
        y: mouseY,
        relX: 0,
        relY: (mouseY - cardRect.y) / cardRect.height
      };
    } else if (minDist === distToRight) {
      return {
        x: cardRect.x + cardRect.width,
        y: mouseY,
        relX: 1,
        relY: (mouseY - cardRect.y) / cardRect.height
      };
    } else if (minDist === distToTop) {
      return {
        x: mouseX,
        y: cardRect.y,
        relX: (mouseX - cardRect.x) / cardRect.width,
        relY: 0
      };
    } else {
      return {
        x: mouseX,
        y: cardRect.y + cardRect.height,
        relX: (mouseX - cardRect.x) / cardRect.width,
        relY: 1
      };
    }
  };

  const addNewCard = () => {
    const globalFiles = fileManager.getAllFiles();
    const newModule = manager.createPreprocessingModuleWithGlobalFiles(globalFiles);
    setModules([...modules, newModule]);
  };

  const updateCardText = (moduleId: number, field: 'title' | 'content', value: string) => {
    const targetModule = modules.find(m => m.card.id === moduleId);
    if (!targetModule) return;

    if (field === 'title') {
      targetModule.card.title = value;
    } else {
      targetModule.card.content = value;
    }
    
    manager.updateModuleCard(moduleId, { [field]: value });
    setModules([...modules]);
  };

  const startWiring = () => {
    console.log('Starting wiring mode');
    setIsWiring(true);
    setActiveWire(null);
  };

  return (
    <div className="w-full h-full bg-[#003449] flex flex-col gap-6 p-4">
      <div className="relative w-1/2">
        <span
          className="absolute inset-0 cursor-text flex"
        >
          <textarea
            value={dashboardTitle}
            onChange={(e) => setDashboardTitle(e.target.value)}
            className="text-2xl font-bold text-white bg-transparent w-full border-none focus:outline-none focus:ring-1 focus:ring-blue-500 rounded px-1 cursor-text break-words resize-none overflow-hidden"
            rows={1}
            style={{ height: 'auto' }}
          />
        </span>
        <span className="text-2xl font-bold text-white invisible whitespace-pre-wrap break-words">
          {dashboardTitle || '\u00A0'.repeat(10)}
        </span>
      </div>

      <FileUploadSection />
      
      <div className="flex gap-4">
        <button
          onClick={addNewCard}
          className="bg-[#0086bb] hover:bg-[#4fcdff] text-white px-4 py-2 rounded w-32"
        >
          Add Module
        </button>
        <button
          onClick={startWiring}
          className={`px-4 py-2 rounded w-32 ${
            isWiring
              ? 'bg-green-500 hover:bg-green-600 text-white'
              : 'bg-[#0086bb] hover:bg-[#4fcdff] text-white'
          }`}
        >
          {isWiring ? 'Linking...' : 'Add Link'}
        </button>
      </div>

      <div
        data-canvas
        className={`w-full h-96 bg-[#f6f6f6] border-2 border-gray-200 rounded-lg relative ${
          modules.some(m => m.card.isDragging) ? 'select-none' : ''
        }`}
        onMouseMove={handleMouseMove}
        onMouseUp={handleMouseUp}
        onMouseLeave={handleMouseUp}
      >
        <svg className="absolute inset-0 w-full h-full pointer-events-none">
          {wires.map(wire => {
            const dx = wire.endX - wire.startX;
            const dy = wire.endY - wire.startY;
            const distance = Math.sqrt(dx * dx + dy * dy);
            
            // Adjust control point distance based on wire length
            const controlDistance = Math.min(distance * 0.5, 100);
            
            // Determine control points based on relative positions
            let c1x, c1y, c2x, c2y;
            
            // If start is to the left of end
            if (wire.startX < wire.endX) {
              c1x = wire.startX + controlDistance;
              c2x = wire.endX - controlDistance;
            } else {
              c1x = wire.startX - controlDistance;
              c2x = wire.endX + controlDistance;
            }
            
            // Keep vertical positions aligned with endpoints
            c1y = wire.startY;
            c2y = wire.endY;

            const path = `M ${wire.startX} ${wire.startY}
              C ${c1x} ${c1y},
                ${c2x} ${c2y},
                ${wire.endX} ${wire.endY}`;

            return (
              <path
                key={wire.id}
                d={path}
                fill="none"
                stroke="#2563eb"
                strokeWidth="2"
              />
            );
          })}
          {activeWire && (
            <path
              d={`M ${activeWire.startX} ${activeWire.startY}
                C ${activeWire.startX + 100} ${activeWire.startY},
                  ${(activeWire.mouseX || activeWire.startX) - 100} ${activeWire.mouseY || activeWire.startY},
                  ${activeWire.mouseX || activeWire.startX} ${activeWire.mouseY || activeWire.startY}`}
              fill="none"
              stroke="#2563eb"
              strokeWidth="2"
              strokeDasharray="4"
            />
          )}
        </svg>

        <AnimatePresence>
          {modules.map(mod => {
            const isExpanded = mod.card.id === expandedCard;
            
            return (
              <motion.div
                key={mod.card.id}
                layout
                initial={false}
                animate={isExpanded ? {
                  position: 'fixed',
                  top: '10%',
                  left: '15%',
                  width: '70%',
                  height: '80%',
                  zIndex: 50,
                  backgroundColor: 'white',
                  borderRadius: '0.5rem',
                  boxShadow: '0 25px 50px -12px rgba(0, 0, 0, 0.25)',
                } : {
                  position: 'absolute',
                  top: mod.card.y,
                  left: mod.card.x,
                  width: '16rem',
                  height: 'auto',
                  zIndex: mod.card.isDragging ? 10 : 1,
                }}
                transition={{ duration: 0.3 }}
              >
                {isExpanded ? (
                  <>
                    <div 
                      className="fixed inset-0 bg-black/30"
                      style={{ zIndex: 40 }}
                      onClick={handleClose}
                    />
                    <div className="fixed inset-0 backdrop-blur-sm" style={{ zIndex: 41 }} />
                    <div className="bg-white rounded-lg shadow-xl h-full overflow-auto relative" style={{ zIndex: 42 }}>
                      <button
                        onClick={handleClose}
                        className="absolute top-4 right-4 z-50 bg-gray-100 hover:bg-gray-200 rounded-full p-2"
                      >
                        <span className="sr-only">Close</span>
                        ✕
                      </button>
                      <Demo className="bg-white" cardId={mod.card.id} />
                    </div>
                  </>
                ) : (
                  <Card
                    data-card-id={mod.card.id}
                    className="w-full shadow-lg relative cursor-pointer"
                    onMouseDown={(e) => handleMouseDown(e, mod.card.id)}
                    onClick={(e) => handleCardClick(e, mod.card.id)}
                  >
                    <div 
                      className="absolute top-2 right-2 text-gray-400 hover:text-gray-600 transition-colors"
                      onClick={(e) => {
                        e.stopPropagation();
                        setExpandedCard(mod.card.id);
                      }}
                    >
                      <svg
                        xmlns="http://www.w3.org/2000/svg"
                        width="16"
                        height="16"
                        viewBox="0 0 24 24"
                        fill="none"
                        stroke="currentColor"
                        strokeWidth="2"
                        strokeLinecap="round"
                        strokeLinejoin="round"
                      >
                        <path d="M15 3h6v6M9 21H3v-6M21 3l-7 7M3 21l7-7" />
                      </svg>
                    </div>
                    
                    <div className="p-4 space-y-2">
                      <div className="relative">
                        <span
                          className="absolute inset-0 cursor-text"
                          style={{
                            width: Math.max(mod.card.title.length, 4) + 'ch',
                            minWidth: '4ch'
                          }}
                        >
                          <input
                            type="text"
                            value={mod.card.title}
                            onChange={(e) => updateCardText(mod.card.id, 'title', e.target.value)}
                            onFocus={() => setEditingCard(mod.card.id)}
                            onBlur={() => setEditingCard(null)}
                            className="font-semibold bg-transparent w-full border-none focus:outline-none focus:ring-1 focus:ring-blue-500 rounded px-1 cursor-text"
                            onClick={(e) => e.stopPropagation()}
                          />
                        </span>
                        <span className="font-semibold invisible whitespace-pre">
                          {mod.card.title || '\u00A0\u00A0\u00A0\u00A0'}
                        </span>
                      </div>
                      
                      <div className="text-sm relative w-full">
                        <textarea
                          value={mod.card.content}
                          placeholder="Enter description"
                          onChange={(e) => {
                            e.target.style.height = 'auto';
                            e.target.style.height = e.target.scrollHeight + 'px';
                            updateCardText(mod.card.id, 'content', e.target.value);
                          }}
                          onFocus={() => setEditingCard(mod.card.id)}
                          onBlur={(e) => {
                            setEditingCard(null);
                            if (!e.target.value.trim()) {
                              updateCardText(mod.card.id, 'content', "Enter description");
                            }
                          }}
                          className="w-[calc(100%-8px)] bg-transparent border-none focus:outline-none focus:ring-1 focus:ring-blue-500 rounded cursor-text resize-none mx-1 overflow-hidden"
                          onClick={(e) => e.stopPropagation()}
                          rows={1}
                          style={{ minHeight: '1.5em' }}
                        />
                      </div>
                    </div>
                  </Card>
                )}
              </motion.div>
            );
          })}
        </AnimatePresence>
      </div>
    </div>
  );
};

export default DraggableCardsCanvas;