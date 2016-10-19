#include <iostream>
#include <conio.h>
#include "String.h"
#include "Interface.h"

using namespace std;

//Демонстрация работы конструкторов, работа 1
void testconstructor()
{
	cin.ignore();
	cout << "Enter string: ";
	char* input = new char[60];
	cin.getline(input, 60);
	String* test = new String(60, input);
	cout << "Real length: " << test->RealLength() << "\n";
	cout << "Maximal length: " << test->MaxLength() << "\n";
	cout << "Enter substring: ";
	cin.getline(input, 60);
	cout << "Substring by input: " << test->Substring(input) << "\n";
	cout << "Full string: ";
	test->Print();
	
	String* defaultconst = new String();
	String* copy = new String(*test);
	cout << "\n\n\nNow print all three strings: \n";
	String::PrintAll();
}

int main()
{
	Interface items[] =
	{
		{ 1, &testconstructor, "Test constructor" },
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