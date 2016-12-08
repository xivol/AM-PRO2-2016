#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;
enum class gender{ Male, Female, Unknown};
gender get_gender(const string &name) {
	string ending = name.substr(name.length() - 2);
	if (ending == "ич")
		return gender::Male;
	if (ending == "на")
		return gender::Female;
	return gender::Unknown;
}

uint16_t random_year(uint16_t min_year, uint16_t max_year = 2015) {
	if (min_year == max_year)
		return min_year;
	return rand() % (max_year - min_year) + min_year;
}

string random_name(map<gender, set<string>[3]>& names) {
	stringstream ss;
	gender g = gender(rand() % 3);
	auto g_names = names[g];
	auto name = g_names[0].begin();
	advance(name, rand() % g_names[0].size());
	ss << *name << " ";
	name = g_names[1].begin();
	advance(name, rand() % g_names[1].size());
	ss << *name << " ";
	name = g_names[2].begin();
	advance(name, rand() % g_names[2].size());
	ss << *name;
	return ss.str();
}

void generate_file(char *output, map<gender, set<string>[3]>& names,
	size_t count, uint16_t courses = 4, uint16_t groups = 8) {
	ofstream fout(output);
	if (!fout.is_open()) return;
	while (count > 0) {		
		uint16_t course = rand() % courses;
		uint16_t group = rand() % groups;
		fout << random_name(names) <<"\t"<< random_year(2016 - (course + rand() % 3)) << "\t" << course << "\t" << group << endl;
		count -= 1;
	}
}

int main() {
	setlocale(LC_ALL, "Rus");
	map<gender, set<string>[3]> names;		
	ifstream fin("snames.txt");
	if (!fin.is_open()) return -1;

	while (!fin.eof()) {
		string stud_name = "";
		getline(fin, stud_name, ';');
		if (stud_name.length() == 0)
			break;
		
		gender g = get_gender(stud_name);
		auto t =names[g];
		size_t space = stud_name.find(" ");		
		names[g][0].insert( stud_name.substr(0, space));
		size_t space2 = stud_name.find(" ", space + 1);
		names[g][1].insert(stud_name.substr(space + 1, space2 - space - 1));
		names[g][2].insert(stud_name.substr(space2 + 1));
	}
	fin.close();
	generate_file("students.txt", names, 1000, 4, 8);
	system("pause");
	return 0;
}