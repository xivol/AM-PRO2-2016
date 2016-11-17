#include <array>
#include <iostream>
#include <vector>

using namespace std;

template < typename Iterator>
auto min_value(const Iterator &begin, const Iterator& end)
{
	auto min = *begin;
	cout << typeid(begin).name() << endl;
	for (Iterator i = begin + 1; i != end; ++i)
		if (min > *i) min = *i;
	return min;
}

template <typename T>
auto min(const T&t)
{
	return min_value(t.begin(), t.end());
}

int main() {
	const int n = 10;

	int arr[n] = { 0, 1, 2, 3, 4, 5, -1, 7, 8, 9 };
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << endl;
	cout << min_value(begin(arr), end(arr)) << endl;
	
	array<int, n> a = { 0, 1, 2, 3, 4, 5, -1, 7, 8, 9 };
	for(auto i = a.begin(); i!=a.end(); ++i)
		cout << *i << " ";
	cout << endl;
	cout << min(a) << endl;

	vector<int> v = { 0, 1, 2, 3, 4, 5, -1, 7, 8, 9 };
	for (auto i = v.begin(); i != v.end(); ++i)
		cout << *i << " ";
	cout << endl;
	cout << min(v) << endl;
	system("pause");
	return 0;
}