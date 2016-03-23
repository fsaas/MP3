#pragma once
#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"
class LogoState : public GState
{
private:
	GImage* bgImage;
	GImage* Buttons[3];
	unsigned int bgAlpha;
	int bgFadeState;
	bool Start = false;
public:
	GImage* getImage() { return bgImage; }
	GImage* getButtonImage(int i) { return Buttons[i]; }
	unsigned int getBgAlpha() { return bgAlpha; }
	unsigned int fadeIn(unsigned int color) {
		color += 0x01ffffff;
		return color;
	}
	unsigned int fadeOut(unsigned int color) {
		color -= 0x01ffffff;
		return color;
	}
	LogoState(GImage* image, GImage* BtImage1, GImage* BtImage2, GImage* BtImage3);
	~LogoState();
	void OnUpdate();
	void OnDraw(GRenderer* gr);
	void OnDestroy();
	void OnInitialize(GRenderer* gr);
};

