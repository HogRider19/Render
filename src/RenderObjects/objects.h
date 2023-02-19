#pragma once
#include <stdio.h>
#include "../MathObjects/vector.h"
#include "../MathObjects/ray.h"
#include "math.h"


class BaseObjectInterface
{
public:
    virtual double getDist(double pX, double pY, double pZ) = 0;
    virtual double getColor(Ray ray) = 0;
};


class Sphere : public BaseObjectInterface
{
public:

    double x, y, z;
    double radius;

    Sphere(Vector position, double radius);
    Sphere(double x, double y, double z, double radius);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual double getColor(Ray ray) override;
};

