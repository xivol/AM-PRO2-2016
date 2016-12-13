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
		node(const Datatype& data);
	};
	
	// Начало и конец списка,
    // разделяемый указатель
	shared_ptr<node> first, last;

	// Метод для копирование элементов из другого списка
	void copy_list(const shared_ptr<node> &from_first);

	// Метод удаления списка
	void delete_list();
public:

	list() : first(nullptr), last(nullptr) {}

	list(const list &l)
	{
		copy_list(l.first);
	}

	list &operator=(const list &l)
	{
		delete_list();
		copy_list(l.first);
		return *this;
	}

	~list() 
	{
		delete_list();
	}

	// Проверка списка на пустоту
    bool is_empty() const;

	// Добавление элемента в конец списка
	void push_back(const Datatype &x);
	// Удаление элемента из конца списка
	void pop_back();
	// Чтение последнего элемента списка
	Datatype back();

	// Количество элементов в списке
	size_t count() const;

	// Вывод с указанием числа ссылок
	void print_use_count(ostream &os = cout) const;

	class iterator 
	{
        // Слабый указатель на объект - 
        // объект может быть освобождён 
        // при наличии на него слабых указателей
		weak_ptr<node> current;

		const list *collection;

		iterator(shared_ptr<node> &current, const list *collection) :
			current(current), collection(collection)
		{}

		iterator(const list *collection) : collection(collection)
		{}
	public:
		Datatype &operator*() {
            // если элемент не был освобождён
            if (current.expired()) throw runtime_error("Указанный элемент списка не существует.");
            // блокируем целевой элемент
			return current.lock()->data;            
		}

		iterator &operator++() {
            if (current.expired()) throw runtime_error("Указанный элемент списка не существует.");
			current = current.lock()->next;
			return *this;
		}

		iterator operator++(int) {
            if (current.expired()) throw runtime_error("Указанный элемент списка не существует.");
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


    // Вставка значения в список перед итератором
    void insert_before(const iterator &it, const Datatype &x);
    // Вставка значения в список после итератора
    void insert_after(const iterator &it, const Datatype &x);


    // Удаление первого элемента с заданным значением
    void remove(const Datatype &x);
    // Удаление элемента на который указывает итератор
    void remove_at(const iterator &it);

    // Поиск заданного значения в списке
    iterator find(const Datatype &x);
    // Поиск значения, начиная с заданной позиции
    iterator find_next(const Datatype &x, const iterator &start);

    // Проверка на существование значения в списке
    bool contains(const Datatype &x);
};

template<typename Datatype>
inline list<Datatype>::node::node(const Datatype & data):
	data(data), prev(nullptr), next(nullptr)
{}

template<typename Datatype>
void list<Datatype>::copy_list(const shared_ptr<node> &from_first)
{
	if (!is_empty()) throw runtime_error("Попытка копирования в не пустой список.");
	if (!from_first) return;		

	first = make_shared<node>(from_first->data);

	shared_ptr<node> prev = first;
	shared_ptr<node> from = from_first->next;
	shared_ptr<node> to = first;

	while (from) {
		to->next = make_shared<node>(from->data);		
		if (!first)
			first = to;
		to = to->next;
		to->prev = prev;
		prev = to;
		from = from->next;
	}
	last = prev;
}

template<typename Datatype>
void list<Datatype>::delete_list() 
{	
	while (first) {
		shared_ptr<node> t = first;
		first = first->next;
        // Удаляем все ссылки текущего элемента
		t->next = nullptr;
		t->prev = nullptr;
	}
    // first == nullptr
	last = nullptr;
}

template<typename Datatype>
bool list<Datatype>::is_empty() const
{
    // Умные указатели могут быть 
    // неявно преобразованы к логическому типу
    return !first && !last;
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
size_t list<Datatype>::count() const
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
	size_t i = 0;
	while (t) {
		cout << i++ << ": " << t->data << 
			" ссылок: " << t.use_count() << endl;
		t = t->next;
	}
}