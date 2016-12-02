#include "BinNumber.h"

BinNumber::BinNumber(int maxlength, char* strarr)
{
	for (int i = 0; i < maxlength - 1; i++)
	{
		if (strarr[i] == '\n')
			break;
		if (strarr[i] != '0' && strarr[i] != '1')
		{
			//std::cout << "Incorrect binary number.";
			throw "Incorrect binary number";
			return;
		}
	}
	arr = new char[maxlength+1];
	maxlen = maxlength;
	strcpy_s(arr + 3, maxlength+1, strarr);
	RecalcLength();
	create = time(NULL);
	allstr.insert(allstr.end(), this);
}