#ifndef CHUNKMANAGER_H
#define CHUNKMANAGER_H

#include <QSharedPointer>

/**
 * @brief Manages chunks on the plane.
 * 
 * 
 */
class ChunkManager
{
public:
    ChunkManager();
};

using ChunkManagerPtr = QSharedPointer<ChunkManager>;

#endif // CHUNKMANAGER_H
