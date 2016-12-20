#pragma once

#include "tree.h"

template <typename T>
class bst : public tree<T> 
{
    // Рекурсивная функция вставки элемента в дерево поиска
	static void insert_tree(shared_ptr<node> &root, const T &x);

    // Рекурсивный поиск элемента в дереве
	static shared_ptr<node> find_tree(shared_ptr<node> &root, const T &x);

    // Рекурсивное удаление элемента из дерева
	static void remove_tree(shared_ptr<node> &root);

    // Поиск самого левого поддерева в дереве
	static shared_ptr<node> leftmost_tree(shared_ptr<node> &root);

    // Рекурсивный вывод элементов дерева в инфиксном порядке
    static void print_infix(const shared_ptr<node> &root, ostream &os);
public:
	
	bst() {}
	bst(const bst &t) : tree<T>(t) {}
	
	bst &operator=(const bst &t) 
	{
		tree<T>::operator=(t);
		return *this;
	}

    // Вставка элемента в дерево
	void insert(const T &x) 
	{
		insert_tree(root, x);
	}
    
    // Проверка на существование элемента в дереве
	bool contains(const T &x) const;
    
    // Удаление элемента из дерева
	void remove(const T &x);

    // Вывод элементов дерева в инфиксном порядке
    friend ostream &operator<<(ostream &os; const bst &t);

};

template<typename T>
void bst<T>::insert_tree(shared_ptr<node>& root, const T & x)
{
	if (!root)
		root = make_shared<node>(x);
	else
		if (x < root->data)
			insert_tree(root->left, x);
		else
			insert_tree(root->right, x);
}
