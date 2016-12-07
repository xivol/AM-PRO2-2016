//
// Лабораторная работа №24. Стандартная библиотека шаблонов. Время работы алгоритмов
// chrono_show.h
//
#pragma once
#include <chrono>
#include <list>

using namespace std;
using namespace std::chrono;

template <typename Duration, typename Container>
auto front_insert_time(Container &c, size_t count)
{
    auto start = steady_clock::now();
    while(count--)
        c.insert(c.begin(), Container::value_type());
    auto end = steady_clock::now();
    return duration_cast<Duration>(end - start).count();
}

template <typename Duration, typename Container>
auto back_insert_time(Container &c, size_t count)
{
    auto start = steady_clock::now();
    while (count--)
        c.insert(c.end(), Container::value_type());
    auto end = steady_clock::now();
    return duration_cast<Duration>(end - start).count();
}

template <typename Duration, typename Container>
auto front_erase_time(Container &c, size_t count)
{
    auto start = steady_clock::now();
    while (count--)
        c.erase(c.begin());
    auto end = steady_clock::now();
    return duration_cast<Duration>(end - start).count();
}

template <typename Duration, typename Container>
auto back_erase_time(Container &c, size_t count)
{
    auto start = steady_clock::now();
    while (count--)
        c.erase(--c.end());
    auto end = steady_clock::now();
    return duration_cast<Duration>(end - start).count();
}

template <typename Duration, typename Container>
auto subscript_time(Container &c, size_t count)
{
    auto start = steady_clock::now();
    while (count--)
        Container::value_type t = c[count];
    auto end = steady_clock::now();
    return duration_cast<Duration>(end - start).count();
}

template <typename Duration, typename T>
auto subscript_time(list<T> &c, size_t count)
{
    auto start = steady_clock::now();
    while (count--) {
        // Имитируем обращение по индексу
        auto it = c.begin();
        advance(it, count);
        T t = *it;
    }
    auto end = steady_clock::now();
    return duration_cast<Duration>(end - start).count();
}

template <typename Container>
void show_times(size_t operaton_count)
{
    Container c;
    // Вставка в конец
    cout << "back insert\t:\t" << 
        back_insert_time<milliseconds>(c, operaton_count) << " ms" << endl;
    // Удаление из начала
    cout << "front erase\t:\t" <<
        front_erase_time<milliseconds>(c, operaton_count) << " ms" << endl;
    // Вставка в начало
    cout << "front insert\t:\t" << 
        front_insert_time<milliseconds>(c, operaton_count) << " ms" << endl;
    // Обращение по индексу
    cout << "subscript read\t:\t" <<
        subscript_time<milliseconds>(c, operaton_count) << "ms" << endl;
    // Удаление из конца
    cout << "back erase\t:\t" <<
        back_erase_time<milliseconds>(c, operaton_count) << " ms" << endl;
}