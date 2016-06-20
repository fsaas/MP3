#pragma once
#include "GImage.h"
class subFlag
{
private:  
	GImage *img;
	float x;
	float y;

public:
	subFlag();
	~subFlag();
	float getX();
	float getY();
	void setX(float);
	void setY(float);
	void down();
};

