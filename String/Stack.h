#pragma once
#include "String.h"

class Stack
{
private:
	struct Node { String* data; Node* next; } *top;
public:
	void push(String*);
	String* pop();
	void find(String*);
	void show();
};