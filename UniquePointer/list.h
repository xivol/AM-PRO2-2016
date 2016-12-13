#pragma once
#include <iostream>
#include <memory>
using namespace std;
template <typename Datatype>
class list
{
	// �������� ���� ������
	struct node
	{
		Datatype data;
		shared_ptr<node> prev, next;
		node(const Datatype& data);
	};
	
	// ������ � ����� ������,
    // ����������� ���������
	shared_ptr<node> first, last;

	// ����� ��� ����������� ��������� �� ������� ������
	void copy_list(const shared_ptr<node> &from_first);

	// ����� �������� ������
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

	// �������� ������ �� �������
    bool is_empty() const;

	// ���������� �������� � ����� ������
	void push_back(const Datatype &x);
	// �������� �������� �� ����� ������
	void pop_back();
	// ������ ���������� �������� ������
	Datatype back();

	// ���������� ��������� � ������
	size_t count() const;

	// ����� � ��������� ����� ������
	void print_use_count(ostream &os = cout) const;

	class iterator 
	{
        // ������ ��������� �� ������ - 
        // ������ ����� ���� ��������� 
        // ��� ������� �� ���� ������ ����������
		weak_ptr<node> current;

		const list *collection;

		iterator(shared_ptr<node> &current, const list *collection) :
			current(current), collection(collection)
		{}

		iterator(const list *collection) : collection(collection)
		{}
	public:
		Datatype &operator*() {
            // ���� ������� �� ��� ���������
            if (current.expired()) throw runtime_error("��������� ������� ������ �� ����������.");
            // ��������� ������� �������
			return current.lock()->data;            
		}

		iterator &operator++() {
            if (current.expired()) throw runtime_error("��������� ������� ������ �� ����������.");
			current = current.lock()->next;
			return *this;
		}

		iterator operator++(int) {
            if (current.expired()) throw runtime_error("��������� ������� ������ �� ����������.");
			iterator it = *this;
			current = current.lock()->next;
			return it;
		}

		// ��������� �� ���������
		bool operator==(const iterator &it) const
		{
			return current.lock().get() == it.current.lock().get() && collection == it.collection;
		}

		// ��������� �� �����������
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


    // ������� �������� � ������ ����� ����������
    void insert_before(const iterator &it, const Datatype &x);
    // ������� �������� � ������ ����� ���������
    void insert_after(const iterator &it, const Datatype &x);


    // �������� ������� �������� � �������� ���������
    void remove(const Datatype &x);
    // �������� �������� �� ������� ��������� ��������
    void remove_at(const iterator &it);

    // ����� ��������� �������� � ������
    iterator find(const Datatype &x);
    // ����� ��������, ������� � �������� �������
    iterator find_next(const Datatype &x, const iterator &start);

    // �������� �� ������������� �������� � ������
    bool contains(const Datatype &x);
};

template<typename Datatype>
inline list<Datatype>::node::node(const Datatype & data):
	data(data), prev(nullptr), next(nullptr)
{}

template<typename Datatype>
void list<Datatype>::copy_list(const shared_ptr<node> &from_first)
{
	if (!is_empty()) throw runtime_error("������� ����������� � �� ������ ������.");
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
        // ������� ��� ������ �������� ��������
		t->next = nullptr;
		t->prev = nullptr;
	}
    // first == nullptr
	last = nullptr;
}

template<typename Datatype>
bool list<Datatype>::is_empty() const
{
    // ����� ��������� ����� ���� 
    // ������ ������������� � ����������� ����
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
	if (!last) throw out_of_range("���������� �� ������� ������.");
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
			" ������: " << t.use_count() << endl;
		t = t->next;
	}
}