#include "chunk.h"

Chunk::Chunk(const QSizeF &size)
    : _id{ QUuid::createUuid() }
    , _size{ size }
{
}

QUuid Chunk::id() const
{
    return _id;
}

QSizeF Chunk::size() const
{
    return _size;
}
