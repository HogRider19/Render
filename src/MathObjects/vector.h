#pragma once
#include <stdio.h>
#include <math.h>


namespace vec3
{
    double length(double (&vec)[3]);

    double dot(double (&vec1)[3], double (&vec2)[3]);

    double* mult(double (&vec)[3], double n);

    double* sub(double (&vec1)[3], double (&vec2)[3]);

    double* normalize(double (&vec)[3]);
};

