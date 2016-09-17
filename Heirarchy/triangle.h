#pragma once
#include "polygon.h"
class triangle: public polygon
{
public:
    triangle(const point &p1, const point &p2, const point &p3);

    double area() const;

    double inradius() const;
    double circumradius() const;
    
    enum angle_type { Right, Obtuse, Acute };
    angle_type type() const;
};

