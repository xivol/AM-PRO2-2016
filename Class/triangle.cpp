#include "triangle.h"
#include <cmath>
#include <iostream>


triangle::triangle() : a(), b(), c() {}

triangle::triangle(const point & a, const point & b, const point & c)
{
    if (is_line(a, b, c))
        throw  std::invalid_argument("Точки расположены на одной линии");
    this->a = a;
    this->b = b;
    this->c = c;
}

point triangle::get_a() const
{
    return a;
}

point triangle::get_b() const
{
    return b;
}

point triangle::get_c() const
{
    return c;
}

triangle::angle_type triangle::type() const
{
    double ab = a.distance_to(b);
    ab *= ab;
    double bc = b.distance_to(c);
    bc *= bc;
    double ca = c.distance_to(a);
    ca *= ca;
    sort(ab, bc, ca, false);
    double dif = ab - bc - ca;
    if (abs(dif)<precision)
        return Right;
    if (dif>0)
        return Obtuse;
    return Acute;
}

double triangle::perimeter() const
{
    double ab = a.distance_to(b);
    double bc = b.distance_to(c);
    double ca = c.distance_to(a);
    return ab + bc + ca;
}

double triangle::area() const
{
    double ab = a.distance_to(b);
    double bc = b.distance_to(c);
    double ca = c.distance_to(a);
    double p = (ab + bc + ca) / 2.0;
    std::cout << ab << " " << bc << " " << ca << std::endl;
    std::cout << p << std::endl;
    return sqrt(p*(p - ab)*(p - bc)*(p - ca));
}

double triangle::inradius() const
{
    return area() / perimeter() / 2.0;
}

double triangle::circumradius() const
{
    double ab = a.distance_to(b);
    double bc = b.distance_to(c);
    double ca = c.distance_to(a);
    return ab*bc*ca / sqrt((ab + bc + ca)*(-ab + bc + ca)*(ab - bc + ca)*(ab + bc - ca));
}

void sort(double & a, double & b, double & c, bool asc)
{
    double max, mid, min;
    if (a > b)
        if (b > c)
            max = a, mid = b, min = c;
        else
            if (c > a)
                max = c, mid = a, min = b;
            else
                max = a, mid = c, min = b;
    else
        if (a > c)
            max = b, mid = a, min = c;
        else
            if (c > b)
                max = c, mid = b, min = a;
            else
                max = b, mid = c, min = a;
    if (asc) {
        double t = min;
        min = max;
        max = t;
    }
    a = max;
    b = mid;
    c = min;
}

triangle get_triangle()
{
    point a = get_point();
    point b = get_point();
    point c = get_point();
    return triangle(a,b,c);
}

void print(const triangle & t)
{
    std::cout << "A:";
    print(t.get_a());
    std::cout << ", B:";
    print(t.get_b());
    std::cout << ", C:";
    print(t.get_c());
}
