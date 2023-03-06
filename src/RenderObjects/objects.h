#pragma once
#include <stdio.h>
#include "../MathObjects/vector.h"
#include "../MathObjects/ray.h"
#include "math.h"


class BaseObjectInterface
{
public:
    virtual double getDist(double pX, double pY, double pZ) = 0;
    virtual void getColor(double pX, double pY, double pZ, vec3::Vector &buf) = 0;
};


class Sphere : public BaseObjectInterface
{
public:

    double x, y, z;
    double radius;

    Sphere(double x, double y, double z, double radius);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual void getColor(double pX, double pY, double pZ, vec3::Vector &buf) override;
};


class Plane : public BaseObjectInterface
{
public:

    double x, y, z;
    vec3::Vector normal;

    Plane(double x, double y, double z, vec3::Vector normal);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual void getColor(double pX, double pY, double pZ, vec3::Vector &buf) override;
};


class Torus : public BaseObjectInterface
{
public:

    double x, y, z;
    double radiusSamll, radiusLarge;
    vec3::Vector normal;

    Torus(double x, double y, double z, double radiusSamll, double radiusLarge, vec3::Vector normal);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual void getColor(double pX, double pY, double pZ, vec3::Vector &buf) override;
};

class Mandelbrot : public BaseObjectInterface
{
public:

    double x, y, z;

    Mandelbrot(double x, double y, double z);

    virtual double getDist(double pX, double pY, double pZ) override;

    virtual void getColor(double pX, double pY, double pZ, vec3::Vector &buf) override;
};
