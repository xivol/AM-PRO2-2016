#pragma once

// Описание узла дерева:
//     data - значение в узле дерева;
//     left - укзатель на левое поддерево;
//     right - указатель на правое поддерево.
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

// Функция копирования дерева.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
// Возвращает указатель на корневой элемент копии дерева.
template <typename T>
tree<T> *copy_tree(const tree<T> *root) {
	if (root == nullptr) return nullptr;
	tree<T> *new_tree = new tree<T>(root->data);
	new_tree->right = copy_tree(root->right);
	new_tree->left = copy_tree(root->left);
	return new_tree;
}

// Функция удаления дерева.
// Входные параметры:
//     root - указатель на корневой элемент дерева.
// root == nullptr после выполнения этой функции.
template <typename T>
void delete_tree(tree<T> *&root) {
	if (root == nullptr) return;
	delete_tree(root->right);
	delete_tree(root->left);
	delete root;
	root = nullptr;
}

// Функция вывода дерева на консоль.
// Входные параметры:
//     root - указатель на корневой элемент дерева,
//     os - целевой поток вывода,
//     spaces - количество пробелов перед элементов.
template <typename T>
void print_tree(const tree<T> *root, std::ostream &os = std::cout, const size_t spaces = 0) {
	if (root == nullptr) return;
	print_tree(root->right, os, spaces + 1);
	for (int i = 0; i < spaces; ++i) 
		os << '\t';
	os << root->data << std::endl;
	print_tree(root->left, os, spaces + 1);
}