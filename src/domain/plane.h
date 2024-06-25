#ifndef PLANE_H
#define PLANE_H

#include <QSharedPointer>
#include <QMap>
#include <QSizeF>
#include <QPair>

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

    void setWidth(double width);
    void setHeight(double height);

    QPair<bool, QString> addChunk(const ChunkPtr &chunk);
    QPair<bool, QString> removeChunk(const ChunkPtr &chunk);

    QList<ChunkPtr> chunks() const;

private:
    QSizeF _size;
    QMap<QUuid, ChunkPtr> _chunks;
};

using PlanePtr = QSharedPointer<Plane>;

#endif // PLANE_H
