//
// Лабораторная работа №9. Классы. Наследование
// main.cpp
//
#include "triangle.h"
#include <iostream>

using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");

    point p[3];
    cout << "Введите координаты вершин треугольника:" << endl;
    cin >> p[0] >> p[1] >> p[2];
    
    triangle t(p[0], p[1], p[2]);
    polygon plg(p,3);

    cout << t.area() << endl;
    cout << plg.area() << endl;    

    system("pause");
    return 0;
}