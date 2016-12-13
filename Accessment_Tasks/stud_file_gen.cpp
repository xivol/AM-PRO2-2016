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

uint16_t random_year(uint16_t min_year, uint16_t max_year = 2016) {
	if (min_year == max_year)
		return min_year;
	return rand() % (max_year - min_year) + min_year;
}

tuple<uint16_t, uint16_t, uint16_t> random_date(uint16_t min_year, uint16_t max_year = 2016) {
	tuple<uint16_t, uint16_t, uint16_t> date;
	get<1>(date) = rand() % 12 + 1;
	switch (get<1>(date)) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		get<0>(date) = rand() % 31+1;
		break;
	case 2:
		get<0>(date) = rand() % 28+1;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		get<0>(date) = rand() % 30+1;
		break;
	}
	if (min_year == max_year)
		get<2>(date) = min_year;
	else
		get<2>(date) = rand() % (max_year - min_year) + min_year;
	return date;
}

string random_name(map<gender, set<string>[3]>& names) {
	stringstream ss;
	gender g = gender(rand() % 2);
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
		uint16_t course = rand() % courses + 1;
		uint16_t group = rand() % groups + 1;
		fout << random_name(names) <<"\t"<< random_year(2016 - (course - 1 + rand() % 3), 2015) << "\t" << course << "\t" << group << endl;
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

	map<int,vector<string>> students;
	fin.open("students.txt");
	while (!fin.eof()) {	
		string stud;
		getline(fin, stud);
		istringstream ss(stud);	
		string name;
		int year, course, group;
		getline(ss, name, '\t');
		ss >> year >> course >> group;
		students[course * 10 + group].push_back(name);
	}
	fin.close();

	map<int, vector<string>> exams;
	fin.open("exams.txt");
	while (!fin.eof()) {
		string name;
		getline(fin, name);
		istringstream ss(name);
		int course, group;
		getline(ss, name, '\t');
		ss >> course >> group;		
		ss.clear();
		exams[course * 10 + group].push_back(name);
	}
	fin.close();
	
	int n_exams = 0;
	for_each(exams.begin(), exams.end(), [&](const auto &v) { n_exams += v.second.size(); });

	vector<string> examinators(rand() % n_exams);
	for (string &name : examinators)
		name = random_name(names);

	vector<tuple<uint16_t, uint16_t, uint16_t>> exam_dates(rand() % n_exams);
		for (auto &date : exam_dates)
			date = random_date(2015);

	ofstream fout("session.txt");
	for (auto i = exams.begin(); i != exams.end(); ++i) {
		int course = i->first / 10;
		int group = i->first % 10;

		for (const string &exam : i->second) {
			auto &examinator = examinators[rand() % examinators.size()];
			auto date = exam_dates[rand() % exam_dates.size()];
			for (const string &student : students[i->first]) {
				fout << exam << "\t" << examinator<< "\t" <<
					get<0>(date) << "." << get<1>(date) << "." << get<2>(date) << "\t" <<
					student << "\t" << rand() % 101 << endl;
			}
		}
	}
	fout.close();

	system("pause");
	return 0;
}