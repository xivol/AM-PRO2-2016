//
// dyn_array.h
//
#pragma once
#include "crtdynmem.h"
#include <iostream>

template <typename Datatype>
class dyn_array
{
    Datatype *data;
    size_t size;
    void copy(const Datatype *from, Datatype* to, size_t size);    
public:

    dyn_array() :data(nullptr), size(0) {}
    dyn_array(size_t size) :size(size)
    {
        data = new Datatype[size];
    }

    dyn_array(const dyn_array& d)
    {
        size = d.size;
        data = new Datatype[size];
        copy(d.data, data, size);
    }

    dyn_array &operator=(const dyn_array& d)
    {
        
    }

    ~dyn_array()
    {
        delete[] data;
    }

    // Операция доступа к элементам
    Datatype &operator[](size_t index);

    // Операция доступа к элементам для чтения
    const Datatype &operator[](size_t index) const;

    // Количество элементов в массиве
    int count() const;

    // Изменение размера массива
    void resize(size_t new_size);

    // Добавление элемента в конец массива
    // с увеличением размера массива
    void append(const Datatype &x);

    class iterator
    {

        // Указатель на узел списка
        node *current;

        // Указатель на список
        const dyn_array *collection;

        // Закрытый конструктор
        // доступен только в дружественных классах 
        iterator(const dyn_array *collection, node *current);
    public:
        // Разименование
        Datatype &operator*();

        // Инкремент (префиксный)
        iterator &operator++();
        // Инкремент (постфиксный)
        iterator operator++(int);

        // Сравнение на равенство
        bool operator==(const iterator &it) const;
        // Сравнение на неравенство
        bool operator!=(const iterator &it) const;

        // Объявляем класс, 
        // которому можно создавать итераторы
        friend class dyn_array<Datatype>;
    };

    //
    // Методы для работы с итератором
    //

    // Получение итерартора на начало списка
    iterator begin();
    // Получение итератора за концом списка
    iterator end();

    template <typename T>
    friend class test_dyn_array<T>;
};

