#include "chunk.h"

Chunk::Chunk(const QSizeF &size, const QColor &color)
    : _uuid{ QUuid::createUuid() }
    , _size{ size }
    , _color{ color }
{
}

QUuid Chunk::uuid() const
{
    return _uuid;
}

QSizeF Chunk::size() const
{
    return _size;
}

QColor Chunk::color() const
{
    return _color;
}
