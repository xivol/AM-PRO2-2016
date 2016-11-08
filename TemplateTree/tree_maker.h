#pragma once
#include <iostream>
#include "tree.h"

// ����� ��������� ������� �������� ���������
class tree_maker {
    // ����������� ����� ������� � ��������� ���������
	template <typename T>
	static void random_insert(typename tree<T>::node *&root, const T &x);
public:
    // ����� ����������� ������ �������� ����������� ��������� 
    // �� ��������� ������ ����� � ��������� �������
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
		if (std::rand() % 2 == 0)  // ��������� ������� � ��������� ���������
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
