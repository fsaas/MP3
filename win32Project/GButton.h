#pragma once
#include "GImage.h"
#include "GRenderer.h"
#include "GWindow.h"
class GButton
{
private:
	GImage* image;
	RECT r;
public:
	GButton(GImage* image,RECT r);
	~GButton();
	void setImage(GImage* image) { this->image = image; }
	void setR(int i, char a);
	void setR(RECT r);
	GImage* getImage() { return image; }
	int getR(char a);
	RECT getR();
	bool getClick();
	bool getOn();
};

