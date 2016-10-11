//
// Лабораторная работа №10. Классы. Обработка исключений
// dyn_array.cpp
//
#include "dyn_array.h"

dyn_array::dyn_array() :data(nullptr), size(0) {}

dyn_array::dyn_array(int size) {
    if (size <= 0)
        throw std::domain_error("dyn_array: значение размера должно быть положительным");
    this->size = size;
    data = new datatype[size];
}

dyn_array::dyn_array(const char *filename, bool is_text)
{
    //if (is_text)
    //    text_init(filename);
    //else
    //    file_init(filename);
}

dyn_array::~dyn_array()
{
    delete[] data;
}

dyn_array::dyn_array(const dyn_array & d)
{
    size = d.size;
    data = new datatype[size];
    copy(d.data, data, size);
}

dyn_array & dyn_array::operator=(const dyn_array & d)
{
    if (size < d.size) {
        delete[] data;
        data = new datatype[d.size];
    } 
    size = d.size;
    copy(d.data, data, size);
    return *this;
}

dyn_array::datatype dyn_array::operator[](int index) const
{
    if (index < 0)
        throw std::domain_error("operator[]: значение index должно быть не отрицательным");
    if (index >= size)
        throw std::out_of_range("operator[]: значение index должно быть < size");\
    return data[index];
}

dyn_array::datatype & dyn_array::operator[](int index)
{
    if (index < 0)
        throw std::domain_error("operator[]: значение index должно быть не отрицательным");
    if (index >= size)
        throw std::out_of_range("operator[]: значение index должно быть < size");
    return data[index];
}

int dyn_array::count() const
{
    return size;
}

void dyn_array::resize(int new_size)
{
    if (new_size < 0)
        throw std::domain_error("resize: значение new_size должно быть не отрицательным");    
    if (size == new_size) return;
    datatype *tmp = data;
    data = new datatype[new_size];
    copy(tmp, data, size);
    delete[] tmp;
    size = new_size;
}

void dyn_array::append(const datatype & x)
{
    resize(size + 1);
    data[size] = x;
    size += 1;
}

void dyn_array::copy(const datatype * from, datatype * to, int size)
{
    for (int i = 0; i < size; ++i) {
        to[i] = from[i];
    }
}
