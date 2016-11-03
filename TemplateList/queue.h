#pragma once

template <typename Datatype>
class abstract_queue {
public:
	virtual ~abstract_queue() = 0 {}
	virtual bool is_empty() const = 0;
	virtual void push(const Datatype &x) = 0;
	virtual void pop() = 0;
	virtual Datatype top() = 0;
};