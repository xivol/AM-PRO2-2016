//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// dyn_array.cpp
//
#include "dyn_array.h"

dyn_array::dyn_array() :data(nullptr), size(0) {}

dyn_array::dyn_array(size_t size) {
    this->size = size;
    data = new datatype[size];
}

dyn_array::~dyn_array()
{
    delete[] data;
}

void dyn_array::copy(const datatype * from, datatype * to, size_t size)
{
    for (size_t i = 0; i < size; ++i) {
        to[i] = from[i];
    }
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

dyn_array::datatype dyn_array::operator[](size_t index) const
{
    return data[index];
}

dyn_array::datatype & dyn_array::operator[](size_t index)
{
    return data[index];
}

int dyn_array::count() const
{
    return size;
}

void dyn_array::resize(size_t new_size)
{
    if (size == new_size) return;
    datatype *tmp = data;
    data = new datatype[new_size];
    if (size != 0)
        copy(tmp, data, new_size);
    delete[] tmp;
    size = new_size;
}

void dyn_array::append(const datatype &x)
{
    resize(size + 1);
    data[size - 1] = x;
}