#pragma once
#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
istream &operator>>(istream &is, vector<T> &v)
{
    string buffer;
    getline(is, buffer);
    std::stringstream sin(buffer);
    copy(istream_iterator<T>(sin), istream_iterator<T>(), back_inserter<vector<T>>(v));
    return is;
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &v)
{
    copy(v.begin(), v.end()-1, ostream_iterator<T>(os, ", "));
    os << v.back();
    return os;
}

void vector_capacity(vector<int>& v, size_t count = 0);
vector<int> max_sum_vector(char *filename);
void vector_file_gen(char *filename, size_t max_n = 100);
