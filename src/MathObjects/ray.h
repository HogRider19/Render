#pragma once
#include "vector.h"


class Ray
{
public:

    Vector position;
    Vector direct;

    Ray(Vector point, Vector direct);

    Vector getGuidingVector(); // Вернуть направляющий вектор

    void rotate(double dx, double dy, double dz); // повернуть на углы dx dy dz

    void rotateAxis(double d, int axis); // axis=0 повернуть относитьельно dx, axis=1 пов.отн dy итд

    double getAngle(int axis); // вернуть угол в радианах относительно оси axis
};