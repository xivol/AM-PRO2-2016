#pragma once
#include <algorithm>
#include <iostream>

// Шаблон класса двоичное дерево
template <typename T>
class tree
{
    // Узел дерева
    struct node
    {
        // Тип данных в узле дерева
        T data;
        // Указатели на левое и правое поддеревья
        node *left, *right;
    };

    // Корень дерева
    node *root;

    // Рекурсивный метод копирования данных из дерева
    static node *copy_tree(node* root);

    // Рекурсивный метод освобождения памяти для дерева
    static void delete_tree(node *root);

    // Рекурсивный метод вывода данных в указанный поток в виде дерева
    static void print_tree(std::ostream &os, const node *root, const size_t spaces = 0);   

    // Рекурсивный метод сравнения деревьев на равенство
    static bool equals_tree(const node *first, const node *second);
public:
    // Конструктор по умолчанию
    tree() : root(nullptr) {}
    // Конструктор копирования
    tree(const tree & t);
    // Операция присваивания
    tree &operator=(const tree & t);
    // Деструктор
    ~tree();

    // Функция вывода в указанный поток
    void print(std::ostream &os = std::cout);

    // Количество узлов дерева
    size_t size();
    
    // Глубина дерева
    size_t depth();

    // Ширина дерева
    size_t width();

    // Операция сравнения деревьев на равенство
    bool operator==(const tree<T> &t);
    // Операция сравнения деревьев на неравенство
    bool operator!=(const tree<T> &t);

    // Класс для создания двоичных деревьев
    // с заданной структурой
    friend class tree_maker;

    // Тестирующий класс
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
    root = nullptr;
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
bool tree<T>::equals_tree(const node *first, const node *second)
{
    if (first == second) return true;
    if (first != nullptr && second != nullptr)
        if (first->data == second->data)
            return equals_tree(first->right, second->right) &&
            equals_tree(first->left, second->left);
    return false;
}