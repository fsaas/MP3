#include "mainProc.h"
#include "LogoState.h"


LogoState::LogoState()
{
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");
	this->bgAlpha = 0xffffff;
	this->bgFadeState = 0;
	RECT r[3];
	for (int i = 0; i < 3; i++) {
		r[i].bottom = 293 + (i * 175);
		r[i].top = 168 + (i * 175);
		r[i].left = 533 + (i * 0);
		r[i].right = 783 + (i * 0);

		this->NButtons[i] = new GButton(new GImage(Renderer(), "./Resource/LogoButton1.bmp"), r[i]);
	}
}


LogoState::~LogoState()
{
	for (int i = 0; i < 3; i++) {
		if (this->NButtons[i] != nullptr) delete NButtons[i];
	}
}

void LogoState::OnInitialize() {

}
void LogoState::OnUpdate(float dt) {
	if (NButtons[0]->getOn()|| NButtons[1]->getOn()|| NButtons[2]->getOn())
		SetCursor(LoadCursor(NULL, IDC_HAND));
	else
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	if (IsMouseDown(0)) {
		if (NButtons[0]->getClick()) {
			StateMgr()->ChangeState(1);
		}
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
}