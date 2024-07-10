#include "chunk.h"

Chunk::Chunk(const QRectF &rect, const QColor &color)
    : _uuid{ QUuid::createUuid() }
    , _rect{ rect }
    , _color{ color }
{
}

QUuid Chunk::uuid() const
{
    return _uuid;
}

QRectF Chunk::rect() const
{
    return _rect;
}

QColor Chunk::color() const
{
    return _color;
}
