//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// polygon.h
//
#pragma once
#include "point.h"

class polygon
{
private:
    // масив точек
    point *points;
    // длина массива
    size_t size;

    // Вспомогательная функция копирования массива точек
    void copy(const point *from, point *to, const size_t size);
public:
    polygon(const point *points, const size_t size);
    ~polygon();   
};