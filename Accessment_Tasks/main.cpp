#include"pass.h"
#include"point.h"
#include"rad_point.h"
#include"room.h"

using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	date d;
	cin >> d.day >> d.month >> d.year;
	pass p(101,d);

	room r(1, 123.45);

	rad_point pp(1.5, 23.5);

	point ppp(1, 2);

	p.print();
	r.print();
	pp.print();
	ppp.print();
	system("pause");
	return 0;
}