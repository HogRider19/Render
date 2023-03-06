#include "objects.h"


//////////////////////////////////////////////////////////////////////////////////

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

void Sphere::getColor(double pX, double pY, double pZ, vec3::Vector &buf)
{
    double c = fabs(z - pZ) / radius / 2;
    if (c > 1)c = 1;
    if (c < 0)c = 0;
    buf.x = c;
    buf.y = c;
    buf.z = 1;
};

//////////////////////////////////////////////////////////////////////////////////

Plane::Plane(double x, double y, double z, vec3::Vector normal)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->normal = normal;
}

double Plane::getDist(double pX, double pY, double pZ)
{
    double cartesianProduct = fabs(normal.x * pX + normal.y * pY + normal.z * pZ 
                                    - (x * normal.x + y * normal.y + z * normal.z));
    return cartesianProduct / vec3::length(normal.x, normal.y, normal.z);
};

void Plane::getColor(double pX, double pY, double pZ, vec3::Vector &buf)
{;
    double c1 = fabs(15 + pZ) / 15;
    double c2 = fabs(pX) / 15;
    buf.x = c2;
    buf.y = 0.5;
    buf.z = c1;
};

//////////////////////////////////////////////////////////////////////////////////


Torus::Torus(double x, double y, double z, double radiusSamll, double radiusLarge, vec3::Vector normal)
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
    double v = vec3::length(pX - x, 0, pZ - z);
    double q = vec3::length(v - radiusSamll, pY, 0);
    return q - radiusLarge;
};

void Torus::getColor(double pX, double pY, double pZ, vec3::Vector &buf)
{
    buf.x = 255;
    buf.y = 255;
    buf.z = 0;
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
    /*
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
    */
   return 1;
};

void Mandelbrot::getColor(double pX, double pY, double pZ, vec3::Vector &buf)
{
    buf.x = 255;
    buf.y = 255;
    buf.z = 0;
};