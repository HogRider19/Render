#pragma once
#include "vector.h"


class Ray
{
public:
    Ray(Vector v, Vector point);

    Vector getGuidingVector(); // Вернуть направляющий вектор

    void rotate(float dx, float dy, float dz); // повернуть на углы dx dy dz

    void rotateAxis(float d, int axis); // axis=0 повернуть относитьельно dx, axis=1 пов.отн dy итд

    float getAngle(int axis); // вернуть угол в радианах относительно оси axis
};