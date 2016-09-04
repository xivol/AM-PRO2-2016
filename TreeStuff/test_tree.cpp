#include <cassert>
#include <iostream>
#include "crtdynmem.h"
#include "test_tree.h"

array_tree get_array_tree(const tree::datatype *array, const size_t length)
{
    array_tree root = new tree[length];
    for (int i = 0; i < length; i++) {
        root[i].data = array[i];
        size_t r = 2 * i + 1;
        size_t l = 2 * i + 2;
        if (r<length) 
            root[i].right = root + r;
        else root[i].right = nullptr;
        if (l < length)
            root[i].left = root + l;
        else root[i].left = nullptr;
    }
    return root;
}

bool test_get_array_tree()
{
    int n = 5;
    tree::datatype *array = new tree::datatype[n];
    for (int i = 0; i<n; i++) {
        array[i] = rand();
    }
    tree *root = get_array_tree(array, n);
    assert(test_array_tree_rec(array, n, 0, root));
    delete[] root;
    delete[] array;
#ifdef _DEBUG
    std::cerr << "test get_array_tree: OK" << std::endl;
#endif
    return true;
}

bool test_array_tree_rec(const tree::datatype *array, const size_t length, const size_t index, const tree *root)
{
    if (root == nullptr && index >= length) return true;
    if (root->data == array[index]) {
        size_t right = 2 * index + 1;
        size_t left = 2 * index + 2;
        if (right < length && root->right == nullptr)
            return true;
        else
            return test_array_tree_rec(array, length, right, root->right);
        if (left < length && root->left == nullptr)
            return true;
        else
            return test_array_tree_rec(array, length, left, root->left);
    }
    return false;
}