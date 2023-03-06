#pragma once
#include <stdio.h>
#include <math.h>


namespace vec3
{
    struct Vector
    {
        double x;
        double y;
        double z;
    };

    double length(double x, double y, double z);

    double dot(double x1, double y1, double z1, double x2, double y2, double z2);

    void mult(double x, double y, double z, double n, Vector &buf);

    void sub(double x1, double y1, double z1, double x2, double y2, double z2, Vector &buf);

    void normalize(double x, double y, double z, Vector &buf);
};

