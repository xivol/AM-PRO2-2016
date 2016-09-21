#pragma once
#include "polygon.h"

class regular : public polygon
{
    point center;
    double side;
    bool convex() const;
public:
    regular(const size_t sides, const double side, const point &center);

    point center() const;
    double area() const;
    double perimeter() const;

    double inradius() const;
    double circumradius() const;
};