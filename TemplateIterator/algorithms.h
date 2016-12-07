//
// Лабораторная работа №22. Стандартная библиотека шаблонов. Шаблонные функции. Работа с контейнерами
// algorithms.h
//
#pragma once
#define GET_VALUE_TYPE()
#include <iostream>

// Шаблон функции вывода
template <typename Container>
void print(Container &container)
{
	// Проход по контейнеру.
	// Работает для любого типа с методами:
	// begin(), end().
	// А также для статических массивов T[N].
    for (const auto &value : container)
        std::cout << value << " ";
	std::cout << std::endl;
}

// Шаблон функции вычисления минимума в промежутке
template <typename Iterator>
auto min_value(const Iterator &begin, const Iterator &end)
{
	/*  Тип возвращвемого значения 
	вычисляется автоматически на этапе компиляции.
	Это возможно, т.к. тип значений в контейнере
	однозначно определяет тип возвращаемого значения.
	*/
	auto min = *begin;
	std::cout << typeid(min).name() << " : ";

    auto it = begin;
    for (++it; it != end; ++it)
        if (min > *it)
            min = *it;
    return min;
}

// Шаблон функции вычисления суммы в промежутке
template <typename Iterator, typename T = double>
T sum_value(const Iterator &begin, const Iterator &end) 
{
	/*  Тип возвращвемого значения 
	не может быть вычислен автоматически, т.к.
	типа значений в контейнере может быть не достаточно для
	хранения суммы значений.
	*/
	T sum = *begin;
	std::cout << typeid(sum).name() << " : ";

	auto it = begin;
	for (++it; it != end; ++it)
		sum += *it;
	return sum;
}