#pragma once
class IncorrectBinaryNumberException
{
public:
	char* message;
	IncorrectBinaryNumberException(char* msg) { message = msg; };
};

class IncorrectBinaryLengthException
{
public:
	char* message;
	IncorrectBinaryLengthException(char* msg) { message = msg; };
};

class IncorrectBinaryStartException
{
public:
	char* message;
	IncorrectBinaryStartException(char* msg) { message = msg; };
};