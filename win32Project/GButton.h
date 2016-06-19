#pragma once
#include "GRenderer.h"
#include "GWindow.h"

class GImage;

class GButton
{
private:
	GImage* image;
	RECT* m_rect;
	 
public:
	GButton(GImage* image, int x, int y);
	GButton(GImage * image, RECT * rect);
	~GButton();
	void setImage(GImage* image);
	GImage* getImage();

	void setR(RECT * rect);
	RECT* getR();

	bool getClick();
	bool getOn();
};

