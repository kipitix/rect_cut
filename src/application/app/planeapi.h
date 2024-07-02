#ifndef PLANEAPI_H
#define PLANEAPI_H

#include <QObject>
#include <QSharedPointer>
#include <QVariantList>

#include "plane.h"
#include "chunkmanager.h"
#include "planeviewmodel.h"

class PlaneAPI : public QObject
{
    Q_OBJECT
public:
    explicit PlaneAPI(const PlanePtr &plane, const ChunkManagerPtr &chunkManager, const PlaneViewModelPtr &planeViewModel);
    
    Q_INVOKABLE bool calculate(double planeWidth, double planeHeight, const QVariantList &chunkTemplates);

private:

    PlanePtr _plane;
    ChunkManagerPtr _chunkManager;
    PlaneViewModelPtr _planeViewModel;
};

using PlaneAPIPtr = QSharedPointer<PlaneAPI>;

#endif // PLANEAPI_H
