#pragma once
#include <iostream>
#include <memory>
using namespace std;
template <typename Datatype>
class list
{
	
	// Описание узла списка
	struct node
	{
		Datatype data;
		shared_ptr<node> prev, next;
		node(const Datatype& data, shared_ptr<node> &prev, shared_ptr<node> &next);
		node(const Datatype& data = 0);
		~node();
	};
	
	// Начало и конец списка
	shared_ptr<node> first, last;

	// Метод для копирование элементов из другого списка
	void copy_list(const shared_ptr<node> &from_first, const shared_ptr<node> &from_last);

	// Метод удаления списка
	void delete_list();
public:

	list() : first(nullptr), last(nullptr) {}

	list(const list &l)
	{
		copy_list(l.first, l.last);
	}

	list &operator=(const list &l)
	{
		delete_list();
		copy_list(l.first, l.last);
		return *this;
	}
	~list() {
		delete_list();
	}

	// Проверка списка на пустоту
	bool is_empty() const
	{
		return !first && !last;
	}

	// Добавление элемента в конец
	void push_back(const Datatype &x);
	// Добавление элемента в конец
	void pop_back();
	//
	Datatype back();

	// Количество элементов в списке
	size_t size() const;

	// Вывод с указанием числа ссылок
	void print_use_count(ostream &os = cout) const;

	class iterator 
	{
		weak_ptr<node> current;

		const list *collection;

		iterator(shared_ptr<node> &current, const list *collection) :
			current(current), collection(collection)
		{}

		iterator(const list *collection) :
			current(), collection(collection)
		{}
	public:
		Datatype &operator*() {
			return current.lock()->data;
		}

		iterator &operator++() {
			current = current.lock()->next;
			return *this;
		}

		iterator operator++(int) {
			iterator it = *this;
			current = current.lock()->next;
			return it;
		}

		// Сравнение на равенство
		bool operator==(const iterator &it) const
		{
			return current.lock().get() == it.current.lock().get() && collection == it.collection;
		}

		// Сравнение на неравенство
		bool operator!=(const iterator &it) const
		{
			return !(*this == it);
		}
		friend class list;
	};

	iterator begin() {
		return iterator(first, this);
	}

	iterator end() {
		return iterator(this);
	}
};

template<typename Datatype>
inline list<Datatype>::node::node(const Datatype &data, shared_ptr<node> &prev, shared_ptr<node> &next):
	data(data),prev(prev),next(next) 
{}

template<typename Datatype>
inline list<Datatype>::node::node(const Datatype & data):
	data(data), prev(nullptr), next(nullptr)
{}

template<typename Datatype>
inline list<Datatype>::node::~node()
{
	if (next)
		next->prev = nullptr;
}

template<typename Datatype>
void list<Datatype>::copy_list(const shared_ptr<node> &from_first, const shared_ptr<node> &from_last)
{
	if (!is_empty()) throw runtime_error("Попытка копирования в не пустой список");
	shared_ptr<node> &to = first;
	shared_ptr<node> from = from_first;
	while (from) {
		shared_ptr<node> &prev = to;
		to = make_shared<node>(from->data);
		to->prev = prev;
		to = to->next;
		from = from->next;
	}
	to->next = nullptr;
	last = to;
}

template<typename Datatype>
void list<Datatype>::delete_list() 
{	
	while (first) {
		shared_ptr<node> t = first;
		first = first->next;
		t->next = nullptr;
		t->prev = nullptr;
	}
}

template<typename Datatype>
void list<Datatype>::push_back(const Datatype &x)
{
	if (!last) {
		last = make_shared<node>(x);
		last->prev = nullptr;
		first = last;
	}
	else {
		last->next = make_shared<node>(x);
		last->next->prev = last;
		last = last->next;
	}
	last->next = nullptr;
	cout << last.use_count() << endl;
}

template<typename Datatype>
void list<Datatype>::pop_back()
{
	if (!last) return;
	last = last->prev;
	if (last)
		last->next = nullptr;
	else
		first = nullptr;
}

template<typename Datatype>
Datatype list<Datatype>::back()
{
	if (!last) throw out_of_range("Извлечение из пустого списка.");
	return last->data;
}

template<typename Datatype>
size_t list<Datatype>::size() const
{
	size_t sz = 0;
	shared_ptr<node> t = first;
	while (t) {
		sz++;
		t = t->next;
	}
	return sz;
}

template<typename Datatype>
void list<Datatype>::print_use_count(ostream &os = cout) const
{
	shared_ptr<node> t = first;
	while (t) {
		cout << t->data << "\t: " << t.use_count() << endl;
		t = t->next;
	}
}