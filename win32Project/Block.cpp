#include "Block.h"
#include<string.h>

Block::Block(char* givenBrief, char* givenActual)
{
	strcpy(brief, givenBrief);
	strcpy(Actual, givenActual);
}


Block::~Block()
{
}


char* Block::getBrief()
{
	return brief;
}
char* Block::getActual()
{
	return Actual;
}