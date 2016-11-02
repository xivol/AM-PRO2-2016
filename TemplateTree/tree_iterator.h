#pragma once
#include <stack>

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
	//virtual ~tree();

	size_t depth();
	size_t width();

	void push(const T&x, node*& root) {
		if (root == nullptr) {
			root = new node;
			root->data = x;
			root->left = nullptr;
			root->right = nullptr;
		}
		else {
			if (rand() % 2 == 0)  // вставляем элемент в случайное поддерево
				push(x, root->left);
			else
				push(x, root->right);
		}
	}
	void push(const T&x) {
		push(x, root);
	}

	class iterator {
	public:
		enum class direction { Prefix = 0, Infix, Suffix };
	private:
		std::stack<node *> prev;
		node *current;
		const tree *collection;
		bool full_circle;

		direction dir;

		iterator(const tree *collection, node *cur, direction direct = direction::Infix) :
			collection(collection), dir(direct) {
			full_circle = false;
			current = next_top(cur);
		}

		node* next_top(node*cur) {
			switch (dir) {
			case direction::Suffix:
				return next_postfix(cur);
			}
		}

		node *leftmost(node *cur) {
			if (cur == nullptr) return nullptr;
			while (cur -> left != nullptr) {
				prev.push(cur);
				cur = cur->left;
			}
			return cur;

		}

		node* next_postfix(node * cur) {
			if (cur == nullptr)
				if (!prev.empty())
				{
					node* t = prev.top();
					prev.pop();
					return t;
				}
				else
					return nullptr;
			// cur != nullptr
			if (!prev.empty()) {				
				if (prev.top()->right == cur) {
					node *t = prev.top();
					prev.pop();
					return t;
				}
				if (prev.top()->left == cur) {
					return leftmost(cur);
				}
			}
			if (full_circle) return nullptr;
			full_circle = true;
			return leftmost(cur);
		}

		friend class tree;

	public :

		iterator &operator++() {
			current = next_top(current);
			return *this;
		}
		T operator*() {
			return current->data;
		}
		bool operator!= (const iterator & it) {
			return collection == it.collection &&
				current != it.current;
		}
	};

	iterator begin() {
		return iterator(this, root, iterator::direction::Suffix);
	}
	iterator end() {
		return iterator(this, nullptr, iterator::direction::Suffix);
	}
	
};