#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>

using namespace std;
int main()
{    
    setlocale(LC_ALL, "Rus");

    ifstream fin("mapset.cpp");
    // Вывести все символы из файла
    set<char> chars;
    char c;
    while (fin >> c)
        chars.insert(c);
    fin.close();
    cout << "Все символ файла" << endl;
    for (char c : chars)
        cout << c << ", ";
    cout << endl;

    // Исключить из множества символов вспомогательные символы
    string delim = " .!?,:;-=+_#()[]{}<>\\\/\'\"";
    set<char> ex(delim.begin(), delim.end());

    set<char> result;
    set_difference(chars.begin(), chars.end(), ex.begin(), ex.end(),
        inserter(result, result.end()));

    cout << "Множество без вспомогательных символов" << endl;
    for (char c : result)
        cout << c << ", ";
    cout << endl;

    // Посчитать количество повторений слов в файле
    map<string, int> words;
    fin.open("input.txt");
    string word;
    while (fin >> word) {
        // Приведём слово к нижнему регистру
        transform(word.begin(), word.end(), word.begin(), tolower);
        // Удалим знаки препинания из конца слова
        if (ex.find(word[word.length()-1]) != ex.end()) {
            word.erase(word.length()-1);
        }
        words[word] += 1;
    }
    fin.close();

    for (pair<string, int> elem : words)
        cout << elem.first << "\t: " << elem.second << endl;

    system("pause");
    return 0;
}