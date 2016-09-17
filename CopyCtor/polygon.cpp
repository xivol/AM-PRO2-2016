//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// polygon.cpp
//
#include "polygon.h"

void polygon::copy(const point * from, point * to, const size_t size)
{
    for (int i = 0; i < size; ++i)
        to[i] = from[i];
}

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
    delete [] points;
}