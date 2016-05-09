
#include <fstream>
#include "StageState.h"
#include "mainProc.h"



StageState::StageState()
{
	this->bgImage = new GImage(Renderer(), "LogoState.bmp");
	std::ifstream stage("stage%d.txt", stageNum);
	RECT r[15];
	for (int i = 0; i < 15; i++) {
		if (i >= 0 && i <= 7) {
			Blocks[i] = NILL;
			if (i >= 0 && i <= 3) {
				r[i].top = 100;
				r[i].bottom = r[i].top + 100;
				r[i].left = 200 + ((i % 4) * 200);
				r[i].right = r[i].left + 200;
			}
			if( i>=4 && i<=7) {
				r[i].top = 250;
				r[i].bottom = r[i].top + 100;
				r[i].left = 200 + ((i % 4) * 200);
				r[i].right = r[i].left + 200;
			}
		}
		if (i >= 8 && i <= 11) {
			r[i].top = 500;
			r[i].bottom = r[i].top + 100;
			r[i].left = 200 + ((i%4) * 240);
			r[i].right = r[i].left + 200;
		}
	}
	this->NButtons[0] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[0]);
	this->NButtons[1] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[1]);
	this->NButtons[2] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[2]);
	this->NButtons[3] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[3]);
	this->NButtons[4] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[4]);
	this->NButtons[5] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[5]);
	this->NButtons[6] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[6]);
	this->NButtons[7] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[7]);
	this->NButtons[8] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[8]);
	this->NButtons[9] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[9]);
	this->NButtons[10] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[10]);
	this->NButtons[11] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[11]);
	this->NButtons[12] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[12]);
	this->NButtons[13] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[13]);
	this->NButtons[14] = new GButton(new GImage(Renderer(), "LogoButton1.bmp"), r[14]);
}


StageState::~StageState()
{
}

void StageState::OnInitialize() {

}
void StageState::OnUpdate(float dt) {
	if (NButtons[0]->getOn() || NButtons[1]->getOn() || NButtons[2]->getOn() || NButtons[3]->getOn() || NButtons[4]->getOn() || NButtons[5]->getOn() || NButtons[6]->getOn() || NButtons[7]->getOn() || NButtons[8]->getOn() || NButtons[9]->getOn()|| NButtons[10]->getOn() || NButtons[11]->getOn() || NButtons[12]->getOn() || NButtons[13]->getOn() || NButtons[14]->getOn())
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

	for (int i = 0; i < 15; i++) {
		Renderer()->Draw(NButtons[i]->getImage(), NButtons[i]->getR('L'), NButtons[i]->getR('T'));
	}
}
void StageState::OnDestroy() {
	for (int i = 0; i < 15; i++) {
		if (this->NButtons[i] != nullptr) delete NButtons[i];
	}
}