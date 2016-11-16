#pragma once
#include "tree_iterator.h"
#include <iostream>

// Шаблон класса Двоичное Дерево Поиска
template <typename T>
class bst : public tree<T>
{
    typedef  tree<T>::node node;
    // Вставка элемента в дерево и 
    // возвращение указателя на вставленный элемент
    node *insert_tree(node *&root, const T &x);

    // Поиск элемента в дереве
    node *&find_tree(node *&root, const T &x);

    // Удаление указанного элемента из дерева
    void remove_tree(node *&root);

    // Получение самого левого узла в дереве
    node *&leftmost(node *&root);

    // Получение самого правого узла в дереве
    node *&rightmost(node *&root);    
public:
	bst(const bst& t) :tree(t) {}

	bst &operator=(const bst &t)
	{
		tree::operator=(t);
		return *this;
	}

    // Вставка значения и 
    // возвращение итератора на него
    iterator insert(const T &x);

    // Поиск значения в дереве
    iterator find(const T &x) const;

    // Определение наличия значения в дереве
    bool contains(const T &x) const;

    // Поиск и вставка значения в дерево
    iterator find_insert(const T &x);

    // Удаление заданного значения
    void remove(const T &x);

    // Операция сравнения на равенство
    bool operator==(const bst &t);
    // Операция сравнения на неравенство
    bool operator!=(const bst &t);

    template<typename P>
    friend std::istream &operator>>(std::istream &is, bst<P> &t);

    friend class test_bst;
};

template<typename T>
std::ostream &operator<<(std::ostream &os, bst<T> &t);