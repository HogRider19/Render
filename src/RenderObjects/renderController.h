#pragma once
#include <stdio.h>
#include <list>
#include "math.h"
#include <SFML/Graphics.hpp>
#include "objects.h"
#include "../MathObjects/utils.h"


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
    vec3::Vector position;
    vec3::Vector direction;
    CameraConfig config;

    Camera(){};
    Camera(vec3::Vector position, vec3::Vector direction, CameraConfig conf);

    void move(vec3::Vector delta);

    void moveTo(vec3::Vector newPosition);

    void rotate(vec3::Vector rotationAngles);
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

    void rayMarching(vec3::Vector rayPoint, vec3::Vector rayDir, vec3::Vector &buf);

    RayMarchingStepResult rayMarchingStep(Ray ray);
};
