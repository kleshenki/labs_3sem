#ifndef TEMPLATE_STACK
#define TEMPLATE_STACK
#include "TemplateStack.h"

template<class T>
void TemplateStack<T>::push(T* element)
{
	Node* newelem = new Node();
	newelem->data = element;
	newelem->next = top;
	top = newelem;
}

template<class T>
T* TemplateStack<T>::pop()
{
	T* ret = top->data;
	top = top->next;
	return ret;
}

template<class T>
void TemplateStack<T>::find(T* element)
{
	Node* e = top;
	do
	{
		if (e->data == element)
		{
			cout << element;
			break;
		}
		e = e->next;
	} while (e != NULL);
}

template<class T>
void TemplateStack<T>::show()
{
	Node* e = top;
	do
	{
		cout << *(e->data) << "\n";
		e = e->next;
	} while (e != NULL);
}
#endif