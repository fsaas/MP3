#pragma once
class Block
{
private:
	char brief[10];
	char def[100];

public:
	Block(char* givenBrief , char* givenDef);
	~Block();
	char* getBrief();
	char* getDef();
};

