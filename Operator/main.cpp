//
// ������������ ������ �6. ������. ��������
// main.cpp
//
#include "point.h"
#include "test_point.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    test_point::run();

    try {
        point p1, p2;
        cout << "������� ���������� ������ �����" << endl;
        cin >> p1;
        cout << "������� ���������� ������ �����" << endl;
        cin >> p2;
        if (p1 == p2) 
            cout << "����� �����!" << endl;
        else
            cout << "����� �� �����!" << endl;
    }
    catch (exception e) {
        cout << e.what() << endl;
    }
    system("pause");
    return 0;
}