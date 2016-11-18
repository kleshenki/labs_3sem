#pragma once
#include <list>
#include <ctime>
#include <iostream>

#define LEN 3 // выделяем три символа в начале строки для хранения реальной длины строки

using namespace std;

class String
{
protected:
	char* arr;
	int maxlen;
	time_t create; // время создания строки

public:
	static list<String*> allstr; //Лист со всеми объектами класса в памяти
	static void PrintAll(); //Вывод в консоль всех объектов

	String();
	String(int maxlength, char* strarr);
	String(const String& copy);
	~String();

	int RealLength();
	int MaxLength();
	char* Substring(char*); // нахождение подстроки
	virtual void Print();
	void RecalcLength();

	//Перегрузка операций
	String operator+(char* concat);
	String operator+(String concat);
	String operator-(char* substring);
	String operator()(int position, int length);
	String& operator=(String& assignment);

	//Операторы ввода/вывода
	friend ostream& operator<<(ostream& os, String& output);
	friend istream& operator>>(istream& is, String& input);
	friend ofstream& operator<<(ofstream& ofs, String& output);
	friend ifstream& operator>>(ifstream& ifs, String& input);

	void PrintToFile(char* path, bool binary);
	static String GetFromFile(char* path, int length, bool binary);
};