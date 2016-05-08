#pragma once
class Block
{
private:
	char brief[10];
	char Actual[100];

public:
	Block(char* givenBrief , char* givenActual);
	~Block();
	char* getBrief();
	char* getActual();
};

