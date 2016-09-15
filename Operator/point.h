#pragma once
#include <cassert>
#include <iostream>
#include <fstream>

const double precision = 1E-10;

class test_point;
class vector;

class point
{
private:
    double x, y;
public:
    point();
    point(double x, double y);
    point(const point &p);
    ~point();
    
    double get_x() const;
    double get_y() const;

    double distance_to(const point &target) const;
    double distance_to(const point &start, const point &finish) const;

    friend class test_point;
    friend std::istream &operator>>(std::istream &is,  point &p);
};

point get_point();
void print(const point &p);

bool is_line(const point &p1, const point &p2, const point &p3);

bool operator==(const point &p1, const point &p2);
bool operator!=(const point &p1, const point &p2);

std::ostream &operator<<(std::ostream &os, const point &p);
std::istream &operator>>(std::istream &is,  point &p);

point operator+(const point &p, const vector &v);
point operator-(const point &p, const vector &v);

template <typename T>
T read_binary(std::ifstream &fin)
{
    T t;
    fin.read(reinterpret_cast<char*> (&t), sizeof(t));
    return t;
}

template <typename T>
void write_binary(std::ofstream &fout, T &t)
{
    fout.write(reinterpret_cast<char*> (&t), sizeof(t));
}

template <typename T>
size_t number_of(const char *filename)
{
    assert(filename);

    std::ifstream fin(filename, std::ios::binary);
    if (!fin.is_open())
        throw std::exception("Невозможно открыть файл!");

    size_t count = 0;
    while (!fin.eof()) {
        // считать очередной элемент из файла
        read_binary<T>(fin);
        if (fin)   // если чтение прошло успешно
            count++;
    }

    fin.close();
    return count;
}
