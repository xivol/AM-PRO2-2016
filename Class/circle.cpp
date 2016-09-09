#include "circle.h"
#include <cassert>
#include <cmath>
#include <cfloat>
#include <iostream>

circle::circle(const point & c, double r): c(c),r(r) 
{ 
    if (r <= precision)
        throw std::invalid_argument("Некорректный радиус круга");
}

point circle::center() const
{
    return c;
}

double circle::radius() const
{
    return r;
}

double circle::area() const
{
    return r*r*Pi;
}

double circle::perimeter() const
{
    return 2*r*Pi;
}

bool circle::contains(const point & p) const
{
    return p.distance_to(c) <= r;
}

circle get_circle()
{
    point c = get_point();
    double r;
    std::cin >> r;
    if (!std::cin)
        throw std::domain_error("Некорректный радиус круга");
    return circle(c,r);
}

void print(const circle & c)
{
    std::cout << "C: ";
    print(c.center());
    std::cout << ", R: " << c.radius() << std::endl;
}

circle min_circuncircle(const point * points, const size_t length)
{
    assert(points != nullptr);
    circle min_circle = circle(points[0], sqrt(DBL_MAX)/4);
    for (int i = 0; i < length; ++i) {
        for (int j = length - 1; j > i; --j) {
            circle c = circle(points[i], points[i].distance_to(points[j]));
            bool circum = true;
            for (int k = 0; k < length; ++k)
                if (!c.contains(points[k])) {
                    circum = false;
                    break;
                }
            if (circum) {
                if (c.area() < min_circle.area())
                    min_circle = c;
            }
        }
    }
    return min_circle;
}
