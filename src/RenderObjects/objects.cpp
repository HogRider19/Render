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

Vector Sphere::getColor(double pX, double pY, double pZ)
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

Vector Plane::getColor(double pX, double pY, double pZ)
{
    return Vector(0.5, 0.5, 0.5);
};

//////////////////////////////////////////////////////////////////////////////////

Torus::Torus(Vector position, double radiusSamll, double radiusLarge)
{
    this->x = position.x;
    this->y = position.y;
    this->z = position.z;
    this->radiusSamll = radiusSamll;
    this->radiusLarge = radiusLarge;
};

Torus::Torus(double x, double y, double z, double radiusSamll, double radiusLarge)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->radiusSamll = radiusSamll;
    this->radiusLarge = radiusLarge;
};

double Torus::getDist(double pX, double pY, double pZ)
{
    double centerDist = sqrt(pX * pX + pZ * pZ) - radiusLarge;
    double distanceToTorus = sqrt(centerDist * centerDist + pY * pY) - radiusSamll;
    return distanceToTorus;
};

Vector Torus::getColor(double pX, double pY, double pZ)
{
    return Vector(255, 215, 0);
};
