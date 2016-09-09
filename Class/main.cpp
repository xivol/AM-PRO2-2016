#include "triangle.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "������� ���������� ������ ������������" << endl;
    point p1 = get_point();
    point p2 = get_point();
    point p3 = get_point();

    triangle t(p1,p2,p3);
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
    
    system("pause");
    return 0;
}