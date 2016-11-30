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
auto subscript_time(Container &c)
{
    auto start = steady_clock::now();
    for (int i = 0; i < c.size(); ++i)
        Container::value_type t =c[i];
    auto end = steady_clock::now();
    return duration_cast<Duration>(end - start).count();
}

template <typename Duration, typename T>
auto subscript_time(list<T> &c)
{
    auto start = steady_clock::now();
    for (int i = 0; i < c.size(); ++i) {
        auto it = c.begin();
            advance(it, i);
            T t = *it;
    }
    auto end = steady_clock::now();
    return duration_cast<Duration>(end - start).count();
}
