//
// Лабораторная работа №18. Абстрактные типы данных. Двоичное дерево
// tree_maker.h
//
#pragma once
#include <iostream>
#include "tree.h"

// Класс создающий деревья заданной структуры
class tree_maker 
{
    // Рекурсивный метод вставки в случайное поддерево
	template <typename T>
	static void random_insert(typename tree<T>::node *&root, const T &x);
public:

    // Метод заполняющий дерево в случайном порядке
    // заданным количеством элементов из указаного потока ввода 
	template <typename T> 
	static tree<T> random_tree(const size_t count, std::istream &source = std::cin);
};

template <typename T>
void tree_maker::random_insert(typename tree<T>::node *&root, const T &x)
{
	if (root == nullptr) {
		root = new tree<T>::node;
		root->data = x;
		root->left = nullptr;
		root->right = nullptr;
	}
	else {
		if (std::rand() % 2 == 0)  // вставляем элемент в случайное поддерево
			random_insert(root->left, x);
		else
			random_insert(root->right, x);
	}
}

template <typename T>
tree<T> tree_maker::random_tree(const size_t count, std::istream &source)
{
	tree<T> new_tree;
	for (size_t i = 0; i < count; ++i) {
		T t;
		if (source >> t)
			random_insert(new_tree.root, t);
	}
	return new_tree;
}
