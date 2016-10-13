#pragma once
#include <cstdint>
#include <iostream>
// ���������� ����� �� �����
class rad_point {
	// �����
	double z;
	// ������
	double a;
public:
	rad_point() :a(0), z(0) {}
	rad_point(double zenith, double azimuth) : 
		a(azimuth), z(zenith) {}

	void print(std::ostream &os = std::cout) {
		os << "(" << z << "�, " << a << "�)" << std::endl;
	}

	double zenith() const {
		return z;
	}

	double azimuth() const {
		return a;
	}
};
