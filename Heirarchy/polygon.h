//
// Лабораторная работа №8. Классы. Наследование
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
    // может быть использован в дружественных классах и функциях
    // а также в наследниках
    polygon();
public:
    // Конструктор от массива точек
    polygon(const point *points, const size_t size);

    // Деструктор
    ~polygon();

    double area() const;

    friend class test_polygon;
};