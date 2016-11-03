#pragma once
#include "list.h"

template <typename Datatype>
class abstract_queue {
	virtual ~abstract_queue() = 0 {}
	virtual bool is_empty() const = 0;
	virtual void push(const Datatype &x) = 0;
	virtual void pop() = 0;
	virtual Datatype top() = 0;
};

template <typename Datatype>
class queue : public abstract_queue<Datatype>{
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