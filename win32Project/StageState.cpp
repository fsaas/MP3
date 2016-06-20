#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StageState.h"
#include "mainProc.h"
#include "Block.h"
#include "GFont.h"
#include <stdio.h>
#include "GWindow.h"
#include "GButton.h"

StageState::StageState(int type) : GState()
{	
	this->m_font = new GFont("NanumGothic", 15);
	this->returnBtn = new GButton(new GImage(Renderer(), "./Resource/returnBtn.bmp"), 30, 450);
	char temp[256] = { 0, };
	FILE * fp = NULL;
	if (type == 0) {
		fp = fopen("./Resource/desc/Action.txt", "rt");
	}
	else if (type == 1) {
		fp = fopen("./Resource/desc/Bullet.txt", "rt");
	}
	
	if (fp != NULL) {
		for (int i = 0; i < 10; i++) {
			fgets(descText[i], 1024, fp);
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			descText[i][0] = '\0';
		}
	}
	if(fp != NULL)	fclose(fp);

	this->genreType = type;
	this->descImage = new GImage(Renderer(), "./Resource/Font/rect.png");
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");
	int x, y;

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			x = (j * 150) + 30;
			y = (i * 150) + 150;
			Blocks[i * 5 + j] = NILL;
			sprintf(temp, "./Resource/StageImg/stageX.bmp");
			this->NButtons[i * 5 + j] = new GButton(new GImage(Renderer(), temp), x, y);
		}
	}
}


StageState::~StageState()
{
	for (int i = 0; i < 10; i++) {
		if (this->NButtons[i] != nullptr) delete NButtons[i];
	}
	if (m_font != nullptr) delete m_font;
	if (returnBtn != nullptr) delete returnBtn;
	if (descImage != nullptr) delete descImage;
	if (bgImage != nullptr) delete bgImage;
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
	if (returnBtn->getOn()) {
		flag = true;
	}
	if (flag)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	else
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	if (IsMouseDown(0)) {
		if (NButtons[0]->getClick()) {
			StateMgr()->ChangeState(3);
		}
		if (NButtons[1]->getClick()) {
			PostQuitMessage(0);
		}
		if (returnBtn->getClick()) {
			StateMgr()->ChangeState(1);
		}
	}
	SetPrevMouseDown();
}

void StageState::OnDraw() {
	Renderer()->Draw(this->bgImage, 0, 0);
	Renderer()->Draw(this->descImage, 800, 100);
	for (int i = 0; i < 10; i++) {
		Renderer()->Draw(NButtons[i]->getImage(), NButtons[i]->getR()->left, NButtons[i]->getR()->top);
	}
	for (int i = 0; i < 10; i++) {
		if (NButtons[i]->getOn()) {
			Renderer()->FontDraw(this->m_font, this->descText[i], 805, 105, 490, 490, 0xff000000);
		}
	}
	Renderer()->Draw(returnBtn->getImage(), returnBtn->getR()->left, returnBtn->getR()->top);
}
void StageState::OnDestroy() {

}

GImage * StageState::getButtonImage(int i) { return NButtons[i]->getImage();

}
