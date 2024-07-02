#include "plane.h"

Plane::Plane(const QSizeF &size)
    : _size{ size }
{
}

QSizeF Plane::size() const
{
    return _size;
}

void Plane::setSize(const QSizeF &size)
{
    _size = size;
}

Result Plane::addChunk(const ChunkPtr &chunk)
{
    if (_chunks.contains(chunk->uuid())) {
        return { false, QString{ "Plane already contains chunk with ID: '%1'" }.arg(chunk->uuid().toString()) };
    }

    _chunks.insert(chunk->uuid(), chunk);

    return { true, "" };
}

Result Plane::removeChunk(const ChunkPtr &chunk)
{
    if (!_chunks.contains(chunk->uuid())) {
        return { false, QString{ "Plane does not contains chunk with ID: '%1'" }.arg(chunk->uuid().toString()) };
    }

    _chunks.remove(chunk->uuid());

    return { true, "" };
}

void Plane::clearChunks()
{
    _chunks.clear();    
}

QList<ChunkPtr> Plane::chunks() const
{
    return _chunks.values();
}
