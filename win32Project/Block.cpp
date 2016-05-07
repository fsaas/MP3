#include "Block.h"
#include<string.h>

Block::Block(char* givenBrief, char* givenDef)
{
	strcpy(brief, givenBrief);
	strcpy(def, givenDef);
}


Block::~Block()
{
}


char* Block::getBrief()
{
	return brief;
}
char* Block::getDef()
{
	return def;
}