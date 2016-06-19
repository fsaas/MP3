#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StageState.h"
#include "mainProc.h"
#include <stdio.h>

StageState::StageState(int type) : GState()
{
	this->genreType = type;

	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");
	int x, y;
	char temp[256] = { 0, };

	for (int i = 0; i < 10; i++) {
		x = 100 + ((i % 4) * 100);
		y = 100 + ((i / 4) * 100);
		sprintf(temp, "./Resource/StageImg/stageX.bmp");
		this->NButtons[i] = new GButton(new GImage(Renderer(), temp), x, y);
	}
}


StageState::~StageState()
{
	for (int i = 0; i < 10; i++) {
		if (this->NButtons[i] != nullptr) delete NButtons[i];
	}
}

void StageState::OnInitialize() {

}

void StageState::OnUpdate(float dt) {
	bool flag = false;
	for (int i = 0; i < 10; i++) {
		if (NButtons[i]->getOn()) {
			flag = true;
			break;
		}
	}
	if (flag)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	else
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	/*if (IsMouseDown(0)) {
		if (NButtons[0]->getClick()) {
			StateMgr()->ChangeState(2);
		}
		if (NButtons[1]->getClick()) {
			PostQuitMessage(0);
		}
	}*/
}
void StageState::OnDraw() {

	for (int i = 0; i < 10; i++) {
		Renderer()->Draw(NButtons[i]->getImage(), NButtons[i]->getR()->left, NButtons[i]->getR()->top);
	}
}
void StageState::OnDestroy() {
}