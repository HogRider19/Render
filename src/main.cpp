
#include "RenderObjects/renderController.h"

void scene1()
{
    CameraConfig cameraConfig;
    cameraConfig.resolutionX = 800;
    cameraConfig.resolutionY = 800;
    cameraConfig.viewingAngleX = 3.14;
    cameraConfig.viewingAngleY = 3.14;
    cameraConfig.projectionPlaneDistance = 1.0;

    RenderConfig renderConfig;
    renderConfig.WinWidth = 800;
    renderConfig.WinHeight = 800;
    renderConfig.maxIterationRayMarch = 50;
    renderConfig.displayAccuracy = 0.000;
    renderConfig.visibilityRange = 30.0;

    Camera camera = Camera(Vector(0, 0, 0), Vector(0, 1, 0), cameraConfig);
    RenderController controller = RenderController(camera, renderConfig);

    Mandelbrot p = Mandelbrot(0, 0, 2);
    BaseObjectInterface &obj1 = p;
    controller.addObject(obj1);

/*
    Sphere s = Sphere(0, 0, -14, 2);
    BaseObjectInterface &obj2 = s;
    controller.addObject(obj2);

    Sphere s2 = Sphere(1.5, -1, -6, 1);
    BaseObjectInterface &obj3 = s2;
    controller.addObject(obj3);

    Sphere s3 = Sphere(-3, 3, -16, 3);
    BaseObjectInterface &obj4 = s3;
    controller.addObject(obj4);
*/
    controller.run();  
}


int main()
{
    scene1();

    return 0;
}

