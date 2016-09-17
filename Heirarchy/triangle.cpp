#include "triangle.h"

triangle::triangle(const point & p1, const point & p2, const point & p3)
{
    point p[3];
    p[0] = p1;
    p[1] = p3;
    p[2] = p3;
    copy(p, points, 3);
    size = 3;
}
