#include "BinNumber.h"
#include "Exception.h"

BinNumber::BinNumber(int maxlength, char* strarr)
{
	if (strarr[0] == '0')
	{
		throw new IncorrectBinaryStartException("Incorrect binary start.");
		return;
	}
	for (int i = 0; i < maxlength - 1; i++)
	{
		if (strarr[i] == '\n' && i != maxlength - 1)
		{
			throw new IncorrectBinaryLengthException("Incorrect binary length.");
			return;
		}
		if (strarr[i] == '\n')
			break;
		if (strarr[i] != '0' && strarr[i] != '1')
		{
			//std::cout << "Incorrect binary number.";
			throw new IncorrectBinaryNumberException("Incorrect binary number.");
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