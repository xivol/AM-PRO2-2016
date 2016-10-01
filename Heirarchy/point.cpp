//
// ������������ ������ �8. ������. ������������
// point.cpp
//
#include <cmath>
#include <exception>
#include <iostream>
#include "point.h"

using namespace std;

//
// ������
//

point::point() : x(0.0), y(0.0)
{
    //cout << "������� ����� (0,0)" << endl;
}

point::point(double x, double y)
{
    this->x = x;
    this->y = y;
    //cout << "������� ����� ( " << x << " , " << y << " )" << endl;
}

point::point(const point &p) : x(p.x), y(p.y)
{
    //cout << "������� ����� ( " << x << " , " << y << " )" << endl;
}

point::~point()
{
    //cout << "���������� ����� ( " << x << " , " << y << " )" << endl;
}

double point::distance_to(const point &target) const
{
    return sqrt((x - target.x)*(x - target.x) + (y - target.y)*(y - target.y));
}

double point::get_x() const
{
    return x;
}

double point::get_y() const
{
    return y;
}

//
// ��������
//

bool operator==(const point &p1, const point &p2)
{
    return abs(p1.get_x() - p2.get_x()) < precision &&
        abs(p1.get_y() - p2.get_y()) < precision;
}

bool operator!=(const point &p1, const point &p2)
{
    return !(p1 == p2);
}

std::ostream &operator<<(std::ostream &os, const point &p)
{
    os << "( " << p.get_x() << ", " << p.get_y() << " )";
    return os;
}

std::istream &operator>>(std::istream &is, point &p)
{
    is >> p.x >> p.y;
    return is;
}

//
// ���������� �������
//

point get_point()
{
    double x, y;
    std::cin >> x >> y;
    if (!std::cin)
        throw std::domain_error("������������ ���������� �����");
    return point(x, y);
}

void print(const point & p)
{
    std::cout << "(" << p.get_x() << ", " << p.get_y() << ")";
}
