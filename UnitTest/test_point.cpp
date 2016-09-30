#include "stdafx.h"
#include "test_helpers.h"
#include "point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TEST_CLASS(test_point)
{

public:
    
    TEST_METHOD(default_ctor)
    {
        point p;
        Assert::AreEqual(p.get_x(), 0.0, L"point::get_x");
        Assert::AreEqual(p.get_y(), 0.0, L"point::get_y");
    }

    TEST_METHOD(ctor)
    {
        point p;
        for (double x = -10.; x < 10; x += 0.3)
            for (double y = -10.; y < 10; y += 0.3) {
                p.x = x;
                p.y = y;
                Assert::AreEqual(p.get_x(), x, L"point::get_x");
                Assert::AreEqual(p.get_y(), y, L"point::get_y");
            }
    }

    TEST_METHOD(copy_ctor)
    {
        for (double x = -10.; x < 10; x += 0.3)
            for (double y = -10.; y < 10; y += 0.3) {
                point p(x, y), p1(p);
                Assert::AreEqual(p, p1);
            }

    }

    TEST_METHOD(zero_distance)
    {
        double result = 0;
        for (double x = -10.; x < 10; x += 0.3)
            for (double y = -10.; y < 10; y += 0.3) {
                point p1(x, y), p2(x, y);
                std::wstring fail = get_message(L"для точек", &p1, &p2);
                Assert::AreEqual(p1.distance_to(p2), result, precision, fail.c_str());
            }
    }

    TEST_METHOD(one_distance)
    {
        double result = 1;
        for (double x = -10; x < 10; x += 0.3)
            for (double y = -10; y < 10; y += 0.3) {
                point p1(x, y), p2(x + 1, y);
                std::wstring fail = get_message(L"для точек", &p1, &p2);
                Assert::AreEqual(p1.distance_to(p2), result, precision, fail.c_str());
            }
        for (double x = -10; x < 10; x += 0.3)
            for (double y = -10; y < 10; y += 0.3) {
                point p1(x, y), p2(x, y + 1);
                std::wstring fail = get_message(L"для точек", &p1, &p2);
                Assert::AreEqual(p1.distance_to(p2), result, precision, fail.c_str());
            }
    }

    TEST_METHOD(distance_to)
    {
        for (double x = -10; x < 10; x += 0.3)
            for (double y = -10; y < 10; y += 0.3)
                for (double z = 0; z < 10; z += 1.0) {
                    point p1(x, y), p2(x + z, y + z);
                    double result = sqrt(z * z * 2);
                    std::wstring fail = get_message(L"для точек", &p1, &p2);
                    Assert::AreEqual(p1.distance_to(p2), result, precision, fail.c_str());
                }
    }

    TEST_METHOD(operator_eq)
    {
        for (double x = -10.; x < 10; x += 0.3)
            for (double y = -10.; y < 10; y += 0.3) {
                point p1(x, y), p2(x, y);
                std::wstring fail = get_message(L"для точек", &p1, &p2);
                Assert::IsTrue(p1==p2, fail.c_str());
            }
    }

    TEST_METHOD(operator_neq)
    {
        for (double x = -10.; x < 10; x += 0.3)
            for (double y = -10.; y < 10; y += 0.3) {
                point p1(x, y), p2(x - y, x + y);
                std::wstring fail = get_message(L"для точек", &p1, &p2);
                Assert::IsTrue(p1!=p2, fail.c_str());
            }
    }

};