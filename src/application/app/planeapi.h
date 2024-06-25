#ifndef PLANEAPI_H
#define PLANEAPI_H

#include <QObject>
#include <QSharedPointer>

#include "plane.h"
#include "planeviewmodel.h"

class PlaneAPI : public QObject
{
    Q_OBJECT
public:
    explicit PlaneAPI(const PlanePtr &plane, const PlaneViewModelPtr &planeViewModel);

    Q_INVOKABLE bool setPlaneWidth(double width);
    Q_INVOKABLE bool setPlaneHeight(double height);

    Q_INVOKABLE bool calculate();

private:

    PlanePtr _plane;
    PlaneViewModelPtr _planeViewModel;
};

using PlaneAPIPtr = QSharedPointer<PlaneAPI>;

#endif // PLANEAPI_H
