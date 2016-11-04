#include <iostream>
#include "tree_iterator.h"
#include "tree_maker.h"

int main() {
	tree<int> t = tree_maker::balanced_tree<int>(10);
    t.print();    
	auto it = t.begin();
	while(it!=t.end()){
		std::cout << *it << ' ';
		++it;
	}
    std::cout << std::endl << t.depth() <<' ' << t.width();
	system("pause");
}