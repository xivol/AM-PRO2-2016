//
// Лабораторная работа №18. Абстрактные типы данных. Двоичное дерево
// main.cpp
//
#include <iostream>
#include "tree.h"
#include "test_tree.h"
#include "tree_maker.h"

int main()
{
    test_tree<int>::run();
    tree<int> t = tree_maker::random_tree<int>(10);
    t.print();
	system("pause");
}