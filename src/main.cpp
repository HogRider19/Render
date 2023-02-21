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

    Camera camera = Camera(Vector(0, 0, 0), Vector(0, 0, 0), cameraConfig);
    RenderController controller = RenderController(camera, renderConfig);
    controller.run();

    return 0;
}