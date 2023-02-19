#pragma once
#include "../MathObjects/ray.h"


class BaseObjectInterface
{
public:
    virtual float getDist(Ray ray) = 0;
    virtual float getColor(Ray ray) = 0;
};