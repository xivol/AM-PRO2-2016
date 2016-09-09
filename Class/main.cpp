#include "triangle.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "ВВедите координаты вершин треугольника" << endl;
    point p1 = get_point();
    point p2 = get_point();
    point p3 = get_point();

    triangle t(p1,p2,p3);
    print(t);
    cout << endl;
    switch (t.type()) {
        case triangle::Right: 
            cout << "Прямоугольный треугольник" << endl;
            break;
        case triangle::Acute:
            cout << "Остроугольный треугольник" << endl;
            break;
        case triangle::Obtuse:
            cout << "Тупоугольный треугольник" << endl;
            break;
    }
    cout << "Площадь треугольника: " << t.area() << endl;
    cout << "Периметр треугольника: " << t.perimeter() << endl;
    cout << "Радиус описанной окружности: " << t.circumradius() << endl;
    cout << "Радиус висанной окружности: " << t.inradius() << endl;
    
    system("pause");
    return 0;
}