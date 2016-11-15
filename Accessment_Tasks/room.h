#pragma once
#include <cstdint>
#include <iostream>

// �������
class room {
	// ����� �������
	uint32_t num;
	// ������� �������
	double sqr;
public:
	room(uint32_t number, double square) :
		num(number), sqr(square) {}

	void print(std::ostream &os = std::cout) {
		os << "������� �" << num << " ������� " << sqr << std::endl;
	}

	uint32_t number() const {
		return num;
	}

	double square() const {
		return sqr;
	}
};