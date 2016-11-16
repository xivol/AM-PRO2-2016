#pragma once
#include "tree.h"


template <typename T>
class bst : public tree<T>
{
protected:
    typedef  tree<T>::node node;
    static node *insert_tree(node *&root, const T &x);
    static node *&find_tree(node *& const root, const T &x);
    static void remove_tree(node *&root);
    static node *&leftmost(node *const&  root);
    static node *&rightmost(node *const&  root);
public:
	bst() {}
	bst(const bst& t) :tree<T>(t) {}

	bst &operator=(const bst &t)
	{
		tree<T>::operator=(t);
		return *this;
	}

    iterator insert(const T &x)
    {
        node* t = insert_tree(root, x);
        super_root_init();
        return make_iterator(t);
    }

    iterator find(const T &x) const
    {
        return make_iter(find_tree(root, x));
    }

    bool contains(const T &x) const
    {
        return find_tree(root, x) != nullptr;
    }

    iterator find_insert(const T &x)
    {
        node *&t = find_tree(tree<T>::root, x);
        if (t == nullptr) {
            t = insert_tree(t, x);
            super_root_init();
        }
        return make_iterator(t);
    }

    void remove(const T &x)
    {
        remove_tree(find_tree(root, x));
		super_root_init();
    }

	void remove(iterator &it)
	{
		if (it == end()) return;
		remove_tree(tree<T>::find_tree(root, it));
		super_root_init();
	}
	iterator min() const
	{
		return tree<T>::make_iterator(leftmost(root));
	}
	iterator max() const
	{
		return make_iterator(rightmost(root));
	}
};

template<typename T>
typename bst<T>::node * bst<T>::insert_tree(node *& root, const T & x)
{
    if (root == nullptr) {
        root = new node;
        root->data = x;
        root->left = nullptr;
        root->right = nullptr;
        return root;
    }
    if (x < root->data)
        return insert_tree(root->left, x);
    else
        return insert_tree(root->right, x);
}


template<typename T>
typename bst<T>::node *& bst<T>::find_tree(tree<T>::node *& const root, const T & x)
{
    if (root == nullptr) return root;
    if (root->data == x) return root;
    if (x < root->data)
        return find_tree(root->left, x);
    else
        return find_tree(root->right, x);
}

template<typename T>
inline void bst<T>::remove_tree(tree<T>::node *&root)
{
    if (root == nullptr) return;    
    if (root->left == nullptr || root->right == nullptr) {    
        node *t = nullptr;
        if (root->right == nullptr)
            t = root->left;
        if (root->left == nullptr)
            t = root->right;
        delete root;
        root = t;
    }
    else {
        node *&t = leftmost(root->right);
        root->data = t->data;
        node *p = t->right;
        delete t;
        t = p;
    }
}

template<typename T>
typename bst<T>::node *& bst<T>::leftmost(node *const& root)
{
	if (root == nullptr) return const_cast<node*&>(root);
	node *&t = const_cast<node*&>(root);
    while (t->left != nullptr) {
        t = t->left;
    }
    return t;
}

template<typename T>
typename bst<T>::node *& bst<T>::rightmost( node *const&  root)
{
    if (root == nullptr) return const_cast<node*&>(root);
    node *&t = const_cast<node*&>(root);
    while (t->right != nullptr) {
        t = t->right;
    }
    return t;
}
