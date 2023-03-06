#include "vector.h"


double* vec3::sub(double (&vec1)[3], double (&vec2)[3])
{
    double res[3];
    res[0] = vec1[0] + vec2[0];
    res[1] = vec1[1] + vec2[1];
    res[2] = vec1[2] + vec2[2];
    return res;
};

double* vec3::mult(double (&vec)[3], double n)
{
    double res[3];
    res[0] = vec[0] * n;
    res[1] = vec[1] * n;
    res[2] = vec[2] * n;
    return res;
};

double* vec3::normalize(double (&vec)[3])
{
    double res[3];
    double len = length(vec);
    res[0] = vec[0] / len;
    res[1] = vec[1] / len;
    res[2] = vec[2] / len;
    return res;
};

double vec3::length(double (&vec)[3])
{
    return sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);
};

double vec3::dot(double (&vec1)[3], double (&vec2)[3])
{
    return vec1[0]*vec2[0] + vec1[1]*vec2[1] + vec1[2]*vec2[2];
};


