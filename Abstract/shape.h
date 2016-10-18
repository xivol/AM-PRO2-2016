//
// ������������ ������ �13. ������. ����������� �����
// shape.h
//
#pragma once
#include <iostream>
#include "point.h"

//����������� ����� � ������
class shape {
public:
	// ��� ������ �������� ����������� �������
	// ����� ������ ����� ����������� ����������
	virtual ~shape();

	//// ����� ������
	//virtual point center() const = 0;
	//// ������� ������
	//virtual double area() const = 0;
	////�������� ������
	//virtual double perimeter() const = 0;

	// ������� ����� � �������� ����� os
	virtual void print(std::ostream& os) const = 0;
};

// ����������� �������� ������
std::ostream & operator<<(std::ostream &os, const shape& s);