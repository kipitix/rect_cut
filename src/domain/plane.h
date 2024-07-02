#ifndef PLANE_H
#define PLANE_H

#include <QSharedPointer>
#include <QMap>
#include <QSizeF>
#include <QPair>

#include "defs.h"
#include "chunk.h"

/**
 * @brief Big rectangular plane which we need to cut.
 * 
 * One plane can be split into several chunks.
 */
class Plane
{    
public:
    Plane(const QSizeF &size);

    QSizeF size() const;
    void setSize(const QSizeF &size);

    Result addChunk(const ChunkPtr &chunk);
    Result removeChunk(const ChunkPtr &chunk);
    
    void clearChunks();
    
    QList<ChunkPtr> chunks() const;
    
private:
    QSizeF _size;
    QMap<QUuid, ChunkPtr> _chunks;
};

using PlanePtr = QSharedPointer<Plane>;

#endif // PLANE_H
