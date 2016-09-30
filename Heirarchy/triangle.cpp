#include "triangle.h"

triangle::triangle(const point & p1, const point & p2, const point & p3)
{
    points = new point[3];
    points[0] = p1;
    points[1] = p3;
    points[2] = p3;
    size = 3;
}
