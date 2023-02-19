#include "ray.h"


Ray::Ray(Vector point, Vector direct)
{
    this->direct = direct;
    this->position = point;
}