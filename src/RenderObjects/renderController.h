#pragma once
#include <stdio.h>
#include <list>
#include <SFML/Graphics.hpp>
#include "objects.h"
#include "../MathObjects/utils.h"
#include "math.h"


struct CameraConfig
{
    int resolutionX;
    int resolutionY;
    double viewingAngleX;
    double viewingAngleY;
    double projectionPlaneDistance;
};

struct RenderConfig
{
    int WinWidth;
    int WinHeight;
    int maxIterationRayMarch;
    double displayAccuracy;
    double visibilityRange;
};

struct RayMarchingStepResult
{
    Ray rayMarchingRay;
    double minimalDist;
    int nearestObjectIndex;
};

class Camera
{
public:
    Vector position;
    Vector direction;
    CameraConfig config;

    Camera(){};
    Camera(Vector position, Vector direction, CameraConfig conf);

    void move(Vector delta);

    void moveTo(Vector newPosition);

    void rotate(Vector rotationAngles);
};

class RenderController
{
public:

    std::list<BaseObjectInterface*> objects;
    RenderConfig config;
    Camera camera;

    RenderController(Camera camera, RenderConfig conf);

    void addObject(BaseObjectInterface &obj);

    void run();

private:

    void frameRender(sf::RenderWindow& window);

    void handleEvents(sf::RenderWindow& window);

    Vector rayMarching(Ray ray);

    RayMarchingStepResult rayMarchingStep(Ray ray);
};
