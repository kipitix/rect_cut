#include "plane.h"

Plane::Plane(const QSize &size)
    : _size{ size }
{
}

QSizeF Plane::size() const
{
    return _size;
}

QPair<bool, QString> Plane::addChunk(const ChunkPtr &chunk)
{
    if (_chunks.contains(chunk->id())) {
        return { false, QString{ "Plane already contains chunk with ID: '%1'" }.arg(chunk->id().toString()) };
    }

    _chunks.insert(chunk->id(), chunk);

    return { true, "" };
}

QPair<bool, QString> Plane::removeChunk(const ChunkPtr &chunk)
{
    if (!_chunks.contains(chunk->id())) {
        return { false, QString{ "Plane does not contains chunk with ID: '%1'" }.arg(chunk->id().toString()) };
    }

    _chunks.remove(chunk->id());

    return { true, "" };
}

QList<ChunkPtr> Plane::chunks() const
{
    return _chunks.values();
}
