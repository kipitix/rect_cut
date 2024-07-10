#ifndef CHUNK_H
#define CHUNK_H

#include <QSharedPointer>
#include <QUuid>
#include <QRectF>
#include <QColor>

/**
 * @brief Pease of plane.
 * 
 * Multiple chunks can be added to the plane.
 */
class Chunk
{
public:
    Chunk(const QRectF &rect = QRectF{ 0, 0, 100, 100 }, const QColor &color = Qt::black);

    QUuid uuid() const;
    QRectF rect() const;
    QColor color() const;

private:
    QUuid _uuid;
    QRectF _rect;
    QColor _color;
};

using ChunkPtr = QSharedPointer<Chunk>;

#endif // CHUNK_H
