#include <iostream>
#include "tree_iterator.h"

int main() {
	tree<int> t;
	for (int i = 0; i < 10; ++i)
		t.push(i);
	auto it = t.begin();
	for (int i=0; i<10; i++){
		std::cout << *it << std::endl;
		++it;
	}
	system("pause");
}