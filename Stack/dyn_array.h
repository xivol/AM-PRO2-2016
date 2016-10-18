//
// Лабораторная работа №14. Абстрактные типы данных. Стек
// dyn_array.h
//
#pragma once
#include <exception>
#include <iostream>
#include "crtdynmem.h"

class dyn_array
{
public:    
    // Тип данных, хранящийся в массиве
    typedef int datatype;
    
    dyn_array();
    dyn_array(size_t size);

    dyn_array(const dyn_array& d);    
    dyn_array &operator=(const dyn_array& d);

    ~dyn_array();


    // Операция доступа к элементам
    datatype &operator[](size_t index);

    // Операция доступа к элементам для чтения
    datatype operator[](size_t index) const;

    // Количество элементов в массиве
    int count() const;

    // Изменение размера массива
    void resize(size_t new_size);

    // Добавление элемента в конец массива
    // с увеличением размера массива
    void append(const datatype &x);

private:
    datatype *data;
    size_t size;
    void copy(const datatype *from, datatype* to, size_t size);

    friend class test_dyn_array;
};

