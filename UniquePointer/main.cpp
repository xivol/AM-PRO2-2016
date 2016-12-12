#include "crtdynmem.h"
#include "list.h"

int main() {
	setlocale(LC_ALL, "Rus");
	list<int> list;
	for (int i = 0; i < 10; ++i)
		list.push_back(i);
	std::cout << list.size() << std::endl;

	for (auto i : list)
		cout << i << " ";
	cout << endl;

	while (!list.is_empty())
		list.pop_back();

	cout << list.size() << endl;
	_CrtDumpMemoryLeaks();
	return 0;
}