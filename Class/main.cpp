#include "triangle.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
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
        }
        catch (exception e) {
            cout << e.what() << endl;
        }
    }
    // ����� ����� ������� �����������
    system("pause");
    return 0;
}