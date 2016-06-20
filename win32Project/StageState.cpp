#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StageState.h"
#include "mainProc.h"
#include "Block.h"
#include "GFont.h"
#include <stdio.h>

StageState::StageState(int type) : GState()
{	
	this->m_font = new GFont("NanumGothic", 10);

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
	fclose(fp);

	this->genreType = type;
	this->descImage = new GImage(Renderer(), "./Resource/Font/rect.png");
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");
	int x, y;

	for (int i = 0; i < 15; i++) {
		if (i >= 0 && i <= 7) {
			Blocks[i] = NILL;
			if (i >= 0 && i <= 3) {
				y = 100;
				x = 200 + ((i % 4) * 200);
			}
			if( i>=4 && i<=7) {
				y = 250;
				x = 200 + ((i % 4) * 200);
			}
		}
		if (i >= 8 && i <= 11) {
			y = 500;
			x = 200 + ((i%4) * 240);
		}
		sprintf(temp, "./Resource/StageImg/stageX.bmp");
		this->NButtons[i] = new GButton(new GImage(Renderer(), temp), x, y);
	}
}


StageState::~StageState()
{
	for (int i = 0; i < 15; i++) {
		if (this->NButtons[i] != nullptr) delete NButtons[i];
	}
}

void StageState::OnInitialize() {

}

void StageState::OnUpdate(float dt) {
	bool flag = false;
	for (int i = 0; i < 15; i++) {
		if (NButtons[i]->getOn()) {
			flag = true;
			break;
		}
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
	}
}
void StageState::OnDraw() {
	Renderer()->Draw(this->bgImage, 0, 0);
	Renderer()->Draw(this->descImage, 800, 100);
	for (int i = 0; i < 15; i++) {
		Renderer()->Draw(NButtons[i]->getImage(), NButtons[i]->getR()->left, NButtons[i]->getR()->top);
	}
	for (int i = 0; i < 15; i++) {
		if (NButtons[i]->getOn()) {
			Renderer()->FontDraw(this->m_font, this->descText[i], 805, 105, 490, 490, 0xff000000);
		}
	}
}
void StageState::OnDestroy() {

}