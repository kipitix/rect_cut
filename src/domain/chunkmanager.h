#ifndef CHUNKMANAGER_H
#define CHUNKMANAGER_H

#include <QSharedPointer>
#include <QSizeF>
#include <QColor>

#include "plane.h"
#include "defs.h"

struct ChunkTemplate
{
    QSizeF size;
    int count;
    QColor color;
};

/**
 * @brief Manages chunks on the plane.
 * 
 * 
 */
class ChunkManager
{
public:
    ChunkManager();
    
    Result calculate(const PlanePtr &plane, const QSizeF &planeSize, const QList<ChunkTemplate> &chunkTemplates);
};

using ChunkManagerPtr = QSharedPointer<ChunkManager>;

#endif // CHUNKMANAGER_H
