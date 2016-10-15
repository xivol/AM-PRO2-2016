#pragma once

class list {
public:
	typedef int datatype;
private:
	struct node {
		datatype data;
		node *prev, *next;
	};
	node *front, *back;
public:
	class iterator {
		node *current;
	public:
	};
};