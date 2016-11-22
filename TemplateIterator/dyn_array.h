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

    // �������� ������� � ���������
    Datatype &operator[](size_t index);

    // �������� ������� � ��������� ��� ������
    const Datatype &operator[](size_t index) const;

    // ���������� ��������� � �������
    int count() const;

    // ��������� ������� �������
    void resize(size_t new_size);

    // ���������� �������� � ����� �������
    // � ����������� ������� �������
    void append(const Datatype &x);

    class iterator
    {

        // ��������� �� ���� ������
        node *current;

        // ��������� �� ������
        const dyn_array *collection;

        // �������� �����������
        // �������� ������ � ������������� ������� 
        iterator(const dyn_array *collection, node *current);
    public:
        // �������������
        Datatype &operator*();

        // ��������� (����������)
        iterator &operator++();
        // ��������� (�����������)
        iterator operator++(int);

        // ��������� �� ���������
        bool operator==(const iterator &it) const;
        // ��������� �� �����������
        bool operator!=(const iterator &it) const;

        // ��������� �����, 
        // �������� ����� ��������� ���������
        friend class dyn_array<Datatype>;
    };

    //
    // ������ ��� ������ � ����������
    //

    // ��������� ���������� �� ������ ������
    iterator begin();
    // ��������� ��������� �� ������ ������
    iterator end();

    template <typename T>
    friend class test_dyn_array<T>;
};

