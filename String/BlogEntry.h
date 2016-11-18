#pragma once
#include <ctime>
#include "String.h"

class BlogEntry : public String
{
private:
	bool complete;
	time_t start, end;
public:
	explicit BlogEntry() : String() {};
	BlogEntry(int maxlen, char* entry);

	void SetCompletionState(bool state);
	bool GetCompletionState();
	void Print();
};