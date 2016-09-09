#include "triangle.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
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
        }
        catch (exception e) {
            cout << e.what() << endl;
        }
    }
    // здесь будут вызваны деструкторы
    system("pause");
    return 0;
}