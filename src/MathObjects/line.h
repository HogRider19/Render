#pragma once
#include "vector.h"

class Line
{
    Vector point1;
    Vector popen2;
public:
    Line(Vector p1, Vector p2);
    Line(float p1_x, float p1_y, float p1_z, float p2_x, float p2_y, float p2_z);

    Vector getGuidingVector(); // Вернуть направляющий вектор

    void rotate(float dx, float dy, float dz); // повернуть на углы dx dy dz

    void rotateAxis(float d, int axis); // axis=0 повернуть относитьельно dx, axis=1 пов.отн dy итд

    float getAngle(int axis); // вернуть угол в радианах относительно оси axis
};