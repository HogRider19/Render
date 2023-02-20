#include "vector.h"


Vector::Vector(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
};

void Vector::sub(Vector other)
{

};

Vector Vector::subNew(Vector other)
{
    return Vector();
};

void Vector::rotate(double dx, double dy, double dz)
{

};

double Vector::lenght()
{
    return sqrt(x * x + y * y + z * z);
}


