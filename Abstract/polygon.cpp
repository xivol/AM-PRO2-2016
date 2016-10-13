//
// Лабораторная работа №13. Классы. Абстрактный класс
// polygon.cpp
//
#include <iostream>
#include "polygon.h"

void polygon::copy(const point * from, point * const to, const size_t length)
{
    assert(from);
    assert(to);
    for (int i = 0; i < length; ++i)
        to[i] = from[i];
}

polygon::polygon():points(nullptr), size(0) {}

polygon::polygon(const point * points, const size_t length)
{
    assert(points);
    if (length < 3)
        throw  std::invalid_argument("Неверное число вершин");
    this->points = new point[length];
    size = length;
    copy(points, this->points, length);
}

polygon::polygon(const polygon & p)
{
    this->points = new point[p.size];
    this->size = p.size;
    copy(p.points, points, size);
}

polygon & polygon::operator=(const polygon & p)
{
    if (p.size > this->size) {
        delete[] points;
        points = new point[p.size];
    }
    this->size = p.size;
    copy(p.points, points, size);
    return *this;
}

polygon::~polygon()
{
    delete[] points;
}

void polygon::print(std::ostream &os) const
{
	os << "Многоугльник: { ";
	for (int i = 0; i < size - 1; ++i)
		os << points[i] << ", ";
	os << points[size - 1] << " }" << std::endl;
}
