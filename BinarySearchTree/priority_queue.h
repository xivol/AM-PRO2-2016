#pragma once
#include "bst.h"

template <typename Key, typename Value>
struct pair
{
    Key key;
    Value value;
    bool operator==(const pair &p)
    {
        return key == p.key;
    }
    bool operator<(const pair &p)
    {
        return key < p.key;
    }
};

template <typename Priority, typename Value>
class priority_queue : protected bst<pair<Priority, Value>>
{
    typedef pair<Priority, Value> pair;
    typedef bst<pair>::iterator iterator;

    Priority default;
public:
    priority_queue() {}
    priority_queue(const Priority &default): default(default) {}
	
	priority_queue(const priority_queue &q): bst<pair>(q) {}
	priority_queue& operator=(const priority_queue &q);

	void push(const Value &v) { push(v, default); }
    void push(const Value &v, const Priority &p);
    void pop();

	Value top() const;
    bool empty() const;

	priority_queue &operator<<(const Value &v);
	priority_queue &operator>>(Value &v);
	priority_queue operator+(const priority_queue &q);

	template <typename P, typename V>
	friend std::ostream &operator<<(std::ostream &os, const priority_queue<P, V> &q);
	template <typename P, typename V>
	friend std::istream &operator>>(std::istream &is, priority_queue<P, V> &q);
};
