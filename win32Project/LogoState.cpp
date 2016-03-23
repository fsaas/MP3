#include "LogoState.h"


LogoState::LogoState(GImage* image, GImage* BtImage1, GImage* BtImage2, GImage* BtImage3)
{
	this->bgImage = image;
	this->bgAlpha = 0xffffff;
	this->bgFadeState = 0;
	this->Buttons[0] = BtImage1;
	this->Buttons[1] = BtImage2;
	this->Buttons[2] = BtImage3;
}


LogoState::~LogoState()
{
}

void LogoState::OnInitialize(GRenderer* gr) {

}
void LogoState::OnUpdate() {
	if (GetMouseX() > 534 && GetMouseX() < 834)
		if (GetMouseY() > 168 && GetMouseY() < 318) {
			SetCursor(LoadCursor(NULL, IDC_HAND));
		}
		else
			;
	else
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	if (IsMouseDown(0)) {
		if (GetMouseX() > 534 && GetMouseX() < 834)
			if (GetMouseY() > 168 && GetMouseY() < 318) {
				if (Buttons[0] != Buttons[1])
					Buttons[0] = Buttons[1];
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
		gr->Draw(getButtonImage(i), 534, 168 + i * 175);
	}
}
void LogoState::OnDestroy() {
}