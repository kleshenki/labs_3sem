#pragma once
#include "String.h"

class BinNumber : public String
{
public:
	explicit BinNumber() : String() {};
	BinNumber(int maxlen, char* strarr);
};