#pragma once
#include <algorithm>
#include <iostream>

template <typename T>
class tree
{
protected:
    struct node
    {
        T data;
        node *left, *right;
    };

    node *root;

    static node *copy_tree(node* root);
    static void delete_tree(node *root);
    static void print_tree(std::ostream &os, const node *root, const size_t spaces = 0);
    static size_t size(const node *root);
    static size_t depth(const node *root);
    static size_t width(const node *root, const size_t depth);
    static bool equals_tree(const node *root1, const node *root2);
public:
    tree() : root(nullptr) {}
    tree(const tree & t);
    tree &operator=(const tree & t);
    virtual ~tree();

    void print(std::ostream &os = std::cout);

    size_t size();
    size_t depth();
    size_t width();

    bool operator==(const tree &t);
    bool operator!=(const tree &t);

    friend class tree_maker;
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
inline size_t tree<T>::size(const node * root)
{
    return root == nullptr ? 0 : size(root->left) + size(root->right) + 1;
}

template<typename T>
inline size_t tree<T>::depth(const node * root)
{
    if (root == nullptr) return 0;
    return std::max(depth(root->left), depth(root->right)) + 1;
}

template<typename T>
inline size_t tree<T>::width(const node * root, const size_t depth)
{
    if (root == nullptr) return 0;
    if (depth == 1) return 1;
    return width(root->right, depth - 1) + width(root->left, depth - 1);

}

template <typename T>
void tree<T>::print(std::ostream &os)
{
    print_tree(os, this->root);
}

template <typename T>
tree<T>::tree(const tree & t)
{
    root = copy_tree(t.root);
}

template <typename T>
tree<T> &tree<T>::operator=(const tree & t)
{
    delete_tree(root);
    root = copy_tree(t.root);
}

template <typename T>
tree<T>::~tree()
{
    delete_tree(root);
}

template<typename T>
inline size_t tree<T>::size()
{
    return size(root);
}

template <typename T>
size_t tree<T>::depth()
{
    return depth(root);
}

template <typename T>
size_t tree<T>::width()
{
    size_t d = depth();
    size_t max_w = 0;
    while (d) {
        max_w = std::max(max_w, width(root, d));
        --d;
    }
    return max_w;
}