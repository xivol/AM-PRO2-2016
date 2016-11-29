#pragma once

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

template <typename Container>
void sorted_fill(Container &v, const char *filename)
{
    ifstream fin(filename);
    while (!fin.eof()) {
        Container::value_type val;
        if (!(fin >> val))
            break;
        auto pos = upper_bound(begin(v), end(v), val);
        v.insert(pos, val);
    }
    fin.close();
}


template <typename Container>
inline void print(const Container&c, const char *delim = " ")
{
    copy(begin(c), end(c), ostream_iterator<Container::value_type>(cout, delim));
}
template <typename Container>
inline void read(Container&c, istream &is=cin)
{
    copy(istream_iterator<Container::value_type>(is), istream_iterator<Container::value_type>(), back_inserter<Container>(c));
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, "\t"));
    os << endl;
    return os;
}


