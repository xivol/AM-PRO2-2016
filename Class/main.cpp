#include <iostream>
#include "point.h"
#include "test_point.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");

    test_point::run();

    cout << "¬ведите координаты точки" << endl;
    point p = get_point();
    print(p);

    system("pause");
    return 0;
}