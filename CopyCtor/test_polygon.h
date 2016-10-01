//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// test_polygon.h
//
#pragma once
#include "polygon.h"

class test_polygon
{
    // Функция получения массива случайных точек
    point *get_points(const size_t length);
    
    //
    // Тестируемые функции
    //

    // Тест для функции
    // polygon::copy(const point *from, point *to, const size_t size)
    bool copy();

    // Тест для функции
    // polygon::polygon(const point *points, const size_t size)
    bool points_ctor();
public:
    static bool run();
};