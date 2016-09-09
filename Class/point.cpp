//
// Лабораторная работа №4. Классы. Поля и vетоды
// point.cpp
//
#include <iostream>
#include "point.h"

point get_point()
{
    point p;
    std::cin >> p.x >> p.y;
    if (!std::cin)
        throw std::domain_error("Некорректные координаты точки");
    return p;
}

void print(point p)
{
    std::cout << "( " << p.get_x() << ", " << p.get_y() << " )";
}
