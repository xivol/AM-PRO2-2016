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

bool test_point::distance_to_line()
{
    point p1(0, 0);
    point p2(0, 1);
    point p3(1, 1);
    double result = 1;
    assert(abs(p1.distance_to(p2, p3) - result) < precision);
    p1.x = 0.5, p1.y = 1;
    result = 0;
    assert(abs(p1.distance_to(p2, p3) - result) < precision);
    p1.x = 0, p1.y = 0;
    p2.x = 0, p2.y = 1;
    p3.x = 1, p3.y = 0;
    result = sqrt(2) / 2.0;
    assert(abs(p1.distance_to(p2, p3) - result) < precision);
#ifdef _DEBUG
    std::cerr << "test distance_to_line: OK" << std::endl;
#endif
    return true;
}

bool test_point::run()
{
    test_point test;
    return test.distance_to() && test.distance_to_line();
}