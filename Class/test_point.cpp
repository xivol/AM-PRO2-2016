//
// Лабораторная работа №4. Классы. Поля и vетоды
// test_point.cpp
//
#include "test_point.h"
#include <cassert>
#include <iostream>

bool test_point::distance_to()
{
    point p1(0, 0);
    point p2(0, 1);
    double result = 1;
    assert(abs(p1.distance_to(p2) - result) < precision);  
    p2.x = 0, p2.y = 0;
    result = 0;
    assert(abs(p1.distance_to(p2) - result) < precision);
    p1.x = 2, p1.y = 4;
    p2.x = 3, p2.y = 5;
    result = sqrt(2);
    assert(abs(p1.distance_to(p2) - result) < precision);
    p1.x = 0, p1.y = 3;
    p2.x = 4, p2.y = 2;
    result = sqrt(17);
    assert(abs(p1.distance_to(p2) - result) < precision);
#ifdef _DEBUG
    std::cerr << "test distance_to: OK" << std::endl;
#endif
    return true;
}

bool test_point::run()
{
    test_point test;
    return test.distance_to();
}
