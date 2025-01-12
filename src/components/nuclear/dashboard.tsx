import React, { useState, useEffect } from 'react';
import { Card } from '@/components/ui/card';
import { router } from '@/routes/router';
import { ModuleManager } from '@/backend/manager/ModuleManager';
import { ModuleCard } from '@/backend/models/ModuleCard';

const DraggableCardsCanvas = () => {
  const manager = ModuleManager.getInstance();
  const [modules, setModules] = useState(manager.getAllModules());
  const [wires, setWires] = useState(manager.getAllWires());
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

  // Reflect changes from manager if storing wires/modules somewhere else
  useEffect(() => {
    const storedModules = manager.getAllModules();
    setModules([...storedModules]);
    setWires([...manager.getAllWires()]);
  }, []);

  useEffect(() => {
    // Keep wires in internal state synchronized
    manager.setWires(wires);
  }, [wires]);

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
      const newX = mouseX - draggingModule.card.dragOffset.x;
      const newY = mouseY - draggingModule.card.dragOffset.y;

      draggingModule.updateCardPosition(newX, newY);
      setModules([...modules]);
      updateConnectedWirePositions(draggingModule.card.id, newX, newY, e.currentTarget);
    }
  };

  const handleMouseUp = () => {
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

  const updateConnectedWirePositions = (
    cardId: number,
    newX: number,
    newY: number,
    canvasElement: HTMLDivElement
  ) => {
    // Recalculate wires that connect to this card
    const updated = wires.map(wire => {
      if (wire.startCard === cardId || wire.endCard === cardId) {
        const cardElement = canvasElement.querySelector(`[data-card-id="${cardId}"]`) as HTMLDivElement | null;
        if (!cardElement) return wire;

        const cardRect = cardElement.getBoundingClientRect();
        const canvasRect = canvasElement.getBoundingClientRect();
        const relativeRect = {
          x: newX,
          y: newY,
          width: cardRect.width,
          height: cardRect.height
        };
        if (wire.startCard === cardId) {
          const startX = relativeRect.x + wire.startRelX * relativeRect.width;
          const startY = relativeRect.y + wire.startRelY * relativeRect.height;
          return { ...wire, startX, startY };
        } else {
          const endX = relativeRect.x + wire.endRelX * relativeRect.width;
          const endY = relativeRect.y + wire.endRelY * relativeRect.height;
          return { ...wire, endX, endY };
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

    found.card.isDragging = false;
    found.card.dragOffset = { x: offsetX, y: offsetY };
    setModules([...modules]);
  };

  const handleCardClick = (
    e: React.MouseEvent<HTMLDivElement>,
    cardId: number
  ) => {
    if (isWiring) {
      wireLogic(e, cardId);
      return;
    }
    const found = modules.find(m => m.card.id === cardId);
    if (!found) return;

    if (found.card.isDragging || modules.some(m => m.card.isDragging) || recentlyDragged) {
      return;
    }
    if (editingCard !== null) return;

    router.navigate({ to: '/demo/$cardId', params: { cardId: cardId.toString() } });
  };

  const wireLogic = (e: React.MouseEvent<HTMLDivElement>, cardId: number) => {
    const cardElement = e.currentTarget as HTMLDivElement;
    const canvasRect = cardElement.parentElement?.getBoundingClientRect();
    if (!canvasRect) return;

    const cardRect = cardElement.getBoundingClientRect();
    const mouseX = e.clientX - canvasRect.left;
    const mouseY = e.clientY - canvasRect.top;

    // Snap to nearest edge
    const snapPoint = getSnapPoint(
      {
        x: cardRect.left - canvasRect.left,
        y: cardRect.top - canvasRect.top,
        width: cardRect.width,
        height: cardRect.height
      },
      mouseX,
      mouseY
    );

    if (!activeWire) {
      setActiveWire({
        startCard: cardId,
        startX: snapPoint.x,
        startY: snapPoint.y,
        startRelX: snapPoint.relX,
        startRelY: snapPoint.relY
      });
    } else {
      if (activeWire.startCard === cardId) {
        setActiveWire(null);
        setIsWiring(false);
        return;
      }
      const hasExistingConnection = wires.some(
        wire =>
          (wire.startCard === activeWire.startCard && wire.endCard === cardId) ||
          (wire.startCard === cardId && wire.endCard === activeWire.startCard)
      );
      if (hasExistingConnection) {
        alert('These cards are already connected!');
        setActiveWire(null);
        setIsWiring(false);
        return;
      }
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
      manager.addWire(newWire);
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
    // You can generate an ID from something else or just keep a running count
    const newId = modules.length ? Math.max(...modules.map(m => m.card.id)) + 1 : 1;

    const newCard: ModuleCard = {
      id: newId,
      x: 100,
      y: 100,
      isDragging: false,
      dragOffset: { x: 0, y: 0 },
      title: `Card ${newId}`,
      content: 'Edit this text!'
    };
    const newModule = manager.createModule(newCard, []);
    setModules([...modules, newModule]);
  };

  const updateCardText = (moduleId: number, field: 'title' | 'content', value: string) => {
    const targetModule = modules.find(m => m.card.id === moduleId);
    if (!targetModule) return;
    if (field === 'title') {
      targetModule.updateCardTitle(value);
    } else {
      targetModule.updateCardContent(value);
    }
    manager.updateModuleCard(moduleId, { [field]: value });
    setModules([...modules]);
  };

  const startWiring = () => {
    setIsWiring(true);
    setActiveWire(null);
  };

  return (
    <div className="w-full h-full flex flex-col gap-4 p-4">
      <div className="flex gap-4">
        <button
          onClick={addNewCard}
          className="bg-blue-500 hover:bg-blue-600 text-white px-4 py-2 rounded w-32"
        >
          Add Card
        </button>
        <button
          onClick={startWiring}
          className={`px-4 py-2 rounded w-32 ${
            isWiring
              ? 'bg-green-500 hover:bg-green-600 text-white'
              : 'bg-blue-500 hover:bg-blue-600 text-white'
          }`}
        >
          {isWiring ? 'Wiring...' : 'Add Wire'}
        </button>
      </div>

      <div
        className="w-full h-96 bg-white border-2 border-gray-200 rounded-lg relative"
        onMouseMove={handleMouseMove}
        onMouseUp={handleMouseUp}
        onMouseLeave={handleMouseUp}
      >
        <svg className="absolute inset-0 w-full h-full pointer-events-none">
          {wires.map(wire => {
            const dx = wire.endX - wire.startX;
            const dy = wire.endY - wire.startY;
            const distance = Math.sqrt(dx * dx + dy * dy);
            const controlDistance = Math.min(distance * 0.5, 100);

            let c1x, c1y, c2x, c2y;
            if (wire.startX < wire.endX) {
              c1x = wire.startX + controlDistance;
              c1y = wire.startY;
              c2x = wire.endX - controlDistance;
              c2y = wire.endY;
            } else {
              c1x = wire.startX - controlDistance;
              c1y = wire.startY;
              c2x = wire.endX + controlDistance;
              c2y = wire.endY;
            }

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

        {modules.map(mod => (
          <Card
            key={mod.card.id}
            data-card-id={mod.card.id}
            className="absolute w-64 cursor-move shadow-lg"
            style={{
              transform: `translate(${mod.card.x}px, ${mod.card.y}px)`,
              zIndex: mod.card.isDragging ? 10 : 1,
            }}
            onMouseDown={(e) => handleMouseDown(e, mod.card.id)}
            onClick={(e) => handleCardClick(e, mod.card.id)}
          >
            <div className="p-4 space-y-2">
              <div className="relative">
                <span
                  className="absolute inset-0 cursor-text"
                  style={{
                    width: mod.card.title.length + 'ch',
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
                <span className="font-semibold invisible">
                  {mod.card.title || ' '}
                </span>
              </div>
              <div className="relative">
                <span
                  className="absolute inset-0 cursor-text inline-block"
                  style={{
                    width: Math.max(mod.card.content.length, 4) + 'ch',
                    minHeight: '1.5em',
                    height: 'auto'
                  }}
                >
                  <textarea
                    value={mod.card.content}
                    onChange={(e) => updateCardText(mod.card.id, 'content', e.target.value)}
                    onFocus={() => setEditingCard(mod.card.id)}
                    onBlur={() => setEditingCard(null)}
                    className="w-full min-h-[1.5em] bg-transparent border-none resize-none focus:outline-none focus:ring-1 focus:ring-blue-500 rounded px-1 cursor-text"
                    style={{ height: '100%' }}
                    onClick={(e) => e.stopPropagation()}
                  />
                </span>
                <span className="invisible whitespace-pre-wrap block">
                  {mod.card.content || ' '}
                </span>
              </div>
            </div>
          </Card>
        ))}
      </div>

      <div className="w-full mt-4 bg-white border rounded-lg">
        <table className="min-w-full divide-y divide-gray-200">
          <thead className="bg-gray-50">
            <tr>
              <th scope="col" className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                From
              </th>
              <th scope="col" className="px-6 py-3 text-left text-xs font-medium text-gray-500 uppercase tracking-wider">
                To
              </th>
            </tr>
          </thead>
          <tbody className="bg-white divide-y divide-gray-200">
            {wires.map(wire => {
              const startModule = modules.find(m => m.card.id === wire.startCard);
              const endModule = modules.find(m => m.card.id === wire.endCard);
              return (
                <tr key={wire.id}>
                  <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-900">
                    {startModule ? startModule.card.title : `Card ${wire.startCard}`}
                  </td>
                  <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-900">
                    {endModule ? endModule.card.title : `Card ${wire.endCard}`}
                  </td>
                </tr>
              );
            })}
            {wires.length === 0 && (
              <tr>
                <td colSpan={2} className="px-6 py-4 whitespace-nowrap text-sm text-gray-500 text-center">
                  No connections yet
                </td>
              </tr>
            )}
          </tbody>
        </table>
      </div>
    </div>
  );
};

export default DraggableCardsCanvas;