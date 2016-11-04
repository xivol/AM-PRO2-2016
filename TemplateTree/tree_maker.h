#pragma once
#include "tree_iterator.h"
#include <iostream>


class tree_maker {
	template <typename T>
	static void random_insert(typename tree<T>::node *&root, const T &x);
    template <typename T>
    static bool width_first_insert(typename tree<T>::node *&root, const size_t depth, const T &x);
    template <typename T>
    static typename tree<T>::node *balanced_insert(const size_t count, std::istream &source);
public:
	template <typename T> 
	static tree<T> random_tree(const size_t count, std::istream &source = std::cin);
	template <typename T>
	static tree<T> random_tree(const size_t count, const T *source);
    template <typename T>
    static tree<T> random_tree(const size_t count, T (*source)(void)); 
    template <typename T>
    static tree<T> random_tree(std::istream &source = std::cin);
    template <typename T>
    static tree<T> width_first_tree(size_t count, std::istream &source = std::cin);
    template <typename T>
    static tree<T> balanced_tree(const size_t count, std::istream &source = std::cin);
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

template<typename T>
bool tree_maker::width_first_insert(typename tree<T>::node *& root, const size_t depth, const T & x)
{
    if (depth == 0) return false;
    if (root == nullptr) {
        if (depth == 1) {
            root = new tree<T>::node;
            root->data = x;
            root->left = nullptr;
            root->right = nullptr;
            return true;
        }
    }
    else {
        bool inserted = width_first_insert(root->left, depth - 1, x) ||  
            width_first_insert(root->right, depth - 1, x);
        return inserted;
    }
    return false;
}

template<typename T>
typename tree<T>::node * tree_maker::balanced_insert(const size_t count, std::istream & source)
{
    if (count == 0 ) return nullptr;
    T x;
    if (source >> x) {
        tree<T>::node *t = new tree<T>::node;
        t->data = x;
        t->left = balanced_insert<T>(count / 2, source);
        if (count / 2)
            t->right = balanced_insert<T>(count - count / 2 - 1, source);
        else
            t->right = nullptr;
        return t;
    } else
        return nullptr;
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

template <typename T>
tree<T> tree_maker::random_tree(std::istream &source)
{
    tree<T> new_tree;
    T t;
    while (source >> t)
        random_insert(new_tree.root, t);
    return new_tree;
}

template<typename T>
tree<T> tree_maker::width_first_tree(size_t count, std::istream & source)
{
    tree<T> new_tree;
    size_t depth = std::ceill(std::log(count) / std::log(2.0));
    size_t width = 1;    
    for (size_t i = 1; i <= depth; ++i) {
        for (size_t j = 0; j < width && count>0; ++j) {
            T t;
            if (source >> t) {
                width_first_insert(new_tree.root, i, t);
                count--;
            }
        }
        width *= 2;
    }
    return new_tree;
}

template<typename T>
tree<T> tree_maker::balanced_tree(const size_t count, std::istream & source)
{
    tree<T> new_tree;
    new_tree.root = balanced_insert<T>(count, source);
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

template<typename T>
tree<T> tree_maker::random_tree(const size_t count, T(*source)(void))
{
    tree<T> new_tree;
    for (size_t i = 0; i < count; ++i) {
        random_insert(new_tree.root, source());
    }
    return new_tree;
}