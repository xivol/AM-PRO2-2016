//
// Лабораторная работа №13. Классы. Абстрактный класс
// polygon.h
//
#pragma once
#include "point.h"
#include "shape.h"

class polygon: public shape
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
	void print(std::ostream &os = std::cout) const;

    friend class test_polygon;
};
