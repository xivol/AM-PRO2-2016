//
// Лабораторная работа №13. Классы. Абстрактный класс
// triangle.cpp
//
#include "triangle.h"

triangle::triangle(const point & p1, const point & p2, const point & p3)
{
    points = new point[3];
    points[0] = p1;
    points[1] = p3;
    points[2] = p3;
    size = 3;
}

triangle::triangle(const triangle & t) : polygon(t) {}

void triangle::print(std::ostream &os) const
{
    os << "Треугольник: { " <<
        points[0] << ", " <<
        points[1] << ", " <<
        points[2] << " }" << std::endl;
}

triangle get_triangle()
{
    point p1 = get_point();
    point p2 = get_point();
    point p3 = get_point();
    return triangle(p1, p2, p3);
}
