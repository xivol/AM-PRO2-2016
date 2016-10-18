//
// Лабораторная работа №13. Классы. Абстрактный класс
// shape.cpp
//
#include "shape.h"

shape::~shape() {}

std::ostream & operator<<(std::ostream & os, const shape & s)
{
	s.print(os); // обращение к виртуальной функции print
	return os;
}
