#include "utils.h"


Vector convertPlaneCoordToGlobal(double x, double y, Vector planeNormal, Vector planePoint)
{
    planeNormal.normalize();
    Vector planePointToCurrent = Vector(x, y, 0).subNew(planePoint.multNew(-1));
    double distAlongNormal = planePointToCurrent.dot(planeNormal);
    return planePoint.subNew(planeNormal.multNew(distAlongNormal));
}