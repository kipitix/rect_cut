#ifndef PLANEVIEWMODEL_H
#define PLANEVIEWMODEL_H

#include <QObject>
#include <QSharedPointer>
#include <QVariantList>

#include "plane.h"

class PlaneViewModel : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QSizeF size READ size NOTIFY sizeChanged FINAL)

    Q_PROPERTY(QVariantList chunkList READ chunkList  NOTIFY chunkListChanged FINAL)

public:
    explicit PlaneViewModel(const PlanePtr &plane);

    QSizeF size() const;

    QVariantList chunkList() const;

    void refresh();

signals:
    void sizeChanged();
    void chunkListChanged();

private:
    PlanePtr _plane;

};

using PlaneViewModelPtr = QSharedPointer<PlaneViewModel>;

#endif // PLANEVIEWMODEL_H
