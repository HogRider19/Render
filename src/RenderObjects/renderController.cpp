#include "renderController.h"


Camera::Camera(Vector position, Vector direction, CameraConfig conf)
{
    this->position = position;
    this->direction = direction;
    this->config = conf;
};

void Camera::rotate(Vector rotationAngles)
{
    //direction.rotate(rotationAngles.x, rotationAngles.y, rotationAngles.x);
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

void RenderController::addObject(BaseObjectInterface &obj)
{
    objects.push_front(&obj);
}

Vector RenderController::rayMarching(Ray ray)
{ 

    Ray rayMarchingRay = ray;
    double minimalDist = std::numeric_limits<double>::max();
    int nearestObjectindex = 0;

    for(int stepCount=0; stepCount<config.maxIterationRayMarch; stepCount++)
    {
        RayMarchingStepResult res = rayMarchingStep(rayMarchingRay);
        rayMarchingRay = res.rayMarchingRay;
        minimalDist = res.minimalDist;
        nearestObjectindex = res.nearestObjectIndex;

        if(minimalDist < config.displayAccuracy)
        {

            //printf("%f\n", minimalDist);

            std::list<BaseObjectInterface*>::iterator it = objects.begin();
            std::advance(it, nearestObjectindex);
            BaseObjectInterface* crossObject = *it;

            Vector cressPoint = rayMarchingRay.position;
            return crossObject->getColor(cressPoint.x, cressPoint.y, cressPoint.z);
        }
    }
    return Vector(0, 0, 0);
}

RayMarchingStepResult RenderController::rayMarchingStep(Ray ray)
{
    double minimalDist = std::numeric_limits<double>::max();
    int nearestObjectIndex = 0;
    int index = 0;

    std::for_each(objects.begin(), objects.end(),
    [ray, &minimalDist, &nearestObjectIndex, &index](BaseObjectInterface* object) 
    {
        Vector point = ray.position;
        double dist = object->getDist(point.x, point.y, point.z);
        if (dist < minimalDist)
        {
            nearestObjectIndex = index;
            minimalDist = dist;
        }

        index++;
    });
    
    ray.direction.normalize();
    Vector displace = ray.direction.multNew(minimalDist);
    Vector newPosition = ray.position.subNew(displace);
    Ray rayMarchingRay = Ray(newPosition, ray.direction);

    RayMarchingStepResult result;
    result.rayMarchingRay = rayMarchingRay;
    result.minimalDist = minimalDist;
    result.nearestObjectIndex = nearestObjectIndex;

    return result;
}

void RenderController::frameRender(sf::RenderWindow& window)
{   
    window.clear();
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
            //Vector point = convertPlaneCoordToGlobal(x, y, camera.direction, planePoint);
            Vector point = Vector(x*pixelSizeX, y*pixelSizeY, cnf.projectionPlaneDistance);
            Vector renderRayDirection = camera.position.subNew(point.multNew(-1));
            Ray renderRay = Ray(camera.position, renderRayDirection);

            //printf("%f %f %f\n", point.x, point.y, point.z);

            Vector pixelCollor = rayMarching(renderRay);
            pixelCollor.mult(255);

            //printf("%f %f %f\n", pixelCollor.x, pixelCollor.y, pixelCollor.z);

            sf::RectangleShape pixel (sf::Vector2f(config.WinWidth / cnf.resolutionX * 2,
                                                 config.WinHeight / cnf.resolutionY *2));
            pixel.setFillColor(sf::Color(pixelCollor.x, pixelCollor.y, pixelCollor.z));
            pixel.setPosition(x * config.WinWidth + config.WinWidth/2,
                                 y * config.WinHeight + config.WinHeight/2);

            //printf("%f %f\n", pixelSizeX, pixelSizeY);

            window.draw(pixel);
        }
    }
}

void RenderController::handleEvents(sf::RenderWindow& window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void RenderController::run()
{
    sf::RenderWindow window(sf::VideoMode(config.WinWidth, config.WinHeight), "Render!");

    frameRender(window);
    window.display();

    while (window.isOpen())
    {
        handleEvents(window);
    }
};