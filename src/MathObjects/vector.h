#pragma once
#include <stdio.h>
#include <math.h>


class Vector
{

public:
    double x, y, z = 0;
    
    Vector(){};
    Vector(double x, double y, double z);

    double lenght(); // Вернуть длину 

    void sub(Vector other); // прибавить вектор к текущему

    Vector subNew(Vector other); // вернкть сумму векторов

    void rotate(double dx, double dy, double dz); // повернуть на углы dx dy dz

    void rotateAxis(double d, int axis); // axis=0 повернуть относитьельно dx, axis=1 пов.отн dy итд

    double getAngle(int axis); // вернуть угол в радианах относительно оси axis

    void normilaze(); // нормализовать

    void mult(double n); // умножить на n 

    Vector multNew(double n); // вернуть результат умножения на n 
};

