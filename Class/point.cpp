#include <cmath>
#include <exception>
#include <iostream>
#include "point.h"

point::point(): x(0.0), y(0.0) {}

point::point(double x, double y)
{
    this->x = x;
    this->y = y;
}

point::point(const point &p): x(p.x), y(p.y) {}

double point::distance_to(const point &target) const
{
    return sqrt((x - target.x)*(x - target.x) + (y - target.y)*(y - target.y));
}

double point::get_x() const
{
    return x;
}

double point::get_y() const
{
    return y;
}

double point::distance_to(const point & start, const point & finish) const
{
    return ((start.y - finish.y)*x + (finish.x - start.x)*y + 
        (start.x*finish.y - finish.x*start.y)) / start.distance_to(finish);
}

point get_point()
{
    double x, y;
    std::cin >> x >> y;
    if (!std::cin)
        throw std::domain_error("Некорректные координаты точки");
    return point(x,y);
}

void print(const point & p)
{
    std::cout << "( " << p.get_x() << ", " << p.get_y() << " )";
}

bool is_line(const point & p1, const point & p2, const point & p3)
{
    double a = (p3.get_x() - p1.get_x()) / (p3.get_y() - p1.get_y());
    double b = (p2.get_x() - p1.get_x()) / (p2.get_y() - p1.get_y());
    return abs(a - b) < precision;
}

