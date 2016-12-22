#pragma once
#include <string>

// Пол
enum class gender { Male, Female, Unrecognised };

// Функтор - предикат сравнения с полом
class is_gender
{
	// Искомый пол
	gender target;

	// Вычисление пола по ФИО
	gender get_gender(std::string name) {
		switch (name[name.length() - 1]) {
		case 'ч':  return gender::Male;
		case 'а':  return gender::Female;
		default:  return gender::Unrecognised;
		}
	}
public:
	is_gender(gender g) : target(g) {}

	// Унарный предикат
	bool operator()(const std::string &name) {
		return get_gender(name) == target;
	}
};

