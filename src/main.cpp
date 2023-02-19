#include "RenderObjects/renderController.h"

int main()
{
    CameraConfig cameraConfig;
    cameraConfig.resolutionX = 100;
    cameraConfig.resolutionY = 100;
    cameraConfig.ViewingAngleX = 3.14;
    cameraConfig.ViewingAngleY = 3.14;

    RenderConfig renderConfig;
    renderConfig.WinWidth = 500;
    renderConfig.WinHeight = 500;

    Camera camera = Camera(Vector(0, 0, 0), Vector(0, 0, 0), cameraConfig);
    RenderController controller = RenderController(camera, renderConfig);
    controller.run();
    return 0;
}