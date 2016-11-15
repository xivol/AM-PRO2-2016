#pragma once
#include <iostream>

// Координаты точек на плоскости
class point {
	double x, y;
public:
	point() :x(0), y(0) {}
	point(double x, double y) : x(x), y(y) {}

	void print(std::ostream &os = std::cout) {
		os << "(" << x << ", " << y << ")" << std::endl;
	}

	double get_x() const {
		return x;
	}

	double get_y() const {
		return y;
	}
};