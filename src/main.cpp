
#include "RenderObjects/renderController.h"

int main()
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
    renderConfig.maxIterationRayMarch = 30;
    renderConfig.displayAccuracy = 0.1;
    renderConfig.visibilityRange = 30.0;

    Camera camera = Camera(Vector(0, 0, 0), Vector(1, 0, 0), cameraConfig);
    RenderController controller = RenderController(camera, renderConfig);

    Sphere sph = Sphere(0, 0, 0, 2);
    BaseObjectInterface &obj = sph;
    controller.addObject(obj);

    controller.run();

    return 0;
}
