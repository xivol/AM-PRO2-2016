#pragma once
#include "point.h"


class vector
{
    double x, y;
public:
    vector();
    vector(double x, double y);
    vector(const point &start, const point &finish);


    double get_x() const;
    double get_y() const;

    double length() const;
    double angle(const vector& v) const;

    void normalize();
    vector operator-() const;

    friend std::istream &operator>>(std::istream &is, vector &v);
};

bool operator==(const vector &v1, const vector &v2);
bool operator!=(const vector &v1, const vector &v2);
bool operator<(const vector &v1, const vector &v2);
bool operator>(const vector &v1, const vector &v2);

vector operator+(const vector &v1, const vector &v2);
vector operator-(const vector &v1, const vector &v2);
vector operator*(const vector &v, double k);
vector operator/(const vector &v, double k);
double operator*(const vector &v1, const vector &v2);

std::ostream &operator<<(std::ostream &os, const vector &v);
//std::istream &operator>>(std::istream &is, const vector &v);
