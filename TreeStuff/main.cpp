//
// Лабораторная работа №2. Деревья
// main.cpp
//
#include <iostream>
#include "tree.h"
#include "test_tree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    test_get_array_tree();
    tree *root = get_tree(10);
    print_tree(root);
    cout << leaves_count(root) << endl;
    delete_tree(root);

    _CrtDumpMemoryLeaks();

    system("pause");
    return 0;
}