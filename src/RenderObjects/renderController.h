#pragma once
#include <stdio.h>
#include <list>
#include <SFML/Graphics.hpp>
#include "objects.h"
#include "math.h"


struct CameraConfig
{
    int resolutionX;
    int resolutionY;
    double ViewingAngleX;
    double ViewingAngleY;
};

struct RenderConfig
{
    int WinWidth;
    int WinHeight;
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

    Vector rayMarching(Ray ray);

    Ray rayMarchingStep(Ray ray);
};
