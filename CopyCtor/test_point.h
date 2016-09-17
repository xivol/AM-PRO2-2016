//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// test_point.h
//
#pragma once
#include "point.h"

// Объявление тестирующего класса
class test_point
{
    bool distance_to();
    bool operator_eq();
    bool operator_neq();
public:
    static bool run();
};

