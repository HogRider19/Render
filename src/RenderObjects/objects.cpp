#include "objects.h"


//////////////////////////////////////////////////////////////////////////////////

Sphere::Sphere(Vector position, double radius)
{
    this->x = position.x;
    this->y = position.y;
    this->z = position.z;
    this->radius = radius;
};

Sphere::Sphere(double x, double y, double z, double radius)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->radius = radius;
};

double Sphere::getDist(double pX, double pY, double pZ)
{
    double pointToCenterDistance = sqrt(pow(pX - x, 2)+ pow(pY - y, 2) + pow(pZ - z, 2));
    double distanceToSphereSurface = pointToCenterDistance - this->radius;
    return distanceToSphereSurface;
};

Vector Sphere::getColor(Ray ray)
{
    return Vector(0, 0, 1);
};

//////////////////////////////////////////////////////////////////////////////////

Plane::Plane(double x, double y, double z, Vector normal)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->normal = normal;
}

Plane::Plane(Vector position, Vector normal)
{
    this->x = position.x;
    this->y = position.y;
    this->z = position.z;
    this->normal = normal;
}

double Plane::getDist(double pX, double pY, double pZ)
{
    double cartesianProduct = fabs(normal.x * pX + normal.y * pY + normal.z * pZ);
    double distanceToPlane = cartesianProduct / normal.lenght();
    return distanceToPlane;
};

Vector Plane::getColor(Ray ray)
{
    return Vector(0.5, 0.5, 0.5);
};
