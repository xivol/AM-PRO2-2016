#pragma once
#include <stack>

template <typename T>
class tree {
	struct node {
		T data;
		node *left, *right;
	};

    node head;
	node *root;

	node *copy_tree(node* root);
	void delete_tree(node *root);
public:
    tree() : root(nullptr) 
    { 
        head.data = 0xcdcdcdcdcdcdcdcd;
        head.left = nullptr;
        head.right = nullptr;
    }
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
        head.right = root;
	}
    void print_tree(const node *root, size_t space)
    {
        if (root == nullptr) return;
        print_tree(root->left, space + 1);
        for (int i = 0; i < space; i++) std::cout << '\t';
        std::cout << root->data << std::endl;
        print_tree(root->right, space + 1);
    }
    void print()
    {
        print_tree(root, 0);
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

        iterator(const tree *collection, node *cur, direction direct = direction::Infix, bool is_end = false) :
			collection(collection), dir(direct) 
        {
            if (is_end)
                current = cur;
            else
			    current = next_top(cur);

		}

		node* next_top(node*cur) 
        {
			switch (dir) {
            case direction::Infix:
                return next_infix(cur);
			}
		}

        node* next_infix(node *cur)
        {
            if (cur == nullptr) return nullptr;
            if (cur->right != nullptr) {
                prev.push(cur);
                cur = cur->right;
                while (cur->left != nullptr) {
                    prev.push(cur);
                    cur = cur->left;
                }
            }
            else {
                node *t = prev.top();
                while (cur == t->right) {
                    cur = t;
                    prev.pop();
                    if (prev.empty()) break;
                    t = prev.top();
                }
                if (cur->right != t && !prev.empty()) {
                    cur = t;
                    prev.pop();
                }
            }
            return cur;
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
		return iterator(this, &head, iterator::direction::Infix);
	}
	iterator end() {
		return iterator(this, & , iterator::direction::Infix, true);
	}
	
};