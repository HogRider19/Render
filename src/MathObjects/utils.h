#pragma once
#include "vector.h"
#include "math.h"


/*
    convertPlaneСoordToGlobal

    Принимает координаты на плоскости (x, y), сама плоскость задана нормалью и принадлежащей
    точкой (planenormal, planePoint <- в трехмерном пространстве), при этом planePoint считается
    началом координат на плоскости, то есть x=0, y=0. Функция должна вернуть координаты
    переданной точки (x, y) в трехмерном пространстве в виде вектора 
*/

Vector convertPlaneCoordToGlobal(double x, double y, Vector planeNormal, Vector planePoint);
