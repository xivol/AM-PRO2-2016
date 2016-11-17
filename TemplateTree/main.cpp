#include <iostream>
#include "tree_iterator.h"
#include "test_tree.h"
#include "tree_maker.h"

int main()
{
    test_tree<int>::run();
    tree<int> t = tree_maker::balanced_tree<int>(10);
    t.print();
	int a[5] = { 1,2,3,4,5 };
 //   std::cout << *t.find(0);
 //   auto it1 = t.rbegin();
 //   auto it2 = t.begin();
	//while(it2!=t.end()){
	//	std::cout << *it1 << ' ' << *it2 << ' ';
	//	--it1;
 //       ++it2;
	//}
	for (auto i : t) {
		std::cout << typeid(i).name() << " ";
		std::cout << i << " ";
	}
    std::cout << std::endl << t.depth() << ' ' << t.width() << ' ' << t.size();
	system("pause");
}