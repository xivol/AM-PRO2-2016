//
// Лабораторная работа №21. Абстрактные типы данных. Очередь с приоритетом
// priority_queue.h
//
#pragma once
#include "bst.h"

// Шаблон элемента для очереди с приоритетом
template <typename Key, typename Value>
struct qpair
{
	Key key;
	Value value;

	// Конструкторы
	qpair() {}
	qpair(const Key&k, const Value &v) : key(k), value(v) {}

	// Сравнение на равенство
	bool operator==(const qpair &p) const
	{
		// равны если совпадают и ключ и значение
		return key == p.key && value == p.value;
	}
	// Сранение на неравенство
	bool operator<(const qpair &p) const
	{
		// сравнение по ключу
		return key < p.key;
	}
};

// Шаблон очереди с приоритетом
template <typename Priority, typename Value>
class priority_queue : protected bst<qpair<Priority, Value>>
{
	/* Мы используем завкырое наследование, 
	   т.к. очередь не является деревом, 
	   а лишь использует его для хранения элементов.
	   
	   При этом, мы не можем использовать дерево 
	   как член класса, т.к. нам нужен доступ 
	   к его закрытым методам для эффективной работы с ним.
	   
	   Не превильная архитектура класса bst! 
	   Класс должен позволять выполнять операции эффективно 
	   без доступа к закрытым полям и методам.
	*/
protected:
	// короткое имя пары
	typedef qpair<Priority, Value> qpair;

	// Приоритет по умолчанию
	Priority default;
public:
	// Конструторы
	priority_queue() {}
	priority_queue(const Priority &default) : default(default) {}

	// Копирование
	priority_queue(const priority_queue &q) : bst<qpair>(q) {}
	priority_queue& operator=(const priority_queue &q)
	{
		bst<qpair>::operator=(q);
		return *this;
	}

	// Добавление в очередь
	void push(const Value &v) { push(v, default); }
	void push(const Value &v, const Priority &p);
	
	// Извлечение из очереди
	void pop();
	
	// Просмотр первого элемента
	Value top() const;

	// Проверка очереди на пустоту
	bool empty() const;

	// Операция добавления элемента в очередь
	priority_queue &operator<<(const Value &v);
	// Операция извлечения элемента из очереди
	priority_queue &operator>>(Value &v);

	// Слияние двух очередей - новая очередь
	priority_queue operator+(const priority_queue &q) const;

	// Дружественная операция вывода
	template <typename P, typename V>
	friend std::ostream &operator<<(std::ostream &os, const priority_queue<P, V> &q);
	// Тестирующий класс
	template <typename P, typename V>
	friend class test_priority_queue<P, V>;
};

// Операция ввода элементов в очередь
template<typename P, typename V>
std::istream &operator>>(std::istream & is, priority_queue<P, V>& q);

template<typename P, typename V>
inline std::ostream & operator<<(std::ostream & os, const priority_queue<P, V>& q)
{
	for (bst<qpair<P, V>>::iterator i = q.begin(); i != q.end(); ++i)
		os << "{" << i->key << " " << i->value << "} ";
	return os;
}