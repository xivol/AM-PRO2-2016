#pragma once
#include <iostream>
#include <memory>
using namespace std;
// ������ ������ �������� ������
template <typename T>
class tree
{
	// ���� ������
	struct node
	{
		// ��� ������ � ���� ������
		T data;
		// ��������� �� ����� � ������ ����������
		shared_ptr<node> left, right;
		node(const T &data);
		~node();
	};

	// ������ ������
	shared_ptr<node> root;

	// ����������� ����� ����������� ������ �� ������
	static shared_ptr<node> copy_tree(const shared_ptr<node> root);

	// ����������� ����� ������ ������ � ��������� ����� � ���� ������
	static void print_tree(std::ostream &os, const shared_ptr<node> &root, const size_t spaces = 0);

	static void tree<T>::insert_tree(shared_ptr<node> &root, const T &x);
public:
	// ����������� �� ���������
	tree() : root(nullptr) {}
	
	// ����������� �����������
	tree(const tree & t)
	{
		root = copy_tree(t.root);
	}
	
	// �������� ������������
	tree &operator=(const tree & t) {
		root = nullptr;
		root = copy_tree(t.root);
		return *this;
	}

	// ����������
	~tree() 
	{
		cout << "������ : " << this << endl;
	}

	// ������� ������ � ��������� �����
	void print(std::ostream &os = std::cout)
	{
		print_tree(os, root);
	}


	void push(const T &x) {
		insert_tree(root, x);
	}

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

	// ����� ��� �������� �������� ��������
	friend class tree_maker;

	// ����������� �����
	template <typename P> friend class test_tree;
};


template<typename T>
inline tree<T>::node::node(const T & data) :
	data(data), left(nullptr), right(nullptr)
{}

template<typename T>
tree<T>::node::~node()
{
	cout << data << " : �����������" << endl;
}

template<typename T>
shared_ptr<typename tree<T>::node> tree<T>::copy_tree(const shared_ptr<node> root)
{
	if (!root) return shared_ptr<node>(nullptr);
	shared_ptr<node> new_root = make_shared<node>(root->data);
	new_root->left = copy_tree(root->left);
	new_root->right = copy_tree(root->right);
	return new_root;
}

template<typename T>
inline void tree<T>::delete_tree(const shared_ptr<node>& root)
{
	root = nullptr;
}

template <typename T>
void tree<T>::print_tree(std::ostream &os, const shared_ptr<node> &root, size_t spaces)
{
	if (!root) return;
	print_tree(os, root->right, spaces + 1);
	for (int i = 0; i < spaces; ++i) 
		os << '\t';
	os << root->data << std::endl;
	print_tree(os, root->left, spaces + 1);
}

template<typename T>
void tree<T>::insert_tree(shared_ptr<node> &root, const T &x)
{
	if (!root)
		root = make_shared<node>(x);
	else
		if (x < root->data)
			insert_tree(root->left, x);
		else
			insert_tree(root->right, x);
}
