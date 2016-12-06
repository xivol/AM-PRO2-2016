//
// Лабораторная работа №25. Стандартная библиотека шаблонов. Лямбда-выражения
// main.cpp
//
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main()
{
    char *a = "Hello";
    char *b = "World";
    cout << a << ", " << b << "!" << endl;

    // Лямбда-выражения - безимянные функции,
    // определённые в коде

    // Обмен значений

    // Лямбда с параметрами
    auto swap1 = [](char *&i, char *&j) { char *t = i; i = j; j = t; };
    swap1(a, b);
    cout << "Lambda 1:\t" << a << ", " << b << "!" << endl;
    
    // Лямбда с захватом внешних переменных по ссылке
    auto swap2 = [&a,&b]() { auto t = a; a = b; b = t; };
    swap2();
    cout << "Lambda 2:\t" << a << ", " << b << "!" << endl;

    // Лямбда с захватом по ссылке всех переменных контекста    
    auto swap3 = [&]() { auto t = a; a = b; b = t; };
    swap3();
    cout << "Lambda 3:\t" << a << ", " << b << "!" << endl;

    // Лямбда с захватом по значению и возможностью изменять копии
    auto swap4 = [=]() mutable { auto t = a; a = b; b = t; }; // Ошибка!
    // mutable говорит компилятору, что внешним переменным захваченным по значению
    // можно присваивать новые значения
    swap4();
    cout << "Lambda 4:\t" << a << ", " << b << "!" << endl;

    // Заполнить вектор случайными значениями,
    // не превосходящими размера вектора
    vector<int> v(5);
    generate(v.begin(), v.end(), [&v]() { return rand() % v.size(); });

    // Вычислить сумму значений вектора
    int sum = 0;
    for_each(v.begin(), v.end(), [&sum](const auto &a) { sum += a; });
    
    // Вывод с помощью for_each
    for_each(v.begin(), v.end() - 1, [](const auto &a) { cout << a << " + "; });
    cout << v.back() << " = " << sum << endl;

    system("pause");
    return 0;
}