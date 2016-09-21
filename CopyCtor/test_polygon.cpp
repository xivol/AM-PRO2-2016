//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// test_polygon.cpp
//
#include "test_polygon.h"

point * test_polygon::get_points(const size_t length)
{

    point *points = new point[n];
    for (int i = 0; i < n; ++i) {
        points[i] = point(rand(), rand());
    }
    return points;
}

bool test_polygon::copy()
{
    size_t n = 15;
    point *points = get_points(n);
    point *result = new point[n];
    
    polygon t;
    t.copy(points, result, n);

    for (int i = 0; i < n; ++i) {
        assert(points[i] == result[i]);
    }

    delete [] points;
    delete [] result;
#ifdef _DEBUG
    std::cerr << "test polygon copy: OK" << std::endl;
#endif
    return true;
}

bool test_polygon::points_ctor()
{
    size_t n = 16;
    point *points = get_points(n);

    polygon t(points, n);

    assert(t.size == n);
    for (int i = 0; i < n; i++) {
        assert(t.points[i] == points[i]);
    }

#ifdef _DEBUG
    std::cerr << "test polygon constructor: OK" << std::endl;
#endif
    return true;
}

bool test_polygon::run()
{
    test_polygon test;
    return test.copy() && test.points_ctor();
}
