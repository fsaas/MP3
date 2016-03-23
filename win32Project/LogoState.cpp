#include "LogoState.h"



LogoState::LogoState(GImage* image)
{
	this->bgImage = image;
	this->bgAlpha = 0xffffff;
	this->bgFadeState = 0;
}


LogoState::~LogoState()
{
}

void LogoState::OnInitialize(GRenderer* gr) {

}
void LogoState::OnUpdate() {
	if (getBgAlpha() >= 0xefffffff)
		bgFadeState = 1;
	if (getBgAlpha() <= 0x00ffffff)
		bgFadeState = 0;
	if (bgFadeState == 0)
		bgAlpha = fadeIn(getBgAlpha());
	if (bgFadeState == 1)
		bgAlpha = fadeOut(getBgAlpha());
}
void LogoState::OnDraw(GRenderer* gr) {
	gr->DrawSetAlpha(getImage(), 0, 0, getBgAlpha());
}
void LogoState::OnDestroy() {
}