#pragma once

// �������� ���� ������:
//     tree::datatype - ��� ������ ������;
//     data - �������� � ���� ������;
//     left - �������� �� ����� ���������;
//     right - ��������� �� ������ ���������.
template <typename Datatype>
struct tree
{
	Datatype data;
	tree *left;
	tree *right;
	tree(): left(nullptr), right(nullptr) {}
	tree(const Datatype &data, tree *left = nullptr, tree *right = nullptr):
		data(data), left(left), right(right) {}
};

// ������� ����������� ������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
// ���������� ��������� �� �������� ������� ����� ������.
template <typename T>
tree<T> *copy_tree(const tree<T> *root) {
	if (root == nullptr) return nullptr;
	tree<T> *new_tree = new tree<T>(root->data);
	new_tree->right = copy_tree(root->right);
	new_tree->left = copy_tree(root->left);
	return new_tree;
}

// ������� �������� ������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������.
// root == nullptr ����� ���������� ���� �������.
template <typename T>
void delete_tree(tree<T> *&root) {
	if (root == nullptr) return;
	delete_tree(root->right);
	delete_tree(root->left);
	delete root;
	root = nullptr;
}

// ������� ������ ������ �� �������.
// ������� ���������:
//     root - ��������� �� �������� ������� ������,
//     os - ������� ����� ������,
//     spaces - ���������� �������� ����� ���������.
template <typename T>
void print_tree(const tree<T> *root, std::ostream &os = std::cout, const size_t spaces = 0) {
	if (root == nullptr) return;
	print_tree(root->right, os, spaces + 1);
	for (int i = 0; i < spaces; ++i) 
		os << '\t';
	os << root->data << std::endl;
	print_tree(root->left, os, spaces + 1);
}