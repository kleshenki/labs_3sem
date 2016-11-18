#include "BlogEntry.h"

BlogEntry::BlogEntry(int maxlength, char* entry)
{
	arr = new char[maxlength];
	maxlen = maxlength;
	strcpy_s(arr + 3, maxlength, entry);
	RecalcLength();
	create = time(NULL);
	time(&start);
	complete = false;
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

void BlogEntry::Print()
{
	struct tm* strt = localtime(&start);
	cout << "Started at " << strt->tm_hour << ":" << strt->tm_min << " \"" << arr + LEN << "\" and ";
	if (complete)
	{
		struct tm* endt = localtime(&end);
		cout << "completed at " << endt->tm_hour << ":" << endt->tm_min << ".\n";
	}
	else
		cout << "is still incomplete.\n";
}