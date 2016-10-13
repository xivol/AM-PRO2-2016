//
// Лабораторная работа №13. Классы. Абстрактный класс
// rectangle.cpp
//
#include "rectangle.h"

rectangle::rectangle(const point & p1, const point & p2, const point & p3, const point & p4)
{    
    points = new point[4];
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    points[3] = p4;
    size = 4;
}

rectangle::rectangle(const rectangle & r): polygon(r) {}

rectangle & rectangle::operator=(const rectangle & r)
{
    polygon::operator=(r);
    return *this;
}

void rectangle::print(std::ostream &os) const
{
    os << "Прямоугольник: { " <<
        points[0] << ", " <<
        points[1] << ", " <<
        points[2] << ", " <<
        points[3] << " }" << std::endl;
}

rectangle get_rectangle()
{
    point p1 = get_point();
    point p2 = get_point();
    point p3 = get_point(); 
    point p4 = get_point();
    return rectangle(p1, p2, p3, p4);
}