#pragma once
#include "dyn_array.h"
#include <string>
#include <sstream>


class array_exception : public std::exception {
protected:
	// Ссылка на массив вызвавший ошибку
	const dyn_array *src;
	// Сообщение об ошибке
	std::string msg;
public:
	array_exception(const char *message = "Ошибка массива", const dyn_array* source = nullptr) :
		src(source), msg(message) {}

	const dyn_array *source() const {
		return src;
	}

	const char *what() const {
		return msg.c_str();
	}
};

class size_exception : public array_exception {
protected:
	int error_size;
public:
	size_exception(int size, const dyn_array* source = nullptr) :
		array_exception(source), error_size(size) {
		std::stringstream ss;
		ss << "Некорректный размер массива:" << error_size;
		msg = ss.str();
	}
	size_exception(int size, const char * message, const dyn_array* source = nullptr) :
		array_exception(source, message), error_size(size) { }
	int size() {
		return error_size;
	}
};

class index_exception : public array_exception {
protected:
	int error_index;
public:
	index_exception(int index, const dyn_array* source = nullptr) :
		array_exception(source), error_index(index) {
		std::stringstream ss;
		ss << "" << error_index;
		msg = ss.str();
	}
	
	index_exception(int index, const char * message, const dyn_array* source = nullptr) :
		array_exception(source, message), error_index(index) {}

	int index() {
		return error_index;
	}
};
