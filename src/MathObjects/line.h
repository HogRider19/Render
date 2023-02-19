#pragma once
#include "vector.h"

class Line
{
    Vector point1;
    Vector popen2;
public:
    Line(Vector p1, Vector p2);
    Line(double p1_x, double p1_y, double p1_z, double p2_x, double p2_y, double p2_z);

    Vector getGuidingVector(); // Вернуть направляющий вектор

    void rotate(double dx, double dy, double dz); // повернуть на углы dx dy dz

    void rotateAxis(double d, int axis); // axis=0 повернуть относитьельно dx, axis=1 пов.отн dy итд

    double getAngle(int axis); // вернуть угол в радианах относительно оси axis
};