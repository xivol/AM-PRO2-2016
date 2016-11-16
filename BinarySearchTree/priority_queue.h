#pragma once
#include "bst.h"

template <typename Key, typename Value>
struct qpair
{
	Key key;
	Value value;
	
	qpair() {}
	qpair(const Key&k, const Value &v) : key(k), value(v) {}

	bool operator==(const qpair &p) const
	{
		return key == p.key && value == p.value;
	}
	bool operator<(const qpair &p) const
	{
		return key < p.key;
	}
};

template <typename Priority, typename Value>
class priority_queue : protected bst<qpair<Priority, Value>>
{
	typedef qpair<Priority, Value> qpair;
	typedef bst<qpair>::iterator iterator;

	Priority default;
public:
	priority_queue() {}
	priority_queue(const Priority &default) : default(default) {}

	priority_queue(const priority_queue &q) : bst<qpair>(q) {}
	priority_queue& operator=(const priority_queue &q) 
	{
		bst<qpair>::operator=(q);
		return *this;
	}

	void push(const Value &v) { push(v, default); }
	void push(const Value &v, const Priority &p)
	{
		insert(qpair(p, v));
	}
	void pop()
	{ 
		remove(max());
	}

	Value top() const 
	{
		bst<qpair>::node * t = bst<qpair>::rightmost(tree<qpair>::root);
		if (t == nullptr) throw std::out_of_range("");
		return t->data.value;
	}

	bool empty() const 
	{
		return root == nullptr;
	}

	priority_queue &operator<<(const Value &v)
	{
		push(v);
		return *this;
	}
	priority_queue &operator>>(Value &v) 
	{
		v = top();
		pop();
		return *this;
	}
	priority_queue operator+(const priority_queue &q) const{
		priority_queue sum(q);
		for (iterator i = begin(); i != end(); ++i)
			sum.find_insert(*i);
		return sum;
	}

	template <typename P, typename V>
	friend std::ostream &operator<<(std::ostream &os, const priority_queue<P, V> &q);
};

template<typename P, typename V>
inline std::ostream & operator<<(std::ostream & os, const priority_queue<P, V>& q)
{
	for (bst<qpair<P, V>>::iterator i = q.begin(); i != q.end(); ++i)
		os << "{"<<i->key << " " << i->value << "} ";
	return os;
}

template<typename P, typename V>
inline std::istream & operator >> (std::istream & is, priority_queue<P, V>& q)
{
	while (is.good() && !is.eof()) {
		V v;
		is >> v;
		q << v;
	}
	return is;
}
