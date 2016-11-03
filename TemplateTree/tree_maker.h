#pragma once
#include "tree_iterator.h"
#include <iostream>


class tree_maker {
	template <typename T>
	static void random_insert(typename tree<T>::node *&root, const T &x);
public:
	template <typename T> 
	static tree<T> random_tree(const size_t count, std::istream &is = std::cin);
	template <typename T>
	static tree<T> random_tree(const size_t count, const T *source);
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
		if (rand() % 2 == 0)  // вставляем элемент в случайное поддерево
			random_insert(root->left, x);
		else
			random_insert(root->right, x);
	}
}

template <typename T>
tree<T> tree_maker::random_tree(const size_t count, std::istream &is)
{
	tree<T> new_tree;
	for (size_t i = 0; i < count; ++i) {
		T t;
		if (is >> t)
			random_insert(new_tree.root, t);
	}
	return new_tree;
}

template <typename T>
tree<T> tree_maker::random_tree(const size_t count, const T *source)
{
	tree<T> new_tree;
	for (size_t i = 0; i < count; ++i) {
		random_insert(new_tree.root, source[i]);
	}
	return new_tree;
}