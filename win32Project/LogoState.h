#pragma once
#include "GRenderer.h"
#include "GScene.h"
#include "GImage.h"
class LogoState
{
private:
	GImage* bgImage;
public:
	GImage* getImage() { return bgImage; }
	LogoState(GImage* image);
	~LogoState();
	void OnUpdate();
	void OnDraw(GRenderer* gr);
	void OnDestroy();
	void OnInitialize(GRenderer* gr);
};

