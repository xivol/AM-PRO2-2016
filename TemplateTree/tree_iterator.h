//
// Лабораторная работа №19. Абстрактные типы данных. Двоичное дерево с итератором
// tree_iterator.h
//
#pragma once
#include "crtdynmem.h"
#include <algorithm>
#include <iostream>
#include "stack.h"

template <typename T>
class tree {
protected:
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

	// Барьерный узел для итеративного обхода
	node super_root = { T(), nullptr, nullptr };
	// Инициализация барьерного узла
	void super_root_init();


	// Рекурсивный метод копирования данных из дерева
	static node *copy_tree(node* root);
	// Рекурсивный метод освобождения памяти для дерева
	static void delete_tree(node *root);
	// Рекурсивный метод вывода данных в указанный поток в виде дерева
	static void print_tree(std::ostream &os, const node *root, const size_t spaces = 0);
	// Рекурсивный метод сравнения деревьев на равенство
	static bool equals_tree(const node *first, const node *second);

	// Метод создания итератора на указанный элемент
	// для потомков класса дерево
	class iterator;
	iterator make_iterator(node *t);
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

	// Итератор обхода узлов дерева в инфиксном порядке
	class iterator {
		// Стек улов-предков
		stack<node *> parents;
		// Указатель на текущий узел
		node *current;
		// Указатель на само дерево
		const tree *collection;

		// Конструктор с заданным указателем
		iterator(const tree *collection, node *current);
		// Конструктор для начала/конца коллекции
		iterator(const tree *collection, bool reverse_begin = false);
		// Получение следующего за current узла в дереве
		node* next_infix();
		// Получение идущего перед current узла в дереве
		node* prev_infix();
	public:

		// Переход на следующий узел
		iterator &operator++();
		iterator operator++(int);

		// Переход на предыдущий узел
		iterator &operator--();
		iterator &operator--(int);

		// Получение значения в узле дерева
		T operator*();

		// Операции сравнения итераторов на равенство
		bool operator== (const iterator & it);
		bool operator!= (const iterator & it);

		// Дружественный класс, имеет доступ к закрытым конструкторам
		friend class tree;
	};

	// Указатель на начало инфиксного обхода
	iterator begin();

	// Указатель на конец инфиксного обхода
	iterator rbegin();

	// Указатель за концом дерева
	iterator end();

	// Указатель на первый элемент с заданным значением
	iterator find(const T &x);

	// Класс для создания двоичных деревьев
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
bool tree<T>::equals_tree(const node *root1, const node *root2)
{
	if (root1 == root2) return true;
	if (root1 == nullptr && root2 == nullptr) return true;
	if (root1 != nullptr && root2 != nullptr)
		if (root1->data == root2->data)
			return equals_tree(root1->right, root2->right) &&
			equals_tree(root1->left, root2->left);
	return false;
}

template<typename T>
inline void tree<T>::super_root_init()
{
	super_root.left = root;
	super_root.right = root;
}

template <typename T>
tree<T>::tree(const tree & t)
{
	root = copy_tree(t.root);
	// Инициализируем барьер,
	// поскольку дерево потенциально не пустое
	super_root_init();
}

template <typename T>
tree<T> &tree<T>::operator=(const tree & t)
{
	delete_tree(root);
	root = copy_tree(t.root);
	// Инициализируем барьер,
	// поскольку дерево потенциально не пустое
	super_root_init();
	return *this;
}

template <typename T>
typename tree<T>::node *tree<T>::iterator::next_infix()
{
	if (current == nullptr) return nullptr;
	node *cur = current;
	// Если у текущего узла есть правое поддерево
	if (cur->right != nullptr) {
		parents.push(cur);  // запоминаем путь
		cur = cur->right;
		// Переходим в самый левый узел
		while (cur->left != nullptr) {
			parents.push(cur);  // запоминаем путь
			cur = cur->left;
		}
	}
	// Если у текущего узла нет правого поддерева
	else {
		// Рассмотрим последнего предка
		node *t = parents.top();
		// Если мы справа от предка, нужно подднятся вверх по дереву
		while (cur == t->right) {
			cur = t;
			parents.pop();  // извлекаем предка
			if (parents.is_empty()) break;
			t = parents.top();
		}
		// Если не вышли за конец дерева
		if (!parents.is_empty()) {
			cur = t;
			parents.pop();
		}
	}
	return cur;
}

template <typename T>
tree<T>::iterator::iterator(const tree *collection, node *current) :
    collection(collection),current(current)
{
	if (current == nullptr)
		// Если передали ноль, уходим за конец последовательности
		this->current = const_cast<node*>(&this->collection->super_root);
	else {
		// Для правильной работы итератор должен иметь корректный стек предков
		node *t = const_cast<node*>(&this->collection->super_root);
		// Проходим по дереву до текущего элемента и заполняем стек предков
		while (t != current)
			t = next_infix(t);
	} 
}

template <typename T>
tree<T>::iterator::iterator(const tree *collection, bool reverse_begin) :
    collection(collection)
{
    if (!reverse_begin)
	// Ищем самый первый элемент при инфиксном обходе
        this->current = next_infix(const_cast<node*>(&this->collection->super_root));
}
template<typename T>
inline iterator tree<T>::make_iterator(node * t)
{
	return iterator(this, t);
}
