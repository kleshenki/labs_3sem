#include <iostream>
#include <conio.h>
#include "String.h"
#include "Interface.h"

using namespace std;
//	ХУЙ
//Демонстрация работы конструкторов, работа 1
void testconstructor()
{
	char* input;
	String *test, *defaultconst, *copy;

	cin.ignore();
	cout << "Enter string: ";
	input = new char[60];
	cin.getline(input, 60);
	test = new String(60, input);
	cout << "Real length: " << test->RealLength() << "\n";
	cout << "Maximal length: " << test->MaxLength() << "\n";
	cout << "Enter substring: ";
	cin.getline(input, 60);
	cout << "Substring by input: " << test->Substring(input) << "\n";
	cout << "Full string: ";
	test->Print();
	
	defaultconst = new String();
	copy = new String(*test);
	cout << "\n\n\nNow print all three strings: \n";
	String::PrintAll();
}

//Функции демонстрации перегруженных операторов
void testpluschar()
{
	char* input;

	cin.ignore();
	cout << "Enter string 1: ";
	input = new char[60];
	cin.getline(input, 60);
	String str = String(60, input);
	cout << "Enter string 2: ";
	cin.getline(input, 60);
	str + input;
	str.Print();
}

void testplusstring()
{
	char* input;

	cin.ignore();
	cout << "Enter string 1: ";
	input = new char[60];
	cin.getline(input, 60);
	String str1 = String(60, input);
	cout << "Enter string 2: ";
	cin.getline(input, 60);
	String str2 = String(60, input);
	str1 + str2;
	str1.Print();
}

void testminus()
{

}

void testbrackets()
{

}

void testassignment()
{

}

int main()
{
	Interface items[] =
	{
		//id    функция             комментарий в консоли
		{ 1,	&testconstructor,	"Test constructor"				},
		{ 2,	&testpluschar,		"Test operator+ with char*"		},
		{ 3,	&testplusstring,	"Test operator+ with String"	},
		{ 4,	&testminus,			"Test operator- with char*"		},
		{ 5,	&testbrackets,		"Test operator() with int,int"	},
		{ 6,	&testassignment,	"Test operator= with String*"	},
	};
	while (true)
	{
		int choice;
		for each (Interface i in items)
			cout << i.id << ". " << i.comment << "\n";
		cout << "Choose menu item: ";
		cin >> choice;
		if (choice < 1 || choice > sizeof(items) / sizeof(Interface))
			return 0;
		items[choice - 1].invoke();
		_getch();
		system("cls");
	}
	_getch();
	return 0;
}