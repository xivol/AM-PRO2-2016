#pragma once
#include <algorithm>
#include <iostream>

// ������ ������ �������� ������
template <typename T>
class tree
{
    // ���� ������
    struct node
    {
        // ��� ������ � ���� ������
        T data;
        // ��������� �� ����� � ������ ����������
        node *left, *right;
    };

    // ������ ������
    node *root;

    // ����������� ����� ����������� ������ �� ������
    static node *copy_tree(node* root);

    // ����������� ����� ������������ ������ ��� ������
    static void delete_tree(node *root);

    // ����������� ����� ������ ������ � ��������� ����� � ���� ������
    static void print_tree(std::ostream &os, const node *root, const size_t spaces = 0);   

    // ����������� ����� ��������� �������� �� ���������
    static bool equals_tree(const node *first, const node *second);
public:
    // ����������� �� ���������
    tree() : root(nullptr) {}
    // ����������� �����������
    tree(const tree & t);
    // �������� ������������
    tree &operator=(const tree & t);
    // ����������
    ~tree();

    // ������� ������ � ��������� �����
    void print(std::ostream &os = std::cout);

    // ���������� ����� ������
    size_t size();
    
    // ������� ������
    size_t depth();

    // ������ ������
    size_t width();

    // �������� ��������� �������� �� ���������
    bool operator==(const tree &t);
    // �������� ��������� �������� �� �����������
    bool operator!=(const tree &t);

    // ����� ��� �������� �������� ��������
    // � �������� ����������
    friend class tree_maker;
    // ����������� �����
    template <typename P>
    friend class test_tree<P>;
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