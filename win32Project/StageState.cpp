#include <fstream>
#include "StageState.h"
#include "mainProc.h"

StageState::StageState(int type) : GState()
{
	this->genreType = type;

	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");
	std::ifstream stage("stage%d.txt", stageNum);
	RECT r[15];
	for (int i = 0; i < 15; i++) {
		if (i >= 0 && i <= 7) {
			Blocks[i] = NILL;
			if (i >= 0 && i <= 3) {
				r[i].top = 100;
				r[i].bottom = r[i].top + 85;
				r[i].left = 200 + ((i % 4) * 200);
				r[i].right = r[i].left + 85;
			}
			if( i>=4 && i<=7) {
				r[i].top = 250;
				r[i].bottom = r[i].top + 85;
				r[i].left = 200 + ((i % 4) * 200);
				r[i].right = r[i].left + 85;
			}
		}
		if (i >= 8 && i <= 11) {
			r[i].top = 500;
			r[i].bottom = r[i].top + 100;
			r[i].left = 200 + ((i%4) * 240);
			r[i].right = r[i].left + 200;
		}

		this->NButtons[i] = new GButton(new GImage(Renderer(), "./Resource/StageImg/stageX.bmp"), r[i]);
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
}