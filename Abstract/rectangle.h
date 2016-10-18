//
// Лабораторная работа №13. Классы. Абстрактный класс
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

    void print(std::ostream &os = std::cout) const;
    friend class test_rectangle;
};

rectangle get_rectangle();
