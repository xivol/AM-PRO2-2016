#pragma once

template <typename T>
class tree {
	struct node {
		T data;
		node *left, *right;
	};

	node *root;

	node *copy_tree(node* root);
	void delete_tree(node *root);
public:
	tree() : root(nullptr) {}
	tree(const tree & t);
	tree &operator=(const tree & t);
	virtual ~tree();

	size_t depth();
	size_t width();

	class iterator {
		node *stack;
		iterator(const tree* collection, node *cur);
	};
};

template <typename T>
class bst : public tree<T> {
	typedef bool (*comparator)(const T &t1, const T &t2);
	comparator is_less, is_equal;
public:
	bst(comparator less = nullptr, comparator equal = nullptr) :
	is_less(less), is_equal(equal) {}
	
	void insert(const T &t);
	T &find(const T &t);
	void remove(const T &t);
	bool contains(const T &t);
};


template <typename Key, typename Value>
struct pair {
	Key key;
	Value value;
};

template <typename Key, typename Value>
class map : public bst<pair<Key, Value>> {
	typedef pair<Key, Value> pair;
	static bool key_less(const pair &p1, const pair &p2) {
		return p1.key < p2.key;
	}
	static bool key_equal(const pair &p1, const pair &p2) {
		return p1.key == p2.key;
	}
public:
	map() :bst(&key_less, &key_equal) {}
};

