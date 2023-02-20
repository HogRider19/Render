#include "ray.h"


Ray::Ray(Vector point, Vector direct)
{
    this->direction = direct;
    this->position = point;
}