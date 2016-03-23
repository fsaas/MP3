#pragma once
#include "GRenderer.h"
#include "GScene.h"
#include "GImage.h"
class LogoState
{
private:
	GImage* bgImage;
	unsigned int bgAlpha;
	int bgFadeState;
public:
	GImage* getImage() { return bgImage; }
	unsigned int getBgAlpha() { return bgAlpha; }
	unsigned int fadeIn(unsigned int color) {
		color += 0x01ffffff;
		return color;
	}
	unsigned int fadeOut(unsigned int color) {
		color -= 0x01ffffff;
		return color;
	}
	LogoState(GImage* image);
	~LogoState();
	void OnUpdate();
	void OnDraw(GRenderer* gr);
	void OnDestroy();
	void OnInitialize(GRenderer* gr);
};

