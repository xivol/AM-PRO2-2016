#pragma once
#include "tree.h"

typedef tree *array_tree;

array_tree get_array_tree(const tree::datatype *array, const size_t length);

bool test_array_tree_rec(const tree::datatype *array, const size_t length, const size_t index, const tree *root);