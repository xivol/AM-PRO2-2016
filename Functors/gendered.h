#pragma once
#include <string>
enum class gender{Male, Female, Unrecognised};

class gendered
{
	gender target;
	gender get_gender(std::string name);
public:
	gendered(gender g): target(g) {}
	bool operator(const std::string &name) {
		return get_gender(name) == target;
	}
};

