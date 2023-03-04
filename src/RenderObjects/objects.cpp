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
    double c = fabs(z - pZ) / radius / 2;
    if (c > 1)c = 1;
    if (c < 0)c = 0;
    return Vector(c, c, 1);
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
    double cartesianProduct = fabs(normal.x * pX + normal.y * pY + normal.z * pZ 
                                    - (x * normal.x + y * normal.y + z * normal.z));
    double distanceToPlane = cartesianProduct / normal.lenght();
    return distanceToPlane;
};

Vector Plane::getColor(double pX, double pY, double pZ)
{;
    double c1 = fabs(15 + pZ) / 15;
    double c2 = fabs(pX) / 15;
    return Vector(c2, 0.5, c1);
};

//////////////////////////////////////////////////////////////////////////////////

Torus::Torus(Vector position, double radiusSamll, double radiusLarge, Vector normal)
{
    this->x = position.x;
    this->y = position.y;
    this->z = position.z;
    this->radiusSamll = radiusSamll;
    this->radiusLarge = radiusLarge;
    this->normal = normal;
};

Torus::Torus(double x, double y, double z, double radiusSamll, double radiusLarge, Vector normal)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->radiusSamll = radiusSamll;
    this->radiusLarge = radiusLarge;
    this->normal = normal;
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
