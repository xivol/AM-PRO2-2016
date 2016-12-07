#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// Операция ввода вектора
template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    // Значения считываются одной строкой
    string buffer;
    // Считать всё до конца строки
    getline(is, buffer);
    std::stringstream sin(buffer);
    // Используем итератор ввода и итератор вставки
    copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter<vector<T>>(v));
    return is;
}

// Операция вывода вектора
template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    // Используем итератор вывода
    copy(v.begin(), v.end()-1, ostream_iterator<T>(os, ", "));
    os << v.back();
    return os;
}

// Функция заполненя вектора с выводом изменений объема
void vector_capacity(vector<int>& v, size_t count = 0);

// Вычисление последовательности с максимальной суммой в файле
vector<int> max_sum_vector(char *filename);
