#pragma once
#include "GImage.h"
#include "GRenderer.h"
#include "GWindow.h"
class GButton
{
private:
	GImage* image;
	RECT r;
	bool IsClick;
	bool IsOn;
public:
	GButton(GImage* image, RECT r);
	~GButton();
	void setImage(GImage* image) { this->image = image; }
	void setR(int i, char a);
	void setR(RECT r);
	GImage* getImage() { return image; }
	int getR(char a);
	RECT getR();
	bool getClick() { return this->IsClick; }
	bool getOn() { return this->IsOn; }
	void setClick();
	void setOn();
};

