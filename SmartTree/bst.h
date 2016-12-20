#pragma once

#include "tree.h"

template <typename T>
class bst : public tree<T> 
{
    // ����������� ������� ������� �������� � ������ ������
	static void insert_tree(shared_ptr<node> &root, const T &x);

    // ����������� ����� �������� � ������
	static shared_ptr<node> find_tree(shared_ptr<node> &root, const T &x);

    // ����������� �������� �������� �� ������
	static void remove_tree(shared_ptr<node> &root);

    // ����� ������ ������ ��������� � ������
	static shared_ptr<node> leftmost_tree(shared_ptr<node> &root);

    // ����������� ����� ��������� ������ � ��������� �������
    static void print_infix(const shared_ptr<node> &root, ostream &os);
public:
	
	bst() {}
	bst(const bst &t) : tree<T>(t) {}
	
	bst &operator=(const bst &t) 
	{
		tree<T>::operator=(t);
		return *this;
	}

    // ������� �������� � ������
	void insert(const T &x) 
	{
		insert_tree(root, x);
	}
    
    // �������� �� ������������� �������� � ������
	bool contains(const T &x) const;
    
    // �������� �������� �� ������
	void remove(const T &x);

    // ����� ��������� ������ � ��������� �������
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
