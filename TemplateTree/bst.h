#pragma once
#include "tree_iterator.h"

template <typename T>
class bst : public tree<T>
{
protected:
	node *insert_tree(node *&root, const T &x);
	node *&find_tree(node *&root, const T &x);
	void remove_tree(node *root, const T &x);
	node *leftmost_right(node *root);
public:
    iterator insert(const T &t);
    iterator find(const T &t);
	iterator find_insert(const T &t);
    void remove(const T &t);
    bool contains(const T &t);
};


template <typename Key, typename Value>
struct pair
{
    Key key;
    Value value;
};

template <typename Key, typename Value>
class priority_queue : public bst<pair<Key, Value>>
{
	Key default_priority = { 0 }
public:
	priority_queue() {}
	priority_queue(const Key &default);
	void push(const Value &x) {
		push(x, default_priority);
	}
	void push(const Value &x, const Key &priority);
	Value pop();
	Value top();
	bool is_empty() {
		return tree<pair<Key, Value>>::size() == 0;
	}
};

template <typename Key, typename Value>
bool operator==(const pair<Key, Value> &p1, const pair<Key, Value> &p2) {
	return p1.key == p2.key;
}

template <typename Key, typename Value>
bool operator!=(const pair<Key, Value> &p1, const pair<Key, Value> &p2) {
	return p1.key != p2.key;
}