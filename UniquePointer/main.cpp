#include "dyn_array.h"

int main() {
	setlocale(LC_ALL, "Rus");
	dyn_array<int> a(10);
	for (int i = 0; i < a.size(); ++i)
		a[i] = i;
	std::cout << std::endl;

	a.append(500);
	std::cout << std::endl;

	for (int i = 0; i < a.size(); ++i)
		std::cout << a[i] << " ";
	std::cout << std::endl;

	dyn_array<int> b(a);
	std::cout << std::endl;

	dyn_array<int> c;
	c = a;
	std::cout << std::endl;
	return 0;
}