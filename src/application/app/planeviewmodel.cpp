#include "planeviewmodel.h"

#include <QVariantMap>

PlaneViewModel::PlaneViewModel(const PlanePtr &plane)
    : QObject{ nullptr }
    , _plane{ plane }
{}

QSizeF PlaneViewModel::size() const
{
    return _plane->size();
}

QVariantList PlaneViewModel::chunkList() const
{
    auto chunks = _plane->chunks();

    QVariantList result(chunks.size());
\
    auto index = 0;
    for (const auto &chunk : qAsConst(chunks)) {
        auto chunkData = QVariantMap{
            { "uuid", chunk->uuid().toString() },
            { "position", chunk->position() },
            { "size", chunk->size() },
            { "color", chunk->color() },
            };
        result[index] = chunkData;
        index++;
    }

    return result;
}

void PlaneViewModel::refresh()
{
    emit sizeChanged();
    emit chunkListChanged();
}
