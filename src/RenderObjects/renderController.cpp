#include "renderController.h"


Camera::Camera(Vector position, Vector angls, CameraConfig conf)
{
    this->position = position;
    this->angles = angls;
};

void Camera::rotate(Vector rotationAngles)
{
    angles.rotate(rotationAngles.x, rotationAngles.y, rotationAngles.x);
}

void Camera::move(Vector newPosition)
{
    position.sub(newPosition);
};

void Camera::moveTo(Vector newPosition)
{
    this->position = newPosition;
};

RenderController::RenderController(Camera camera, RenderConfig conf)
{
    this->camera = camera;
    this->config = conf;
};

void RenderController::setObject(BaseObjectInterface &obj){
    objects.push_front(&obj);
}

void RenderController::run()
{
    sf::RenderWindow window(sf::VideoMode(config.WinWidth, config.WinHeight), "Render!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
};