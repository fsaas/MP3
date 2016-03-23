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

void GButton::setClick()
{
	if (IsMouseDown(0)) {
		if (GetMouseX() > r.left && GetMouseX() < r.right)
			if (GetMouseY() > r.bottom && GetMouseY() < r.top)
				IsClick = true;
	}
	else
		IsClick = false;
}

void GButton::setOn()
{
	if (GetMouseX() > r.left && GetMouseX() < r.right) {
		if (GetMouseY() > r.bottom && GetMouseY() < r.top)
			IsOn = true;
	}
	else
	{
		IsOn = false;
	}
	
	
}
