#include "chunk.h"

Chunk::Chunk(const QPointF &position, const QSizeF &size, const QColor &color)
    : _uuid{ QUuid::createUuid() }
    , _position{ position }
    , _size{ size }
    , _color{ color }
{
}

QUuid Chunk::uuid() const
{
    return _uuid;
}

QPointF Chunk::position() const
{
    return _position;
}

QSizeF Chunk::size() const
{
    return _size;
}

QColor Chunk::color() const
{
    return _color;
}
