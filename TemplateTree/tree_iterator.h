#pragma once
#include <stack>

template <typename T>
class tree {
	struct node {
		T data;
		node *left, *right;
	};

	node head = { T(), nullptr, nullptr };
	node *root;

	node *copy_tree(node* root);
	void delete_tree(node *root);
	void print_tree(const node *root, size_t space)
    {
        if (root == nullptr) return;
		print_tree(root->right, space + 1);        
        for (int i = 0; i < space; i++) std::cout << '\t';
        std::cout << root->data << std::endl;
		print_tree(root->left, space + 1);
    }	
public:
    tree() : root(nullptr) { }
	tree(const tree & t) {
		copy_tree(t.root);
	}
	tree &operator=(const tree & t) {
		delete_tree();
		copy_tree(t.root);
	}
	//virtual ~tree();

	size_t depth();
	size_t width();


	void push(const T&x) {
		push(x, root);
        head.right = root;
	}

    void print()
    {
        print_tree(root, 0);
    }

	class iterator {	
		std::stack<node *> parents;
		node *current;
		const tree *collection;
        
		iterator(const tree *collection, node *current, bool is_end = false) :
			collection(collection) {
            if (is_end)
                this->current = current;
            else
			    this->current = next_infix(current);
		}

        node* next_infix(node *cur)
        {
            if (cur == nullptr) return nullptr;
            if (cur->right != nullptr) {
                parents.push(cur);
                cur = cur->right;
                while (cur->left != nullptr) {
                    parents.push(cur);
                    cur = cur->left;
                }
            }
            else {
                node *t = parents.top();
                while (cur == t->right) {
                    cur = t;
                    parents.pop();
                    if (parents.empty()) break;
                    t = parents.top();
                }
                if (cur->right != t && !parents.empty()) {
                    cur = t;
                    parents.pop();
                }
            }
            return cur;
        }


		friend class tree;

	public :

		iterator &operator++() {
			current = next_infix(current);
			return *this;
		}

        iterator operator++(int)
        {
            iterator it = current;
            current = next_infix(current);
            return it;
        }

		T operator*() {
			return current->data;
		}

		bool operator== (const iterator & it) {
			return collection == it.collection && current == it.current;
		}

		bool operator!= (const iterator & it) {
			return !(*this == it);
		}
	};

	iterator begin() {
		return iterator(this, &head);
	}
	iterator end() {
		return iterator(this, &head, true);
	}

	friend class tree_maker;	
};