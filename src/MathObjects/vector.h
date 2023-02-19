#pragma once
#include <stdio.h>


class Vector
{

public:
    float x;
    float y;
    float z;

    Vector(float x, float y, float z);

    float lenght(); // Вернуть длину 

    Vector sub(Vector other); // прибавить вектор

    void rotate(float dx, float dy, float dz); // повернуть на углы dx dy dz

    void rotateAxis(float d, int axis); // axis=0 повернуть относитьельно dx, axis=1 пов.отн dy итд

    float getAngle(int axis); // вернуть угол в радианах относительно оси axis

    void normilaze(); // нормализовать

    void mult(float n); // умножить на n 
};

