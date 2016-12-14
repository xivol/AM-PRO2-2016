#include "crtdynmem.h"
#include "list.h"
#include "tree.h"

int main() {
    setlocale(LC_ALL, "Rus");
	try {
		tree<int> tree1;
		for (int i = 0; i < 10; ++i)
			tree1.push(rand() % 100);
		tree1.print();

		tree<int> tree2;
		tree2.push(1);
		tree2 = tree1;

		tree2.print();
	}
	catch (const exception &e) {
		cout << e.what() << endl;
	}
	_CrtDumpMemoryLeaks();
	try {
		list<int> list1;
		for (int i = 0; i < 10; ++i)
			list1.push_back(i);

		list1.print_use_count();
		
		list<int> list2;
		list2 = list1;

		cout << "Копия:" << endl;
		for (auto i : list2)
			cout << i << " ";
		cout << endl;

		while (!list2.is_empty()) {
			cout << list2.back() << " ";
			list2.pop_back();
		}
		cout << endl;

		cout << list2.size() << endl;
	}
	catch (const exception &e) {
		cout << e.what() << endl;
	}
	_CrtDumpMemoryLeaks();
	std::system("pause");
	return 0;
}