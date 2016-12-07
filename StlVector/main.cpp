#include <iostream>
#include <vector>
#include "vector_functions.h"

using namespace std; 

int main() {
	vector<int> v;
	size_t count = 1000;
	fill_vector(v, count);
	cout << endl;
	v.clear();
	v.reserve(count);
	fill_vector(v, count);
	system("pause");
	return 0;
}