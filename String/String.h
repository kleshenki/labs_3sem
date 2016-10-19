#pragma once
#include <list>
#include <ctime>

#define LEN 3

class String
{
private:
	char* arr;
	int maxlen;
	time_t create;

public:
	static std::list<String*> allstr;
	static void PrintAll();

	String();
	String(int maxlength, char* strarr);
	String(const String& copy);
	~String();

	int Length();
	char* Substring(char*);
	void Print();
};