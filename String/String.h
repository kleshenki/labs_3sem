#pragma once
#include <list>
#include <ctime>
#include <iostream>

#define LEN 3 // выделяем три символа в начале строки для хранения реальной длины строки

using namespace std;

class String
{
private:
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
	void Print();
	void RecalcLength();

	//Перегрузка операций
	String operator+(char*);
	String operator+(String);
	String operator-(char*);
	String operator()(int, int);
	String& operator=(String&);

	//Операторы ввода/вывода
	friend ostream& operator<<(ostream&, String&);
	friend istream& operator>>(istream&, String&);
	friend ofstream& operator<<(ofstream&, String&);
	friend ifstream& operator>>(ifstream&, String&);
};