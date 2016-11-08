#pragma once
#include <cassert>
#include <iostream>
#include "tree_iterator.h"

// ������ ������������ ������ ��� tree<T>
template <typename T>
class test_tree
{
    // ��������� ��� ������ �����
    typedef typename tree<T>::node *array_tree;

    // ����� ��������� ������� �����, ��������� � ������
    static array_tree get_tree(const T *data, const size_t size);    

    // ����� ��������� �������� ������
    static T *get_test_data(const size_t size);

    // ���� ��� copy_tree
    static bool copy_tree();
public:
    // ����� ������� ���� ������
    static bool run();
};

template<typename T>
typename test_tree<T>::array_tree test_tree<T>::get_tree(const T * data, const size_t size)
{
    if (size == 0) return nullptr;
    array_tree root = new tree<T>::node[size];
    for (size_t i = 0; i < size; ++i) {
        root[i].data = data[i];
        size_t r = 2 * i + 1;
        size_t l = 2 * i + 2;
        if (r<size)
            root[i].right = root + r;
        else root[i].right = nullptr;
        if (l < size)
            root[i].left = root + l;
        else root[i].left = nullptr;
    }
    return root;
}

template<typename T>
inline bool test_tree<T>::copy_tree()
{
    for (size_t i = 0; i < 100; ++i) {
        T *test_data = get_test_data(i);
        array_tree test = get_tree(test_data, i);        
        tree<T>::node *t = tree<T>::copy_tree(test);
        assert(tree<T>::equals_tree(t,test));
        delete[] test;
        delete[] test_data;
    }
#ifdef _DEBUG
    std::cerr << "test_tree::copy_tree : OK" << std::endl;
#endif
    return true;
}

template<typename T>
inline bool test_tree<T>::run()
{
    return copy_tree();
}

template <typename T> 
T *test_tree<T>::get_test_data(const size_t size)
{
    /* �� �������� ��� �������� ������ ������������� ����.
       �� ���������� �� ������������� ������ 
       ��� ������� �������� ������� ���� ������
    */
    return nullptr;
}

// ������������� ������� ��� ���� int
template<> int *test_tree<int>::get_test_data(const size_t size)
{
    if (size == 0) return nullptr;
    int * data = new int[size];
    for (size_t i = 0; i < size; ++i)
        data[i] = std::rand();
    return data;
}
