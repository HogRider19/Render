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
    //pY = float((int(pY) % 5 + 5) % 5);
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
    Vector v = Vector(pX - x, 0, pZ - z);
    Vector q = Vector(v.lenght() - radiusSamll, pY, 0);
    return q.lenght() - radiusLarge;
};

Vector Torus::getColor(double pX, double pY, double pZ)
{
    return Vector(255, 215, 0);
};

//////////////////////////////////////////////////////////////////////////////////

Mandelbrot::Mandelbrot(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
};

double Mandelbrot::getDist(double pX, double pY, double pZ)
{
    pX = pX + x;
    pY = pY + y;
    pZ = pZ + z;
    Vector zn = Vector(pX, pY, pZ);
    double hit = 0.0;
    double r = 8.0;
    double d = 2.0;
    for(int i=0; i<8; i++)
    {
        double rad = zn.lenght();
        if(rad > 2)
        {
            hit = 0.5 * log(rad) * rad / d;
        } 
        else
        {
            double th = atan(Vector(zn.x, zn.y, 0).lenght() / zn.z);
            double phi = atan2(zn.y, zn.x);
            double rado = pow(rad, 8.0);
            d = pow(rad, 7.0) * 7.0 * d + 1.0;
            double sint = sin(th * r);
            double zn0 = rado * sint * cos(phi * r);
            double zn1 = rado * sint * sin(phi * r);
            double zn2 = rado * cos(th * r);
            zn = Vector(zn0, zn1, zn2);
            zn.sub(Vector(pX, pY, pZ));
        }
    }
    return hit;
};

Vector Mandelbrot::getColor(double pX, double pY, double pZ)
{
    return Vector(255, 215, 0);
};