#pragma once
#include <string>

// ���
enum class gender { Male, Female, Unrecognised };

// ������� - �������� ��������� � �����
class is_gender
{
	// ������� ���
	gender target;

	// ���������� ���� �� ���
	gender get_gender(std::string name) {
		switch (name[name.length() - 1]) {
		case '�':  return gender::Male;
		case '�':  return gender::Female;
		default:  return gender::Unrecognised;
		}
	}
public:
	is_gender(gender g) : target(g) {}

	// ������� ��������
	bool operator()(const std::string &name) {
		return get_gender(name) == target;
	}
};

