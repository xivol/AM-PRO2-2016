//
// Лабораторная работа №13. Классы. Абстрактный класс
// shape.h
//
#pragma once
#include <iostream>
#include "point.h"

//Абстрактный класс – Фигура
class shape {
public:
	// Как корень иерархии полиморфных классов
	// класс обязан иметь виртуальный деструктор
	virtual ~shape();

	//// Центр фигуры
	//virtual point center() const = 0;
	//// Площадь фигуры
	//virtual double area() const = 0;
	////Периметр фигуры
	//virtual double perimeter() const = 0;

	// Функция вывод в заданный поток os
	virtual void print(std::ostream& os) const = 0;
};

// Полиморфная операция вывода
std::ostream & operator<<(std::ostream &os, const shape& s);