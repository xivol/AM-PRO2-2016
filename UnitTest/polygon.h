//
// Лабораторная работа №8. Классы. Модульное тестирование.
// polygon.h
//
#pragma once
#include "point.h"


class test_polygon;

class polygon
{
private:
    point *points;
    size_t size;

    void copy(const point *from, point *to, const size_t size);
    polygon();
public:
    polygon(const point *points, const size_t size);
    polygon(const polygon &p);
    ~polygon();

    polygon &operator=(const polygon &p);

    size_t count() const;

    friend class test_polygon;
};