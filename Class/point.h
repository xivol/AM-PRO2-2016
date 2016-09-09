#pragma once
class point
{
private:
    double x, y;
public:
    point();
    point(double x, double y);
    point(const point &p);
    
    double get_x() const;
    double get_y() const;

    double distance_to(const point &target) const;
    double distance_to(const point &start, const point &finish) const;
};

point get_point();
void print(const point &p);