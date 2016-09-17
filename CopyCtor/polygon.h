#pragma once
#include <iostream>
#include "point.h"

class polygon
{
    point *points;
    size_t len;

    void copy(const point *from, point *to, const size_t length);
public:
    polygon(const point *points, const size_t length);
    ~polygon();

    polygon(const polygon &p);
    polygon &operator=(const polygon &p);

    point operator[](const size_t index) const;
    size_t count() const;

    double area() const;
    double perimeter() const;
    bool convex() const;
    point center() const;

    friend std::ostream &operator<<(std::ostream &os, const polygon &p);
    friend std::istream &operator>>(std::istream &is, polygon &p);
    friend bool operator==(const polygon &p1, const polygon &p2);
    
};

bool operator!=(const polygon &p1, const polygon &p2);
