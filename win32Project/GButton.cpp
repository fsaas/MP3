#include "GButton.h"



GButton::GButton(GImage * image, RECT r)
{
	setImage(image);
	setR(r);
}

GButton::~GButton()
{
}

void GButton::setR(int i, char a)
{
	switch (a)
	{
	case 'L':
		this->r.left = i;
		break;
	case 'R':
		this->r.right = i;
		break;
	case 'T':
		this->r.top = i;
		break;
	case 'B':
		this->r.bottom = i;
		break;
	default:
		break;
	}

}
void GButton::setR(RECT r)
{
	this->r = r;
}
int GButton::getR(char a)
{
	switch (a)
	{
	case 'L':
		return this->r.left;
		break;
	case 'R':
		return this->r.right;
		break;
	case 'T':
		return this->r.top;
		break;
	case 'B':
		return this->r.bottom;
		break;
	default:
		break;
	}

}

RECT GButton::getR()
{
	return this->r;
}

bool GButton::getClick()
{
	if (GetMouseX() > getR('L') && GetMouseX() < getR('R')) {
		if (GetMouseY() < getR('B') && GetMouseY() > getR('T')) {
			return true;
		}
	}
		return false;
}

bool GButton::getOn()
{
	if (GetMouseX() > getR('L') && GetMouseX() < getR('R')) {
		if (GetMouseY() < getR('B') && GetMouseY() > getR('T')) {
			return true;
		}
	}
	return false;
	
	
}
