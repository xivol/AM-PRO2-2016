#include "vector_functions.h"

using namespace std; 

int main() {
    setlocale(LC_ALL, "Rus");

	vector<int> v;
	size_t count = 100;
	vector_capacity(v, count);
	cout << endl;
	v.clear();
    // Резервируем ёмкость
	v.reserve(count);
    vector_capacity(v, count);

   vector<int> max = max_sum_vector("vector.txt");
   cout << max << endl;

	system("pause");
	return 0;
}