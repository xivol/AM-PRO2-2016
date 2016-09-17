//
// Лабораторная работа №8. Классы. Наследоване
// polygon.cpp
//
#include <iostream>
#include "polygon.h"

void polygon::copy(const point * from, point * to, const size_t size)
{
    for (int i = 0; i < size; ++i)
        to[i] = from[i];
}

polygon::polygon():points(nullptr), size(0){}

polygon::polygon(const point * points, const size_t size)
{
    assert(points);
    if (size < 3)
        throw  std::invalid_argument("Неверное число вершин");
    this->points = new point[size];
    this->size = size;
    copy(points, this->points, size);
}

polygon::~polygon()
{
    delete[] points;
}

double polygon::area() const
{
    double s = 0.0;
    for (int i = 1; i < size; ++i) {
        s += (points[i - 1].get_x() + points[i].get_x())*(points[i - 1].get_y() - points[i].get_y());
    }
    s += (points[size - 1].get_x() + points[0].get_x())*(points[size - 1].get_y() - points[o].get_y());
    return abs(s / 2.0);
}
