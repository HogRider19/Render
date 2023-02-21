#include "renderController.h"


Camera::Camera(Vector position, Vector direction, CameraConfig conf)
{
    this->position = position;
    this->direction = direction;
    this->config = conf;
};

void Camera::rotate(Vector rotationAngles)
{
    direction.rotate(rotationAngles.x, rotationAngles.y, rotationAngles.x);
}

void Camera::move(Vector newPosition)
{
    position.sub(newPosition);
};

void Camera::moveTo(Vector newPosition)
{
    position = newPosition;
};

RenderController::RenderController(Camera camera, RenderConfig conf)
{
    this->camera = camera;
    this->config = conf;
};

void RenderController::addObject(BaseObjectInterface &obj){
    objects.push_front(&obj);
}

Vector RenderController::rayMarching(Ray ray)
{
    return Vector(0, 0, 0);
}

Ray RenderController::rayMarchingStep(Ray ray)
{
    return Ray(Vector(), Vector());
}

void RenderController::frameRender(sf::RenderWindow& window)
{   
    CameraConfig cnf = camera.config;
    Ray cmaeraDirection = Ray(camera.position, camera.direction);

    double planeLengthX = 2 * cnf.projectionPlaneDistance * sin(cnf.viewingAngleX / 2);
    double planeLengthY = 2 * cnf.projectionPlaneDistance * sin(cnf.viewingAngleY / 2);
    double pixelSizeX = planeLengthX / cnf.resolutionX;
    double pixelSizeY = planeLengthY / cnf.resolutionY;
    Vector planePoint = camera.position.subNew(camera.direction);
    for(double x=-planeLengthX/2; x<planeLengthX/2; x = x + pixelSizeX)
    {
        for(double y=-planeLengthY/2; y<planeLengthY/2; y = y + pixelSizeY)
        {
            Vector point = convertPlaneCoordToGlobal(x, y, camera.direction, planePoint);
            Vector renderRayDirection = camera.position.subNew(point.multNew(-1));
            Ray renderRay = Ray(camera.position, renderRayDirection);

            ///
        }
    }
}

void RenderController::run()
{
    sf::RenderWindow window(sf::VideoMode(config.WinWidth, config.WinHeight), "Render!");
    sf::RectangleShape figure(sf::Vector2f(120, 50));
    figure.setPosition(250.f, 250.f);
    figure.setFillColor(sf::Color::Green);

    frameRender(window);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(figure);
        window.display();
    }
};