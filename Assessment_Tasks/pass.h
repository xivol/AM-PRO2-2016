#pragma once
#include <cstdint>
#include <iostream>

struct date {
	uint16_t day, month, year;
	date(uint16_t day = 1, uint16_t month = 1, uint16_t year = 2000) :
		day(day), month(month), year(year) {}
};

// Пропуск
class pass {
	// номер пропуска
	uint32_t num;
	// дата открытия пропуска
	date opened;
public:
	pass(uint32_t number, date open_date) :
		num(number), opened(open_date) {}

	void print(std::ostream &os = std::cout) {
		os << "Пропуск №" << num << " открыт ";
		os << opened.day << "." << opened.month << "." << opened.year << std::endl;
	}

	uint32_t number() const {
		return num;
	}

	date opened_date() const {
		return opened;
	}
};