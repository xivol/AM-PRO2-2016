#pragma once
#include <cstdint>
#include <iostream>

// Комната
class room {
	// номер комнаты
	uint32_t num;
	// площадь комнаты
	double sqr;
public:
	room(uint32_t number, double square) :
		num(number), sqr(square) {}

	void print(std::ostream &os = std::cout) {
		os << "Комната №" << num << " площадь " << sqr << std::endl;
	}

	uint32_t number() const {
		return num;
	}

	double square() const {
		return sqr;
	}
};