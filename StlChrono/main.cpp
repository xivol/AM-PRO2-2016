//
// Лабораторная работа №24. Стандартная библиотека шаблонов. Время работы алгоритмов
// main.cpp
//
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "chrono_show.h"

using namespace std;

int main()
{   
    const size_t size = 10000;

    cout << "vector" << endl;
    show_times<vector<int>>(size);

    cout << endl<< "deque" << endl;
    show_times<deque<int>>(size);

    cout << endl << "list" << endl;
    show_times<list<int>>(size);

    system("pause");
}