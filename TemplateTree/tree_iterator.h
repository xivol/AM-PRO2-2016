//
// ������������ ������ �19. ����������� ���� ������. �������� ������ � ����������
// tree_iterator.h
//
#pragma once
#include "crtdynmem.h"
#include <algorithm>
#include <iostream>
#include "stack.h"

template <typename T>
class tree {
protected:
	// ���� ������
	struct node
	{
		// ��� ������ � ���� ������
		T data;
		// ��������� �� ����� � ������ ����������
		node *left, *right;
	};

	// ������ ������
	node *root;

	// ��������� ���� ��� ������������ ������
	node super_root = { T(), nullptr, nullptr };
	// ������������� ���������� ����
	void super_root_init();


	// ����������� ����� ����������� ������ �� ������
	static node *copy_tree(node* root);
	// ����������� ����� ������������ ������ ��� ������
	static void delete_tree(node *root);
	// ����������� ����� ������ ������ � ��������� ����� � ���� ������
	static void print_tree(std::ostream &os, const node *root, const size_t spaces = 0);
	// ����������� ����� ��������� �������� �� ���������
	static bool equals_tree(const node *first, const node *second);

	// ����� �������� ��������� �� ��������� �������
	// ��� �������� ������ ������
	class iterator;
	iterator make_iterator(node *t);
public:
	// ����������� �� ���������
	tree() : root(nullptr) {}
	// ����������� �����������
	tree(const tree & t);
	// �������� ������������
	tree &operator=(const tree & t);
	// ����������
	~tree();

	// ������� ������ � ��������� �����
	void print(std::ostream &os = std::cout);

	// ���������� ����� ������
	size_t size();
	// ������� ������
	size_t depth();
	// ������ ������
	size_t width();

	// �������� ��������� �������� �� ���������
	bool operator==(const tree<T> &t);
	// �������� ��������� �������� �� �����������
	bool operator!=(const tree<T> &t);

	// �������� ������ ����� ������ � ��������� �������
	class iterator {
		// ���� ����-�������
		stack<node *> parents;
		// ��������� �� ������� ����
		node *current;
		// ��������� �� ���� ������
		const tree *collection;

		// ����������� � �������� ����������
		iterator(const tree *collection, node *current);
		// ����������� ��� ������/����� ���������
		iterator(const tree *collection, bool reverse_begin = false);
		// ��������� ���������� �� current ���� � ������
		node* next_infix();
		// ��������� ������� ����� current ���� � ������
		node* prev_infix();
	public:

		// ������� �� ��������� ����
		iterator &operator++();
		iterator operator++(int);

		// ������� �� ���������� ����
		iterator &operator--();
		iterator &operator--(int);

		// ��������� �������� � ���� ������
		T operator*();

		// �������� ��������� ���������� �� ���������
		bool operator== (const iterator & it);
		bool operator!= (const iterator & it);

		// ������������� �����, ����� ������ � �������� �������������
		friend class tree;
	};

	// ��������� �� ������ ���������� ������
	iterator begin();

	// ��������� �� ����� ���������� ������
	iterator rbegin();

	// ��������� �� ������ ������
	iterator end();

	// ��������� �� ������ ������� � �������� ���������
	iterator find(const T &x);

	// ����� ��� �������� �������� ��������
	friend class tree_maker;
	// ����������� �����
	template <typename P> friend class test_tree;
};

template <typename T>
typename tree<T>::node *tree<T>::copy_tree(node* root)
{
    if (root == nullptr) return nullptr;
    node * t = new node;
    t->data = root->data;
    t->left = copy_tree(root->left);
    t->right = copy_tree(root->right);
    return t;
}

template <typename T>
void tree<T>::delete_tree(node *root)
{
    if (root == nullptr) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

template <typename T>
void tree<T>::print_tree(std::ostream &os, const node *root, size_t spaces)
{
    if (root == nullptr) return;
    print_tree(os, root->right, spaces + 1);
    for (int i = 0; i < spaces; i++) os << '\t';
    os << root->data << std::endl;
    print_tree(os, root->left, spaces + 1);
}

template<typename T>
bool tree<T>::equals_tree(const node *root1, const node *root2)
{
	if (root1 == root2) return true;
	if (root1 == nullptr && root2 == nullptr) return true;
	if (root1 != nullptr && root2 != nullptr)
		if (root1->data == root2->data)
			return equals_tree(root1->right, root2->right) &&
			equals_tree(root1->left, root2->left);
	return false;
}

template<typename T>
inline void tree<T>::super_root_init()
{
	super_root.left = root;
	super_root.right = root;
}

template <typename T>
tree<T>::tree(const tree & t)
{
	root = copy_tree(t.root);
	// �������������� ������,
	// ��������� ������ ������������ �� ������
	super_root_init();
}

template <typename T>
tree<T> &tree<T>::operator=(const tree & t)
{
	delete_tree(root);
	root = copy_tree(t.root);
	// �������������� ������,
	// ��������� ������ ������������ �� ������
	super_root_init();
	return *this;
}

template <typename T>
typename tree<T>::node *tree<T>::iterator::next_infix()
{
	if (current == nullptr) return nullptr;
	node *cur = current;
	// ���� � �������� ���� ���� ������ ���������
	if (cur->right != nullptr) {
		parents.push(cur);  // ���������� ����
		cur = cur->right;
		// ��������� � ����� ����� ����
		while (cur->left != nullptr) {
			parents.push(cur);  // ���������� ����
			cur = cur->left;
		}
	}
	// ���� � �������� ���� ��� ������� ���������
	else {
		// ���������� ���������� ������
		node *t = parents.top();
		// ���� �� ������ �� ������, ����� ��������� ����� �� ������
		while (cur == t->right) {
			cur = t;
			parents.pop();  // ��������� ������
			if (parents.is_empty()) break;
			t = parents.top();
		}
		// ���� �� ����� �� ����� ������
		if (!parents.is_empty()) {
			cur = t;
			parents.pop();
		}
	}
	return cur;
}

template <typename T>
tree<T>::iterator::iterator(const tree *collection, node *current) :
    collection(collection),current(current)
{
	if (current == nullptr)
		// ���� �������� ����, ������ �� ����� ������������������
		this->current = const_cast<node*>(&this->collection->super_root);
	else {
		// ��� ���������� ������ �������� ������ ����� ���������� ���� �������
		node *t = const_cast<node*>(&this->collection->super_root);
		// �������� �� ������ �� �������� �������� � ��������� ���� �������
		while (t != current)
			t = next_infix(t);
	} 
}

template <typename T>
tree<T>::iterator::iterator(const tree *collection, bool reverse_begin) :
    collection(collection)
{
    if (!reverse_begin)
	// ���� ����� ������ ������� ��� ��������� ������
        this->current = next_infix(const_cast<node*>(&this->collection->super_root));
}
template<typename T>
inline iterator tree<T>::make_iterator(node * t)
{
	return iterator(this, t);
}
