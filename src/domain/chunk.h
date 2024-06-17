#ifndef CHUNK_H
#define CHUNK_H

#include <QSharedPointer>
#include <QUuid>
#include <QSizeF>

/**
 * @brief Pease of plane.
 * 
 * Multiple chunks can be added to the plane.
 */
class Chunk
{
public:
    Chunk(const QSizeF& size);

    QUuid id() const;
    QSizeF size() const;

private:
    QUuid _id;
    QSizeF _size;
};

using ChunkPtr = QSharedPointer<Chunk>;

#endif // CHUNK_H
