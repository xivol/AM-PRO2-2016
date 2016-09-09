#include "test_point.h"
#include "triangle.h"
#include "circle.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    test_point::run();
    // Ограничиваем время жизни объектов
    {
        try {
            cout << "ВВедите координаты вершин треугольника" << endl;            
            triangle t = get_triangle();

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

            size_t n;
            cin >> n;
            point* points = new point[n];
            for (int i = 0; i < n; ++i)
                points[i] = get_point();
            print(min_circuncircle(points, n));
            delete [] points;
        }
        catch (exception e) {
            cout << e.what() << endl;
        }
    }
    // здесь будут вызваны деструкторы
    system("pause");
    return 0;
}