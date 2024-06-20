#ifndef PLANEAPI_H
#define PLANEAPI_H

#include <QObject>
#include <QSharedPointer>

class PlaneAPI : public QObject
{
    Q_OBJECT
public:
    explicit PlaneAPI();

signals:
};

using PlaneAPIPtr = QSharedPointer<PlaneAPI>;

#endif // PLANEAPI_H
