#pragma once

#include "tree.h"

template <typename T>
class bst : public tree<T> 
{
	static void insert_tree(shared_ptr<node> &root, const T &x);
	static shared_ptr<node> find_tree(shared_ptr<node> &root, const T &x);
	static void remove_tree(shared_ptr<node> &root);
	static shared_ptr<node> leftmost_tree(shared_ptr<node> &root);
public:
	
	bst() {}
	bst(const bst &t) : tree<T>(t) {}
	
	bst &operator=(const bst &t) 
	{
		tree<T>::operator=(t);
		return *this;
	}


	void insert(const T &x) 
	{
		insert_tree(root, x);
	}

	bool contains(const T &x) const;

	T &find(const T &x);

	void find_insert(const T &x);

	void remove(const T &x);

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
