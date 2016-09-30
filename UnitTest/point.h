//
// Лабораторная работа №8. Классы. Модульное тестирование.
// point.h
//
#pragma once
#include <iostream>

const double precision = 1E-10;

class test_point;

class point
{
private:
    double x, y;
public:
    point();
    point(double x, double y);

    double get_x() const;
    double get_y() const;

    double distance_to(const point &target) const;

    friend std::istream &operator>>(std::istream &is, point &p);

    friend class test_point;
};

bool operator==(const point &p1, const point &p2);
bool operator!=(const point &p1, const point &p2);

std::ostream &operator<<(std::ostream &os, const point &p);

