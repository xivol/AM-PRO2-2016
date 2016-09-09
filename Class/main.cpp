//
// Лабораторная работа №4. Классы. Поля и vетоды
// main.cpp
//
#include <iostream>
#include "point.h"
#include "test_point.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    test_point::run();

    try {
        cout << "Введите координаты точки" << endl;
        point p = get_point();
        print(p);
    }
    catch (domain_error e) {
        cout << e.what() << endl;
    }

    system("pause");
    return 0;
}