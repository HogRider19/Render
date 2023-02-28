#include "vector.h"


Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
};

void Vector::sub(Vector other)
{
    x += other.x;
    y += other.y;
    z += other.z;
};

Vector Vector::subNew(Vector other)
{
    return Vector(x + other.x, y + other.y, z + other.z);
};

double Vector::lenght()
{
    return sqrt(x * x + y * y + z * z);
}

void Vector::mult(double n)
{
    x *= n;
    y *= n;
    z *= n;
} 

Vector Vector::multNew(double n)
{
    return Vector(x * n, y * n, z * n);
}

void Vector::normalize()
{
    double len = this->lenght();
    x /= len;
    y /= len;
    z /= len;
}

double Vector::dot(Vector other)
{
    return x*other.x + y*other.y + z*other.z;
}


