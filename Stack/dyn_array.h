//
// ������������ ������ �14. ����������� ���� ������. ����
// dyn_array.h
//
#pragma once
#include <exception>
#include <iostream>
#include "crtdynmem.h"

class dyn_array
{
public:    
    // ��� ������, ���������� � �������
    typedef int datatype;
    
    dyn_array();
    dyn_array(size_t size);

    dyn_array(const dyn_array& d);    
    dyn_array &operator=(const dyn_array& d);

    ~dyn_array();


    // �������� ������� � ���������
    datatype &operator[](size_t index);

    // �������� ������� � ��������� ��� ������
    datatype operator[](size_t index) const;

    // ���������� ��������� � �������
    int count() const;

    // ��������� ������� �������
    void resize(size_t new_size);

    // ���������� �������� � ����� �������
    // � ����������� ������� �������
    void append(const datatype &x);

private:
    datatype *data;
    size_t size;
    void copy(const datatype *from, datatype* to, size_t size);

    friend class test_dyn_array;
};

