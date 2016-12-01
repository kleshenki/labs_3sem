#include "Stack.h"

void Stack::push(String* element)
{
	Node* newelem = new Node();
	newelem->data = element;
	newelem->next = top;
	top = newelem;
}

String* Stack::pop()
{
	String* ret = top->data;
	top = top->next;
	return ret;
}

void Stack::find(String* element)
{
	Node* e = top;
	do
	{
		if (e->data == element)
		{
			element->Print();
			break;
		}
		e = e->next;
	} while (e != NULL);
}

void Stack::show()
{
	Node* e = top;
	do
	{
		e->data->Print();
		e = e->next;
	} while (e != NULL);
}