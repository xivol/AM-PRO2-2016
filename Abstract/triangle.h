//
// Лабораторная работа №13. Классы. Абстрактный класс
// triangle.h
//
#pragma once
#include "polygon.h"

class triangle: public polygon
{
public:
    triangle(const point &a, const point &b, const point &c);
    triangle(const triangle &t);
    triangle& operator=(const triangle &t);

    void print(std::ostream &os = std::cout) const;
    friend class test_triangle;
};

triangle get_triangle();
