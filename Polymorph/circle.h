#pragma once
#include "point.h"

const double Pi = 3.141592653589793;

class circle
{
    point c;
    double r;
public:
    circle(const point &c, double r);

    point center() const;
    double radius() const;

    double area() const;
    double perimeter() const;

    bool contains(const point& p) const;
};

circle get_circle();
void print(const circle &c);

circle min_circuncircle(const point *array, const size_t length);

