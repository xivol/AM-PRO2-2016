#include "crtdynmem.h"
#include "dyn_array.h"
#include "list.h"

int main() {
    setlocale(LC_ALL, "Rus");

    cout << "-= Массив =-" << endl;
	try {
        dyn_array<int> array1;
        for (int i = 0; i < 20; ++i)
            array1.append(i);

        for (int i = 0; i < array1.count(); ++i)
            cout << array1[i] << " ";
        cout << endl;
        
        dyn_array<int> array2;
        array2 = array1;

        cout << "Копия:" << endl;
        for (int i = 0; i < array2.count(); ++i)
            cout << array2[i] << " ";
        cout << endl;
    }
    catch (const exception &e) {
        cout << e.what() << endl;
    }
    _CrtDumpMemoryLeaks();

    cout << "-= Список =-" << endl;
    try{
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

		cout << list2.count() << endl;
	}
	catch (const exception &e) {
		cout << e.what() << endl;
	}
	_CrtDumpMemoryLeaks();
	std::system("pause");
	return 0;
}