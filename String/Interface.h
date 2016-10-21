#pragma once

class Interface
{
public:
	int id;
	void(*invoke)();
	char* comment;
};