//
// Лабораторная рвбота №2. Деревья
// tree.cpp
//
#include <stdlib.h>
#include <iostream>
#include "crtdynmem.h"
#include "tree.h"

tree *get_tree(const size_t count)
{
    tree *root = nullptr;
    tree::datatype x;
    size_t n = 0;
    while (count > n && std::cin >> x) {
        insert(root, x);
        n += 1;
    }
    return root;
}

void insert(tree *&root, tree::datatype x)
{
    if (root == nullptr) {
        root = new tree;
        root->data = x;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        if (rand() % 2 == 0)  // вставляем элемент в случайное поддерево
            insert(root->left, x);
        else
            insert(root->right, x);
    }
}

void delete_tree(tree *&root)
{
    if (root == nullptr) return;
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
    root = nullptr;
}

void print_tree(const tree *root, size_t space)
{
    if (root == nullptr) return;
    print_tree(root->left, space+1);
    for (int i = 0; i < space; i++) std::cout << '\t';
    std::cout << root->data << std::endl;
    print_tree(root->right, space+1);
}

size_t leaves_count(const tree *root)
{
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) 
        return 1;
    return leaves_count(root->left) + leaves_count(root->right);
}