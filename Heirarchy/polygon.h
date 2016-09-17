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
    // Конструктор по умолчанию для инициализации в наследниках
    polygon();
public:
    polygon(const point *points, const size_t size);
    ~polygon();

    double area() const;
};