#include "vector_functions.h"

using namespace std; 

int main() {
	vector<int> v;
	size_t count = 100;
	vector_capacity(v, count);
	cout << endl;
	v.clear();
	v.reserve(count);
    vector_capacity(v, count);

    vector_file_gen("vector.txt", 50);
   vector<int> max = max_sum_vector("vector.txt");
   cout << max << endl;

	system("pause");
	return 0;
}