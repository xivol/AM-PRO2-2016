#pragma once
#include "polygon.h"

class rectangle: public polygon
{
    double w, h;
public:
    rectangle(const point &p1, const point &p2, const point &p3, const point &p4);
    rectangle(const point &bottom_left, const point &top_right);
    rectangle(const point &bottom_left, double width, double height = 0);

    double area() const;
    double width() const;
    double height() const;

};

