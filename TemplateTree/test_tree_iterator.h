#pragma once
#include <cassert>
#include <iostream>
#include "test_tree.h"
#include "tree_iterator.h"

// Шаблон тестирующего класса для tree<T>
template <typename T>
class test_tree_iterator
{
	// Определим тип массив узлов
	typedef typename tree<T>::node *array_tree;

	// Рекурсивное заполнение массива индексов в инфиксном порядке
	static void infix_nodes(array_tree *nodes, size_t &index_out, array_tree cur) {
		if (cur == nullptr) return;
		infix_index(nodes, index_out, root->left);
		indices[index_out++] = cur;
		infix_index(nodes, index_out, root->right)
	}

	// Тест для copy_tree
	static bool next_infix();
public:
	// Метод запуска всех тестов
	static bool run();
};

template<typename T>
inline bool test_tree_iterator<T>::next_infix()
{
	size_t n = 10;
	T *data = test_tree<T>::get_test_data(n);
	array_tree t = test_tree<T>::get_tree(data, n);
	array_tree *nodes;
	infix_nodes(nodes, index_out, t);
	
	array_tree p = next_infix(t);
	for (size_t i = 0; i < n; ++i) {

	}
	
	return true;
}