//
// ������������ ������ �4. ������. ���� � v�����
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
        cout << "������� ���������� �����" << endl;
        point p = get_point();
        print(p);
    }
    catch (domain_error e) {
        cout << e.what() << endl;
    }

    system("pause");
    return 0;
}