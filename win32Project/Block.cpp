#include <string.h>
#include "Block.h"

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