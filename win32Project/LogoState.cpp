#include "LogoState.h"


LogoState::LogoState(GImage* image, GImage* BtImage1, GImage* BtImage2, GImage* BtImage3)
{
	this->bgImage = image;
	this->bgAlpha = 0xffffff;
	this->bgFadeState = 0;
	this->Buttons[0] = BtImage1;
	this->Buttons[1] = BtImage2;
	this->Buttons[2] = BtImage3;
	RECT r[3];
	for (int i = 0; i < 3; i++) {
		r[i].bottom = 293 + (i * 175);
		r[i].top = 168 + (i * 175);
		r[i].left = 533 + (i * 0);
		r[i].right = 783 + (i * 0);
	}
	this->NButtons[0] = new GButton(BtImage1, r[0]);
	this->NButtons[1] = new GButton(BtImage2, r[1]);
	this->NButtons[2] = new GButton(BtImage3, r[2]);
}


LogoState::~LogoState()
{
}

void LogoState::OnInitialize(GRenderer* gr) {

}
void LogoState::OnUpdate() {
	if (NButtons[0]->getOn()|| NButtons[1]->getOn()|| NButtons[2]->getOn())
		SetCursor(LoadCursor(NULL, IDC_HAND));
	else
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	if (IsMouseDown(0)) {
		if (NButtons[1]->getClick()) {
			PostQuitMessage(0);
		}
	}
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
	for (int i = 0; i < 3; i++) {
		gr->Draw(NButtons[i]->getImage(), NButtons[i]->getR('L'), NButtons[i]->getR('T'));
	}
}
void LogoState::OnDestroy() {
}