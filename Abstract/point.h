#pragma once
#include <cassert>
#include <iostream>
#include <fstream>

const double precision = 1E-10;

class test_point;

class point
{
private:
    double x, y;
public:
    point();
    point(double x, double y);
    point(const point &p);
    ~point();

    double get_x() const;
    double get_y() const;

    double distance_to(const point &target) const;
    double distance_to(const point &start, const point &finish) const;

    void print() const;
    friend class test_point;
    friend std::istream &operator>>(std::istream &is, point &p);
};

point get_point();
void print(const point &p);

bool is_line(const point &p1, const point &p2, const point &p3);

bool operator==(const point &p1, const point &p2);
bool operator!=(const point &p1, const point &p2);

std::ostream &operator<<(std::ostream &os, const point &p);
