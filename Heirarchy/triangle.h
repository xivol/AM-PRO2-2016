#pragma once
#include "polygon.h"
class triangle: public polygon
{
    bool convex() const;
public:
    triangle(const point &p1, const point &p2, const point &p3);

    point get_a() const;
    point get_b() const;
    point get_c() const;

    double area() const;

    double inradius() const;
    double circumradius() const;
    
    enum angle_type { Right, Obtuse, Acute };
    angle_type type() const;
};

