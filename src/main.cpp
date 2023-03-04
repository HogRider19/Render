
#include "RenderObjects/renderController.h"

void scene1()
{
    CameraConfig cameraConfig;
    cameraConfig.resolutionX = 100;
    cameraConfig.resolutionY = 100;
    cameraConfig.viewingAngleX = 3.14;
    cameraConfig.viewingAngleY = 3.14;
    cameraConfig.projectionPlaneDistance = 1.0;

    RenderConfig renderConfig;
    renderConfig.WinWidth = 800;
    renderConfig.WinHeight = 800;
    renderConfig.maxIterationRayMarch = 50;
    renderConfig.displayAccuracy = 0.1;
    renderConfig.visibilityRange = 30.0;

    Camera camera = Camera(Vector(0, 0, 0), Vector(0, 1, 0), cameraConfig);
    RenderController controller = RenderController(camera, renderConfig);

    Plane p = Plane(Vector(0, -1.5, 0), Vector(0, 1, 0));;
    BaseObjectInterface &obj1 = p;
    controller.addObject(obj1);

    Sphere s = Sphere(0, 0, -14, 3);
    BaseObjectInterface &obj2 = s;
    controller.addObject(obj2);

    Sphere s2 = Sphere(1.5, -1, -6, 1);
    BaseObjectInterface &obj3 = s2;
    controller.addObject(obj3);

    controller.run();  
}

int main()
{
    scene1();

    return 0;
}

