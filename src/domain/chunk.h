#ifndef CHUNK_H
#define CHUNK_H

#include <QSharedPointer>
#include <QUuid>
#include <QPointF>
#include <QSizeF>
#include <QColor>

/**
 * @brief Pease of plane.
 * 
 * Multiple chunks can be added to the plane.
 */
class Chunk
{
public:
    Chunk(const QPointF &position, const QSizeF& size = QSize{ 100, 100 }, const QColor &color = Qt::black);

    QUuid uuid() const;
    QPointF position() const;
    QSizeF size() const;
    QColor color() const;

private:
    QUuid _uuid;
    QPointF _position;
    QSizeF _size;
    QColor _color;
};

using ChunkPtr = QSharedPointer<Chunk>;

#endif // CHUNK_H
