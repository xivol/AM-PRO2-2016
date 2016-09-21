//
// Лабораторная работа №7. Классы. Конструктор копии и операция присваивания
// main.cpp
//
#include "point.h"
#include "polygon.h"
#include "test_point.h"
#include "test_polygon.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    test_point::run();
    test_polygon::run();

    try {
        point points[100];
        size_t n;
        cout << "Введите количество точек" << endl;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cout << "Введите координаты " << i + 1 << "й точки" << endl;
            cin >> points[i];
        }
        polygon p(points, n);
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    system("pause");
    return 0;
}