import React, { useState } from 'react';
import { Card } from '@/components/ui/card';

const DraggableCardsCanvas = () => {
  const [cards, setCards] = useState([
    { 
      id: 1, 
      x: 100, 
      y: 100, 
      isDragging: false, 
      dragOffset: { x: 0, y: 0 },
      title: 'Card 1',
      content: 'Edit this text!'
    }
  ]);
  const [nextId, setNextId] = useState(2);
  const [editingCard, setEditingCard] = useState(null);
  const [wires, setWires] = useState([]);
  const [activeWire, setActiveWire] = useState(null);
  const [isWiring, setIsWiring] = useState(false);

  // Calculate the nearest edge point on a card
  const getSnapPoint = (cardRect, mouseX, mouseY) => {
    const centerX = cardRect.x + cardRect.width / 2;
    const centerY = cardRect.y + cardRect.height / 2;
    
    // Calculate distances to each edge
    const distToLeft = Math.abs(mouseX - cardRect.x);
    const distToRight = Math.abs(mouseX - (cardRect.x + cardRect.width));
    const distToTop = Math.abs(mouseY - cardRect.y);
    const distToBottom = Math.abs(mouseY - (cardRect.y + cardRect.height));
    
    // Find the minimum distance
    const minDist = Math.min(distToLeft, distToRight, distToTop, distToBottom);
    
    // Also return relative coordinates for anchoring
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

  const handleCardClick = (e, cardId) => {
    if (!isWiring) return;

    const cardElement = e.currentTarget;
    const cardRect = cardElement.getBoundingClientRect();
    const canvasRect = cardElement.parentElement.getBoundingClientRect();
    
    const mouseX = e.clientX - canvasRect.left;
    const mouseY = e.clientY - canvasRect.top;
    
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
      // Start new wire
      setActiveWire({
        startCard: cardId,
        startX: snapPoint.x,
        startY: snapPoint.y,
        startRelX: snapPoint.relX,
        startRelY: snapPoint.relY
      });
    } else {
      // Check if clicking the same card as start
      if (activeWire.startCard === cardId) {
        // Cancel the wire
        setActiveWire(null);
        setIsWiring(false);
        return;
      }

      // Check for existing connections in either direction
      const hasExistingConnection = wires.some(wire => 
        (wire.startCard === activeWire.startCard && wire.endCard === cardId) ||
        (wire.startCard === cardId && wire.endCard === activeWire.startCard)
      );

      if (hasExistingConnection) {
        // Alert user and cancel the wire
        alert("These cards are already connected!");
        setActiveWire(null);
        setIsWiring(false);
        return;
      }

      // Complete wire
      setWires([...wires, {
        id: wires.length,
        startCard: activeWire.startCard,
        endCard: cardId,
        startX: activeWire.startX,
        startY: activeWire.startY,
        endX: snapPoint.x,
        endY: snapPoint.y,
        // Store relative positions
        startRelX: activeWire.startRelX,
        startRelY: activeWire.startRelY,
        endRelX: snapPoint.relX,
        endRelY: snapPoint.relY
      }]);
      setActiveWire(null);
      setIsWiring(false);
    }
  };

  const handleMouseMove = (e) => {
    const canvasRect = e.currentTarget.getBoundingClientRect();
    const mouseX = e.clientX - canvasRect.left;
    const mouseY = e.clientY - canvasRect.top;

    // Update active wire position if we're wiring
    if (activeWire) {
      setActiveWire({
        ...activeWire,
        mouseX,
        mouseY
      });
    }

    // Handle card dragging
    const draggingCard = cards.find(card => card.isDragging);
    if (draggingCard) {
      const canvasRect = e.currentTarget.getBoundingClientRect();
      const newX = e.clientX - canvasRect.left - draggingCard.dragOffset.x;
      const newY = e.clientY - canvasRect.top - draggingCard.dragOffset.y;

      // Update card position
      setCards(cards.map(card =>
        card.id === draggingCard.id
          ? { ...card, x: newX, y: newY }
          : card
      ));

      // Update connected wires
      setWires(wires.map(wire => {
        if (wire.startCard === draggingCard.id || wire.endCard === draggingCard.id) {
          const cardElement = e.currentTarget.querySelector(`[data-card-id="${draggingCard.id}"]`);
          const cardRect = cardElement.getBoundingClientRect();
          const canvasRect = e.currentTarget.getBoundingClientRect();
          const relativeRect = {
            x: newX,
            y: newY,
            width: cardRect.width,
            height: cardRect.height
          };
          
          if (wire.startCard === draggingCard.id) {
            // Calculate absolute position from relative coordinates
            const startX = relativeRect.x + (wire.startRelX * relativeRect.width);
            const startY = relativeRect.y + (wire.startRelY * relativeRect.height);
            return { ...wire, startX, startY };
          } else {
            // Calculate absolute position from relative coordinates
            const endX = relativeRect.x + (wire.endRelX * relativeRect.width);
            const endY = relativeRect.y + (wire.endRelY * relativeRect.height);
            return { ...wire, endX, endY };
          }
        }
        return wire;
      }));
    }
  };

  const handleMouseDown = (e, cardId) => {
    if (editingCard !== null || isWiring) return;
    
    const card = cards.find(c => c.id === cardId);
    if (!card) return;

    const rect = e.currentTarget.getBoundingClientRect();
    const offsetX = e.clientX - rect.left;
    const offsetY = e.clientY - rect.top;

    setCards(cards.map(card => 
      card.id === cardId 
        ? { ...card, isDragging: true, dragOffset: { x: offsetX, y: offsetY } }
        : card
    ));
  };

  const handleMouseUp = () => {
    setCards(cards.map(card => ({ ...card, isDragging: false })));
  };

  const addNewCard = () => {
    const newCard = {
      id: nextId,
      x: Math.random() * 300,
      y: Math.random() * 300,
      isDragging: false,
      dragOffset: { x: 0, y: 0 },
      title: `Card ${nextId}`,
      content: 'Edit this text!'
    };
    setCards([...cards, newCard]);
    setNextId(nextId + 1);
  };

  const updateCardText = (cardId, field, value) => {
    setCards(cards.map(card =>
      card.id === cardId
        ? { ...card, [field]: value }
        : card
    ));
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
        {/* Render wires */}
        <svg className="absolute inset-0 w-full h-full pointer-events-none">
          {wires.map(wire => {
            // Calculate control points for the curve
            // Move control points out perpendicular to the connection
            const dx = wire.endX - wire.startX;
            const dy = wire.endY - wire.startY;
            const distance = Math.sqrt(dx * dx + dy * dy);
            
            // Control point distance is proportional to the distance between points
            const controlDistance = Math.min(distance * 0.5, 100);
            
            // Calculate which sides the wire is connecting to
            const startSide = wire.startX < wire.endX ? 'right' : 'left';
            const endSide = wire.startX < wire.endX ? 'left' : 'right';
            
            // Set control points based on connection sides
            let c1x, c1y, c2x, c2y;
            
            if (startSide === 'right') {
              c1x = wire.startX + controlDistance;
              c1y = wire.startY;
            } else {
              c1x = wire.startX - controlDistance;
              c1y = wire.startY;
            }
            
            if (endSide === 'right') {
              c2x = wire.endX + controlDistance;
              c2y = wire.endY;
            } else {
              c2x = wire.endX - controlDistance;
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

        {/* Render cards */}
        {cards.map(card => (
          <Card
            key={card.id}
            data-card-id={card.id}
            className="absolute w-64 cursor-move shadow-lg"
            style={{
              transform: `translate(${card.x}px, ${card.y}px)`,
              zIndex: card.isDragging ? 10 : 1,
            }}
            onMouseDown={(e) => handleMouseDown(e, card.id)}
            onClick={(e) => handleCardClick(e, card.id)}
          >
            <div className="p-4 space-y-2">
              <div className="relative">
                <span 
                  className="absolute inset-0 cursor-text"
                  style={{ 
                    width: card.title.length + 'ch',
                    minWidth: '4ch'
                  }}
                >
                  <input
                    type="text"
                    value={card.title}
                    onChange={(e) => updateCardText(card.id, 'title', e.target.value)}
                    onFocus={() => setEditingCard(card.id)}
                    onBlur={() => setEditingCard(null)}
                    className="font-semibold bg-transparent w-full border-none 
                             focus:outline-none focus:ring-1 focus:ring-blue-500 
                             rounded px-1 cursor-text"
                    onClick={(e) => e.stopPropagation()}
                  />
                </span>
                <span className="font-semibold invisible">
                  {card.title || ' '}
                </span>
              </div>
              
              <div className="relative">
                <span 
                  className="absolute inset-0 cursor-text inline-block"
                  style={{ 
                    width: Math.max(card.content.length, 4) + 'ch',
                    minHeight: '1.5em',
                    height: 'auto'
                  }}
                >
                  <textarea
                    value={card.content}
                    onChange={(e) => updateCardText(card.id, 'content', e.target.value)}
                    onFocus={() => setEditingCard(card.id)}
                    onBlur={() => setEditingCard(null)}
                    className="w-full min-h-[1.5em] bg-transparent border-none resize-none 
                             focus:outline-none focus:ring-1 focus:ring-blue-500 
                             rounded px-1 cursor-text"
                    style={{ height: '100%' }}
                    onClick={(e) => e.stopPropagation()}
                  />
                </span>
                <span className="invisible whitespace-pre-wrap block">
                  {card.content || ' '}
                </span>
              </div>
            </div>
          </Card>
        ))}
      </div>

      {/* Connection Table */}
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
              const startCard = cards.find(c => c.id === wire.startCard);
              const endCard = cards.find(c => c.id === wire.endCard);
              return (
                <tr key={wire.id}>
                  <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-900">
                    {startCard ? startCard.title : `Card ${wire.startCard}`}
                  </td>
                  <td className="px-6 py-4 whitespace-nowrap text-sm text-gray-900">
                    {endCard ? endCard.title : `Card ${wire.endCard}`}
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