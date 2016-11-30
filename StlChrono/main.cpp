#include <chrono>
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include "chrono_show.h"

using namespace std;
using namespace std::chrono;

int main()
{   
    const size_t size = 10000;
    array<int, size> a;
    vector<int> v(size);
    deque<int> d(size);
    list<int> l;

    for (size_t i = 0; i < size; ++i) {
        d[i] = v[i] = a[i] = rand();
        l.push_back(d[i]);        
    }

    auto start = steady_clock::now();
    std::sort(a.begin(), a.end());
    auto end = steady_clock::now();

    cout << "array\t" << size << "\tsort:\t" << 
        duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    start = steady_clock::now();
    std::sort(v.begin(), v.end());
    end = steady_clock::now();

    cout << "vector\t" << size << "\tsort:\t" << 
        duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    start = steady_clock::now();
    std::sort(d.begin(), d.end());
    end = steady_clock::now();

    cout << "deque\t" << size << "\tsort:\t" <<
        duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    start = steady_clock::now();
    l.sort();
    end = steady_clock::now();

    cout << "list\t"<<size<<"\tsort:\t" << 
        duration_cast<milliseconds>(end - start).count() << " ms" << endl;

    v.clear();
    cout << "vector\t" << size << "\tfront inserts:\t" <<
        front_insert_time<milliseconds>(v, size) << "ms" << endl;

    l.clear();
    cout << "list\t" << size << "\tfront inserts:\t" <<
        front_insert_time<milliseconds>(l, size) << "ms" << endl;

    d.clear();
    cout << "deque\t" << size << "\tfront inserts:\t" <<
        front_insert_time<milliseconds>(d, size) << "ms" << endl;
 
    cout << "vector\t" << size << "\tfront erases:\t" <<
        front_erase_time<milliseconds>(v, size) << "ms" << endl;
    cout << "list\t" << size << "\tfront erases:\t" <<
        front_erase_time<milliseconds>(l, size) << "ms" << endl;
    cout << "deque\t" << size << "\tfront erases:\t" <<
        front_erase_time<milliseconds>(d, size) << "ms" << endl;
    v.shrink_to_fit();
    d.shrink_to_fit();    
    cout << "vector\t" << size << "\tback inserts:\t" <<
        back_insert_time<milliseconds>(v, size) << "ms" << endl;
    cout << "list\t" << size << "\tback inserts:\t" <<
        back_insert_time<milliseconds>(l, size) << "ms" << endl;
    cout << "deque\t" << size << "\tback inserts:\t" <<
        back_insert_time<milliseconds>(d, size) << "ms" << endl;

    cout << "vector\t" << size << "\tsubscripts:\t" <<
       subscript_time<milliseconds>(v) << "ms" << endl;
    cout << "list\t" << size << "\tsubscripts:\t" <<
        subscript_time<milliseconds>(l) << "ms" << endl;
    cout << "deque\t" << size << "\tsubscripts:\t" <<
        subscript_time<milliseconds>(d) << "ms" << endl;

    cout << "vector\t" << size << "\tfront erases:\t" <<
        back_erase_time<milliseconds>(v, size) << "ms" << endl;
    cout << "list\t" << size << "\tfront erases:\t" <<
        back_erase_time<milliseconds>(l, size) << "ms" << endl;
    cout << "deque\t" << size << "\tfront erases:\t" <<
        back_erase_time<milliseconds>(d, size) << "ms" << endl;

    system("pause");
}