#include "planeapi.h"

PlaneAPI::PlaneAPI(const PlanePtr &plane, const PlaneViewModelPtr &planeViewModel)
    : QObject{ nullptr }
    , _plane{ plane }
    , _planeViewModel{ planeViewModel }
{}

bool PlaneAPI::setPlaneWidth(double width)
{
    _plane->setWidth(width);
    return true;
}

bool PlaneAPI::setPlaneHeight(double height)
{
    _plane->setHeight(height);
    return true;
}

bool PlaneAPI::calculate()
{
    _planeViewModel->refresh();
    return true;
}
