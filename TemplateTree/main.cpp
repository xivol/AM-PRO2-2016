#include <iostream>
#include "tree_iterator.h"

int main() {
	tree<int> t;
	for (int i = 0; i < 10; ++i)
		t.push(i);
    t.print();
	auto it = t.begin();
	while(it!=t.end()){
		std::cout << *it << std::endl;
		++it;
	}
	system("pause");
}