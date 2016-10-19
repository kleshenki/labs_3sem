#include <iostream>
#include "String.h"

std::list<String*> String::allstr = std::list<String*>();

void String::PrintAll()
{
	std::cout << "Total amount of objects: " << allstr.size() << "\nNow print all objects:\n";
	for (auto it = allstr.begin(); it != allstr.end(); it++)
		it._Ptr->_Myval->Print();
}

String::String()
{
	arr = "0\0";
	create = time(NULL);
	allstr.insert(allstr.end(), this);
}

String::String(int maxlength, char* strarr)
{
	arr = new char[maxlength];
	maxlen = maxlength;
	strcpy_s(arr + 3, maxlength, strarr);
	RecalcLength();
	create = time(NULL);
	allstr.insert(allstr.end(), this);
}

String::String(const String& copy)
{
	maxlen = copy.maxlen;
	arr = new char[maxlen + LEN];
	memcpy(arr, copy.arr, maxlen);
	time(&create);
	allstr.insert(allstr.end(), this);
}

String::~String()
{
}

int String::RealLength()
{
	int len = 0;
	for (int i = 0; i < LEN; i++)
	{
		len *= 10;
		len += (int)(arr[i] - '0');
	}
	return len;
}

int String::MaxLength()
{
	return maxlen;
}

char* String::Substring(char* substring)
{
	return strstr(arr, substring);
}

void String::Print()
{
	std::cout << arr + LEN << "\n";
}

void String::RecalcLength()
{
	int real_len = 0;
	while (arr[real_len] != '\0')
		real_len++;
	real_len -= LEN;
	for (int i = LEN - 1; i >= 0; i--)
	{
		arr[i] = (real_len % 10) + '0';
		real_len /= 10;
	}
}

//Методы перегрузки операций
String String::operator+(char* concat)
{
	size_t size = sizeof(concat);
	char* temp = new char[maxlen];
	strcpy(temp, arr);
	arr = new char[maxlen + size];
	strcpy(arr, temp);
	strcat(arr, concat);
	RecalcLength();
	maxlen += size;
	return *this;
}

String String::operator+(String concat)
{
	int size = concat.maxlen;
	char* temp = new char[maxlen];
	strcpy(temp, arr);
	arr = new char[maxlen + size];
	strcpy(arr, temp);
	strcat(arr, concat.arr+LEN);
	maxlen += size;
	RecalcLength();
	return *this;
}

String String::operator-(char* substring)
{
	return *this;
}

String String::operator()(int index, int len)
{
	return *this;
}

String& String::operator=(String& assignment)
{
	return *this;
}