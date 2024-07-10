#include "chunkmanager.h"

#include <algorithm>

#include <QDebug>
#include <QPointF>

#include "chunk.h"

ChunkManager::ChunkManager() {}

Result ChunkManager::calculate(const PlanePtr &plane, const QSizeF &planeSize, const QList<ChunkTemplate> &chunkTemplates)
{
    qDebug() << planeSize;
    qDebug() << chunkTemplates.length();
    
    auto input = chunkTemplates;
    
    std::sort(input.begin(), input.end(), [](const ChunkTemplate &t1, const ChunkTemplate &t2) {
        return (t1.size.width() * t1.size.height()) > (t2.size.width() * t2.size.height());
    });
    
    plane->setSize(planeSize);
    
    plane->clearChunks();
    
    auto pos = QPointF{0.0, 0.0};
    
    for (const auto &chunkTemplate : qAsConst(input)) {
        for (auto i = 0; i < chunkTemplate.count; i ++) {
            auto chunk = ChunkPtr::create(QRectF{ pos, chunkTemplate.size }, chunkTemplate.color);
            plane->addChunk(chunk);
            
            pos.setX(pos.x() + chunkTemplate.size.width());
        }
    }
    
    return { true, "" };
}
