//
// Лабораторная работа №22. Стандартная библиотека шаблонов. Шаблонные функции. Работа с контейнерами
// main.cpp
//
#include <iostream>
#include "algorithms.h"
#include "list.h"

using namespace std;

int main()
{
    const int n = 10;
    int arr[n] = { 0,-1,2,-3,4,-5,6,-7,8,-9 };
	
	// Вызываем шаблонные фукции с явным типом шаблона
    print<int[n]>(arr);	
	cout << min_value<int*>(arr + 0, arr + n) << endl;
	cout << sum_value<int*,int>(arr + 0, arr + n) << endl;

    list<int> l;
	for (int i = 0; i < n; ++i)
		l.push_back(arr[i]);

	// Параметр шаблона вычисляется компилятором
    print(l);  // print<list<int>>(l);
	cout << min_value(l.begin(), l.end()) << endl;  // min_value<list<int>::iterator>(...);
	
	// Тип возвращаемого значения не может быть вычислен компилятором
	// будет использовано значение по умолчанию - double
	cout << sum_value(l.begin(), l.end()) << endl;

    system("pause");
    return 0;
}