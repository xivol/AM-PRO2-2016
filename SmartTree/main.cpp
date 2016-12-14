#include "crtdynmem.h"
#include "tree.h"
#include "bst.h"

int main() {
	setlocale(LC_ALL, "Rus");
	try {
		bst<int> tree1;
		for (int i = 0; i < 10; ++i)
			tree1.insert(rand() % 100);
		
		tree1.print();
		cout << endl;

		bst<int> tree2;
		tree2.insert(1);

		cout << "Копия\t:" << endl;
		tree2 = tree1;
		cout << endl;

		
		tree2.print();
		cout << endl;
	}
	catch (const exception &e) {
		cout << e.what() << endl;
	}
	_CrtDumpMemoryLeaks();
	system("pause");
	return 0;
}