#include "crtdynmem.h"
#include "list.h"

int main() {
    setlocale(LC_ALL, "Rus");
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