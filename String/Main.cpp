#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "String.h"
#include "BinNumber.h"
#include "Interface.h"

using namespace std;

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
	char* input;

	cin.ignore();
	cout << "Enter string 1: ";
	input = new char[60];
	cin.getline(input, 60);
	String str = String(60, input);
	cout << "Enter string 2: ";
	cin.getline(input, 60);
	cout << "Result: ";
	str - input;
	str.Print();
}

void testbrackets()
{
	char *temp = new char[256];
	cout << "Enter string: ";
	cin.ignore();
	cin.getline(temp, 256);
	String str(256, temp);
	cout << "Substring (2, 2) = ";
	String result = str(2, 2);
	result.Print();
}

void testassignment()
{
	char*s = new char[256];
	cout << "Enter first string: ";
	cin.ignore();
	cin.getline(s, 256);
	String str(256, s);
	cout << "Enter second string: ";
	cin.getline(s, 256);
	str = String(256, s);
	cout << "First now is: ";
	str.Print();
}

void testconsolestream()
{
	cin.ignore();
	String str(80, "");
	cout << "Enter string: ";
	cin >> str;
	cout << "The string is: " << str;
}

void testtextfile()
{
	cin.ignore();
	String str(80, "");
	cout << "Enter string: ";
	cin >> str;
	str.PrintToFile(".\\test.txt", false);
	String fromfile;
	fromfile = String::GetFromFile(".\\test.txt", str.MaxLength(), false);
	cout << "The file now contains: " << fromfile;
}

void testbinaryfile()
{
	cin.ignore();
	String str(80, "");
	cout << "Enter string: ";
	cin >> str;
	str.PrintToFile(".\\test.bin", true);
	String fromfile;
	fromfile = String::GetFromFile(".\\test.bin", str.MaxLength(), true);
	cout << "The file now contains: " << fromfile;
}

void testbinnumberclass()
{
	String* bn = new BinNumber(5, "0101");
	bn->Print();
}

int main()
{
	HANDLE hConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	Interface items[] =
	{
		//id    функция					комментарий в консоли
		{ 1,	&testconstructor,		"Test constructor"				},
		{ 2,	&testpluschar,			"Test operator+ with char*"		},
		{ 3,	&testplusstring,		"Test operator+ with String"	},
		{ 4,	&testminus,				"Test operator- with char*"		},
		{ 5,	&testbrackets,			"Test operator() with int,int"	},
		{ 6,	&testassignment,		"Test operator= with String*"	},
		{ 7,	&testconsolestream,		"Test console I/O"				},
		{ 8,	&testtextfile,			"Test text file I/O"			},
		{ 9,	&testbinaryfile,		"Test binary file I/O"			},
		{ 10,	&testbinnumberclass,	"Test BinNumber class"			},
	};
	while (true)
	{
		int choice;
		SetConsoleTextAttribute(hConsoleHandle, 10 | 0);
		for each (Interface i in items)
			cout << i.id << ". " << i.comment << "\n";
		SetConsoleTextAttribute(hConsoleHandle, 12 | 0);
		cout << "Choose menu item: ";
		cin >> choice;
		SetConsoleTextAttribute(hConsoleHandle, 9 | 0);
		if (choice < 1 || choice > sizeof(items) / sizeof(Interface))
			return 0;
		items[choice - 1].invoke();
		_getch();
		system("cls");
	}
	_getch();
	return 0;
}