#include <iostream>
#include <vector>
#include "vector_functions.h"

using namespace std;

void fill_vector(vector<int>& v, size_t count) {

	size_t cap = v.capacity();
	cout << "\tStart" << endl;
	cout << "Capacity: " << cap << "\tSize: " << v.size() << endl;

	for (int i = 0; i < count; ++i) {
		v.push_back(rand());

		if (cap != v.capacity()) {
			cap = v.capacity();
			cout << "Capacity: " << cap << "\tSize: " << v.size() << endl;
		}
	}

	cout << "\tFinal" << endl;
	cout << "Capacity: " << cap << "\tSize: " << v.size() << endl;

	v.shrink_to_fit();
	if (cap != v.capacity()) {
		cap = v.capacity();
		cout << "\tShrunk to fit!" << endl;
		cout << "Capacity: " << cap << "\tSize: " << v.size() << endl;
	}
}