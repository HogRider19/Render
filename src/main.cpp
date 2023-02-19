#include <stdio.h>
#include "MathObjects/vector.h"
#include "RenderObjects/objects.h"

int main()
{
    Sphere s = Sphere(-4, -8, 3, 5);
    BaseObjectInterface *item = &s;
    double dist = item->getDist(1, 1, 1);
    printf("Dist: %f", dist);
    return 0;
}