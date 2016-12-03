#pragma once
#include "String.h"

template<class T>
class TemplateStack
{
private:
	struct Node { T* data; Node* next; } *top;
public:
	void push(T*);
	T* pop();
	void find(T*);
	void show();
};

#include "TemplateStack.cpp"