//
// ������������ ������ �12. ������. ����������� �������
// main.cpp
//
#include "polygon.h"
#include "triangle.h"
#include "rectangle.h"
#include <iostream>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Rus");
    try {
        cout << "������� ���������� ������������:" << endl;
        triangle t = get_triangle();
        cout << "������� ���������� ��������������:" << endl;
        rectangle r = get_rectangle();

        cout << endl << "������ �� ������:" << endl;
        polygon &ref_p = t;
        ref_p.print();

        cout << "����������� ���������� ����:" << endl;
        static_cast<triangle&>(ref_p).print();
        cout << typeid(static_cast<rectangle&>(ref_p)).raw_name();
        static_cast<rectangle&>(ref_p).print();

        //cout << "������������ ���������� ����:" << endl;
        //dynamic_cast<triangle&>(ref_p).print();
        //dynamic_cast<rectangle&>(ref_p).print();

        cout << endl << "������ �� ���������:" << endl;
        polygon *ptr_p = &r;
        ptr_p->print();

        cout << "����������� ���������� ����:" << endl;
        static_cast<triangle*>(ptr_p)->print();
        static_cast<rectangle*>(ptr_p)->print();

        //cout << "������������ ���������� ����:" << endl;
        //dynamic_cast<triangle*>(ptr_p)->print();
        //dynamic_cast<rectangle*>(ptr_p)->print();
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }
    system("pause");
    return 0;
}