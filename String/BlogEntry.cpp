#include "BlogEntry.h"

BlogEntry::BlogEntry(int maxlength, char* entry)
{
	arr = new char[maxlength];
	maxlen = maxlength;
	strcpy_s(arr + 3, maxlength, entry);
	RecalcLength();
	create = time(NULL);
	time(&start);
	allstr.insert(allstr.end(), this);
}

void BlogEntry::SetCompletionState(bool state)
{
	complete = state;
	time(&end);
}

bool BlogEntry::GetCompletionState()
{
	return complete;
}