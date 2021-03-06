#pragma once
#include <cassert>
#include <fstream>

const double precision = 1E-10;

class test_point;

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
};

point get_point();
void print(const point &p);

bool is_line(const point &p1, const point &p2, const point &p3);


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
        throw std::exception("���������� ������� ����!");

    size_t count = 0;
    while (!fin.eof()) {
        // ������� ��������� ������� �� �����
        read_binary<T>(fin);
        if (fin)   // ���� ������ ������ �������
            count++;
    }

    fin.close();
    return count;
}
