#pragma once
#include "baseObject.h"
#include "../MathObjects/vector.h"


class Sphere : public BaseObjectInterface
{
public:

    Vector position;
    float radius;

    Sphere(Vector position, float radius);

    float getDist(Ray ray) override;

    float getColor(Ray ray) override;
};

