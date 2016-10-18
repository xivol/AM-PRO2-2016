//
// Лабораторная работа №12. Классы. Виртуальные функции
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

    void print() const;
    friend class test_triangle;
};

triangle get_triangle();
