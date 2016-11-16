#include "bst.h"
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    bst<int> tree;
    int n = 10;
    srand(clock());
    for (int i = 0; i < n; ++i) {
        tree.insert(rand()%100);
    }
    
    for (auto i = tree.begin(); i != tree.end(); ++i)
        cout << *i << " ";
    cout << endl;
    int k;
    cin >> k;
    tree.find_insert(k);
    tree.print();
    cin >> k;
    tree.remove(k);
    tree.print();
    for (auto i = tree.begin(); i != tree.end(); ++i)
        cout << *i << " ";
    cout << endl;
	bst<int> t2;
	t2 = tree;
	for (auto i = t2.begin(); i != t2.end(); ++i)
		cout << *i << " ";
	cout << endl;
    system("pause");
    return 0;
}
