#include "subFlag.h"



subFlag::subFlag()
{
}


subFlag::~subFlag()
{
}

float subFlag::getX()
{
	return x;
}

float subFlag::getY()
{
	return y;
}

void subFlag::setX(float given)
{
	x = given;
}

void subFlag::setY(float given)
{
	y = given;
}

void subFlag::down()
{
	while (getY()>129)
	{
		setY(getY() - 2);
	}
}
