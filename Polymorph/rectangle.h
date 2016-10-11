//
// Лабораторная работа №12. Классы. Виртуальные функции
// rectangle.h
//
#pragma once
#include "polygon.h"

class rectangle: public polygon
{
public:
    rectangle(const point &p1, const point &p2, const point &p3, const point &p4);
    rectangle(const rectangle &r);
    rectangle &operator=(const rectangle &r);

    void print() const;

    friend class test_rectangle;
};

rectangle get_rectangle();
