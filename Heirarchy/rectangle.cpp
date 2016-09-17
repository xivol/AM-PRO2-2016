#include "rectangle.h"

rectangle::rectangle(const point & p1, const point & p2, const point & p3, const point & p4)
{
    point p[4];
    p[0] = p1;
    p[1] = p3;
    p[2] = p3;
    p[3] = p4;
    copy(p, points, 4);
    size = 4;
}
