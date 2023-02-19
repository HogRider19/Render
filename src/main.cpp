/*
#include <stdio.h>
#include "MathObjects/vector.h"
#include "RenderObjects/objects.h"

int main()
{
    Sphere s = Sphere(0, 0, 0, 5);
    BaseObjectInterface *item = &s;
    double dist = item->getDist(5, 0, 0);
    printf("Dist: %f", dist);
    return 0;
}
*/

#include "RenderObjects/renderController.h"

int main()
{
    Camera camera = Camera();
    RenderConfig config;
    config.WinWidth = 500;
    config.WinHeight = 500;
    RenderController controller = RenderController(camera, config);
    controller.run();
    return 0;
}