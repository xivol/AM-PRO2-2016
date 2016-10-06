#include <iostream>
#include "polygon.h"

void polygon::copy(const point * from, point * to, const size_t length)
{
    for (int i = 0; i < length; ++i)
        to[i] = from[i];
}

polygon::polygon(const point * points, const size_t length)
{
    assert(points);
    if (length < 3)
        throw  std::invalid_argument("Неверное число вершин");
    this->points = new point[length];
    len = length;
    copy(points, this->points, length);
}

polygon::~polygon()
{
    delete [] points;
}

polygon::polygon(const polygon & p)
{
    this->points = new point[p.len];
    this->len = p.len;
    copy(p.points, points, len);
}

polygon & polygon::operator=(const polygon & p)
{
    if (p.len > this->len) {
        delete[] points;
        points = new point[p.len];
    }
    this->len = p.len;
    copy(p.points, points, len);
    return *this;
}

point polygon::operator[](const size_t index) const
{
    return points[index];
}

size_t polygon::count() const
{
    return len;
}

double polygon::area() const
{
    double s = 0.0;
    for (int i = 1; i < len; ++i) {
        s += (points[i - 1].get_x() + points[i].get_x())*(points[i - 1].get_y() - points[i].get_y());
    }
    s += (points[len - 1].get_x() + points[0].get_x())*(points[len - 1].get_y() - points[o].get_y());
    return abs(s / 2.0);
}

double polygon::perimeter() const
{
    double p = 0.0;
    for (int i = 0; i < len; ++i) {
        p += points[i - 1].distance_to(points[i]);
    }
    p += points[len - 1].distance_to(points[0]);
    return p;
}

bool polygon::convex() const
{
    int flag = 0;
    for (int i = 0; i<len; ++i) {
        int j = (i + 1) % len;
        int k = (i + 2) % len;
        double z = (points[j].get_x() - points[i].get_x()) * (points[k].get_y() - points[j].get_y());
        z -= (points[k].get_x() - points[j].get_x()) * (points[j].get_y() - points[i ].get_y());
        if (z < 0)
            flag |= 1; 
        else if (z > 0)
            flag |= 2;
        if (flag == 3)
            return false;
    }

    if (flag != 0)
        return true;
    return false;
}

point polygon::center() const
{
    double xc = 0.0, yc = 0.0;
    for (int i = 0; i < len; ++i) {
        xc += points[i].get_x();
        yc += points[i].get_y();
    }
    return point(xc / len, yc / len);
}

//
// Polygon :: Operators
//

bool operator==(const polygon &p1, const polygon &p2)
{
    if (p1.len != p2.len)
        return false;
    for (int i = 0; i < p1.len; ++i) {
        if (p1.points[i] != p2.points[i])
            return false;
    }
    return true;
}

bool operator!=(const polygon &p1, const polygon &p2)
{
    return !(p1 == p2);
}

std::ostream &operator<<(std::ostream &os, const polygon &p)
{
    for (int i = 0; i < p.len-1; ++i)
        os << p.points[i] << ", ";
    os << p.points[p.len - 1];
    return os
}

std::istream &operator>>(std::istream &is, polygon &p)
{
    is >> p.len;
    if (p.len < 3)
        throw std::invalid_argument("Неверное число вершин");
    delete[] p.points;
    for (int i = 0; i < p.len; ++i)
        is >> p.points[i];
    return is;
}