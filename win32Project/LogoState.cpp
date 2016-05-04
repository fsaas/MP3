#include "mainProc.h"
#include "LogoState.h"


LogoState::LogoState()
{
	this->bgImage = new GImage(Renderer(), "LogoState.bmp");
	this->bgAlpha = 0xffffff;
	this->bgFadeState = 0;
	this->Buttons[0] = new GImage(Renderer(), "LogoButton1.bmp");
	this->Buttons[1] = new GImage(Renderer(), "LogoButton2.bmp");
	this->Buttons[2] = new GImage(Renderer(), "LogoButton3.bmp");
	RECT r[3];
	for (int i = 0; i < 3; i++) {
		r[i].bottom = 293 + (i * 175);
		r[i].top = 168 + (i * 175);
		r[i].left = 533 + (i * 0);
		r[i].right = 783 + (i * 0);
	}
	this->NButtons[0] = new GButton(this->Buttons[0], r[0]);
	this->NButtons[1] = new GButton(this->Buttons[1], r[1]);
	this->NButtons[2] = new GButton(this->Buttons[2], r[2]);
}


LogoState::~LogoState()
{
}

void LogoState::OnInitialize() {

}
void LogoState::OnUpdate(float dt) {
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
void LogoState::OnDraw() {
	Renderer()->DrawSetAlpha(getImage(), 0, 0, getBgAlpha());
	
	for (int i = 0; i < 3; i++) {
		Renderer()->Draw(NButtons[i]->getImage(), NButtons[i]->getR('L'), NButtons[i]->getR('T'));
	}
}
void LogoState::OnDestroy() {
	for (int i = 0; i < 3; i++) {
		if (this->NButtons[i] != nullptr) delete NButtons[i];
		if (this->Buttons[i] != nullptr) delete Buttons[i];
	}
}