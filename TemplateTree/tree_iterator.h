#pragma once
#include "stack.h"
#include <algorithm>
#include <iostream>

template <typename T>
class tree {
protected:
	struct node {
		T data;
		node *left, *right;
	};

    node super_root = { T(), nullptr, nullptr };
	node *root;

	node *copy_tree(node* root);
	void delete_tree(node *root);
    void print_tree(std::ostream &os, const node *root, const size_t spaces = 0);
    void super_root_init();
    size_t size(const node *root);
    size_t depth(const node *root);
    size_t width(const node *root, const size_t depth);
    node *find_tree(const T &x, const node *root);
public:
    tree() : root(nullptr) { }
    tree(const tree & t);
    tree &operator=(const tree & t);
    virtual ~tree();

    void print(std::ostream &os = std::cout);

    size_t size();
	size_t depth();
	size_t width();

    class iterator {	
		stack<node *> parents;
		node *current;
		const tree *collection;
        
        iterator(const tree *collection, node *current);
        iterator(const tree *collection, bool begin = true);
        node* next_infix(node *cur);
        node* prev_infix(node *cur);       
	public :

        iterator &operator++();        
        iterator operator++(int);

        iterator &operator--();
        iterator &operator--(int);

        T operator*();

        bool operator== (const iterator & it);
        bool operator!= (const iterator & it);
        friend class tree;
	};

	iterator begin() 
    {
        return iterator(this);	
    }

    iterator rbegin()
    {
        return iterator(this,false);
    }

	iterator end() 
    { 
        return iterator(this, &super_root);	
    }

    iterator find(const T &x);

    friend class tree_maker;
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
    return width(root->right, depth-1) + width(root->left, depth-1);

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
    super_root_init();
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

template <typename T>
tree<T>::iterator::iterator(const tree *collection, node *current) :
    collection(collection),current(current)
{}

template <typename T>
tree<T>::iterator::iterator(const tree *collection, bool begin) :
    collection(collection)
{
    if (begin)
        this->current = next_infix(const_cast<node*>(&this->collection->super_root));
    else
        this->current = prev_infix(const_cast<node*>(&this->collection->super_root));
}

template <typename T>
typename tree<T>::node *tree<T>::iterator::next_infix(node *cur)
{
    if (cur == nullptr) return nullptr;
    if (cur->right != nullptr) {
        parents.push(cur);
        cur = cur->right;
        while (cur->left != nullptr) {
            parents.push(cur);
            cur = cur->left;
        }
    }
    else {
        node *t = parents.top();
        while (cur == t->right) {
            cur = t;
            parents.pop();
            if (parents.is_empty()) break;
            t = parents.top();
        }
        if (cur->right != t && !parents.is_empty()) {
            cur = t;
            parents.pop();
        }
    }
    return cur;
}

template<typename T>
typename tree<T>::node * tree<T>::iterator::prev_infix(node * cur)
{
    if (cur == nullptr) return nullptr;            
    if (!parents.is_empty() && cur == parents.top())
        parents.pop();
    if (cur->left != nullptr) {
        parents.push(cur);
        cur = cur->left;
        while (cur->right != nullptr) {
            parents.push(cur);
            cur = cur->right;
        }
        return cur;
    }
    else {
        node* t = parents.top();
        while (cur == t->left) {
            cur = t;
            parents.pop();
            if (parents.is_empty()) break;
            t = parents.top();
        }
        return t;
    }
}

template <typename T>
typename tree<T>::iterator &tree<T>::iterator::operator++()
{
    current = next_infix(current);
    return *this;
}

template <typename T>
typename tree<T>::iterator tree<T>::iterator::operator++(int)
{
    iterator it = current;
    current = next_infix(current);
    return it;
}

template<typename T>
typename tree<T>::iterator & tree<T>::iterator::operator--()
{
    current = prev_infix(current);
    return *this;
}

template<typename T>
typename tree<T>::iterator & tree<T>::iterator::operator--(int)
{
    iterator it = *this;
    current = prev_infix(current);
    return it;
}

template <typename T>
T tree<T>::iterator::operator*()
{
    //std::cout << std::endl << parents << std::endl;
    return current->data;
}

template <typename T>
bool tree<T>::iterator::operator== (const iterator & it)
{
    return collection == it.collection && current == it.current;
}

template <typename T>
bool tree<T>::iterator::operator!= (const iterator & it)
{
    return !(*this == it);
}

template <typename P>
std::ostream &operator<<(std::ostream &os, const tree<P> &t)
{
    t.print(os);
    return os;
}

template<typename T>
typename tree<T>::iterator tree<T>::find(const T & x)
{
    return iterator(this, find_tree(x, root));
}

template<typename T>
typename tree<T>::node * tree<T>::find_tree(const T & x, const node *root)
{
    if (root == nullptr) return nullptr;    
    if (node *t = find_tree(x, root->left)) return t;
    if (root->data == x) return const_cast<node*>(root);
    return find_tree(x, root->right);
}

template<typename T>
inline void tree<T>::super_root_init()
{
    super_root.left = root;
    super_root.right = root; 
}
