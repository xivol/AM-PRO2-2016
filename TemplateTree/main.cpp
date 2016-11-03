#include <iostream>
#include "tree_iterator.h"
#include "tree_maker.h"

int main() {
	tree<int> t = tree_maker::random_tree<int>(10);
	auto it = t.begin();
	while(it!=t.end()){
		std::cout << *it << std::endl;
		++it;
	}
	system("pause");
}