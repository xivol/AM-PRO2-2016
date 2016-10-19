//
// Лабораторная работа №15. Абстрактные типы данных. Список с внешним итератором
// main.cpp
//
#include <iostream>
#include "list.h"
#include "test_list.h"

using namespace std;

int main()
{
    test_list::run();
    list l;
    int n = 10;
    while (n--)
        l.push_back(n);

    cout << l << endl;
    
    system("pause");
    return 0;
}