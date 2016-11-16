#pragma once
#include "tree_iterator.h"
#include <iostream>

// ������ ������ �������� ������ ������
template <typename T>
class bst : public tree<T>
{
    typedef  tree<T>::node node;
    // ������� �������� � ������ � 
    // ����������� ��������� �� ����������� �������
    node *insert_tree(node *&root, const T &x);

    // ����� �������� � ������
    node *&find_tree(node *&root, const T &x);

    // �������� ���������� �������� �� ������
    void remove_tree(node *&root);

    // ��������� ������ ������ ���� � ������
    node *&leftmost(node *&root);

    // ��������� ������ ������� ���� � ������
    node *&rightmost(node *&root);    
public:
	bst(const bst& t) :tree(t) {}

	bst &operator=(const bst &t)
	{
		tree::operator=(t);
		return *this;
	}

    // ������� �������� � 
    // ����������� ��������� �� ����
    iterator insert(const T &x);

    // ����� �������� � ������
    iterator find(const T &x) const;

    // ����������� ������� �������� � ������
    bool contains(const T &x) const;

    // ����� � ������� �������� � ������
    iterator find_insert(const T &x);

    // �������� ��������� ��������
    void remove(const T &x);

    // �������� ��������� �� ���������
    bool operator==(const bst &t);
    // �������� ��������� �� �����������
    bool operator!=(const bst &t);

    template<typename P>
    friend std::istream &operator>>(std::istream &is, bst<P> &t);

    friend class test_bst;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, bst<T> &t);