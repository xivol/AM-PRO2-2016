//
// Лабораторная работа №12. Классы. Виртуальные функции
// polygon.h
//
#pragma once
#include "point.h"

class polygon
{
protected:
    // масив точек
    point *points;
    // длина массива
    size_t size;

    // Вспомогательная функция копирования массива точек
    void copy(const point *from, point *to, const size_t size);

    // Закрытый конструктор без параметров
    polygon();
public:
    // Конструктор от массива точек
    polygon(const point *points, const size_t size);
    polygon::polygon(const polygon &p);
    polygon &operator=(const polygon &p);

    // Деструктор
    ~polygon();   

    // Вывод
	void print() const;

    friend class test_polygon;
};
