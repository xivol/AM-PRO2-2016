#pragma once
#include "list.h"

template <typename Datatype>
class queue {
	list<Datatype> data;
public:
	bool is_empty() const
	{
		return data.is_empty();
	}

	void push(const Datatype &x) 
	{
		data.push_back(x);
	}

	Datatype pop() 
	{
		Datatype t = data.front();
		data.pop_front();
		return t;
	}

	Datatype top() const
	{
		return data.front();
	}
};