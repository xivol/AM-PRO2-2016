#pragma once
#include <iostream>
#include "point.h"

class shape {
public:
	virtual ~shape() = 0;

	virtual point center() const = 0;
	virtual double area() const = 0;
	virtual double perimeter() const = 0;

	virtual void print(std::ostream& os) const = 0;
};

std::ostream & operator<<(std::ostream &os, const shape& s);