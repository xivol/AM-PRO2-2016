#pragma once
#include "point.h"

class triangle
{
private:
    point a, b, c;
public:
    
    triangle();
    triangle(const point &a, const point &b, const point &c);

    point get_a() const;
    point get_b() const;
    point get_c() const;

    enum angle_type { Right, Acute, Obtuse};
    angle_type type() const;

    double perimeter() const;
    double area() const;
    double inradius() const;
    double circumradius() const;
};

void sort(double &a, double &b, double &c, bool asc = true);

triangle get_triangle();
void print(const triangle &t);

