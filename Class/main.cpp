#include "test_point.h"
#include "triangle.h"
#include "circle.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    test_point::run();
    // ������������ ����� ����� ��������
    {
        try {
            cout << "������� ���������� ������ ������������" << endl;            
            triangle t = get_triangle();

            print(t);
            cout << endl;

            switch (t.type()) {
                case triangle::Right:
                    cout << "������������� �����������" << endl;
                    break;
                case triangle::Acute:
                    cout << "������������� �����������" << endl;
                    break;
                case triangle::Obtuse:
                    cout << "������������ �����������" << endl;
                    break;
            }

            cout << "������� ������������: " << t.area() << endl;
            cout << "�������� ������������: " << t.perimeter() << endl;
            cout << "������ ��������� ����������: " << t.circumradius() << endl;
            cout << "������ �������� ����������: " << t.inradius() << endl;

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
    // ����� ����� ������� �����������
    system("pause");
    return 0;
}