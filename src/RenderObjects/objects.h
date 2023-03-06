#pragma once
#include <stdio.h>
#include "../MathObjects/vector.h"
#include "../MathObjects/ray.h"
#include "math.h"


class BaseObjectInterface
{
public:
    virtual double getDist(double pX, double pY, double pZ) = 0;
    virtual Vector getColor(double pX, double pY, double pZ) = 0;
};


class Sphere : public BaseObjectInterface
{
public:

    double x, y, z;
    double radius;

    Sphere(Vector position, double radius);
    Sphere(double x, double y, double z, double radius);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual Vector getColor(double pX, double pY, double pZ) override;
};


class Plane : public BaseObjectInterface
{
public:

    double x, y, z;
    Vector normal;

    Plane(Vector position, Vector normal);
    Plane(double x, double y, double z, Vector normal);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual Vector getColor(double pX, double pY, double pZ) override;
};


class Torus : public BaseObjectInterface
{
public:

    double x, y, z;
    double radiusSamll, radiusLarge;
    Vector normal;

    Torus(Vector position, double radiusSamll, double radiusLarge, Vector normal);
    Torus(double x, double y, double z, double radiusSamll, double radiusLarge,  Vector normal);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual Vector getColor(double pX, double pY, double pZ) override;
};

class Mandelbrot : public BaseObjectInterface
{
public:

    double x, y, z;

    Mandelbrot(double x, double y, double z);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual Vector getColor(double pX, double pY, double pZ) override;
};
