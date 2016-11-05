#include <iostream>
#include "tree_iterator.h"
#include "tree_maker.h"

int main()
{
    tree<int> t = tree_maker::balanced_tree<int>(10);
    t.print();
    auto it1 = t.rbegin();
    auto it2 = t.begin();
	while(it2!=t.end()){
		std::cout << *it1 << ' ' << *it2 << ' ';
		--it1;
        ++it2;
	}
    std::cout << std::endl << t.depth() << ' ' << t.width() << ' ' << t.size();
	system("pause");
}