#include "GenreSelect.h"
#include "mainProc.h"
#include "StageState.h"

GenreSelect::GenreSelect()
{
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");	//장르 선택씬 배경화면
	
	RECT r[4];
	for (int i = 0; i < 4; i++) {
		if (i >= 0 && i < 2) {
			r[i].top = 100 + (i * 0);
			r[i].bottom = 200 + (i * 0);
			r[i].left = 100 + (i * 250);
			r[i].right = 200 + (i * 250);

		}
		else{
			r[i].top = 275 + (i * 0);
			r[i].bottom = 375 + (i * 0);
			r[i].left = 100 + ((i - 2) * 250);
			r[i].right = 200 + ((i - 2) * 250);
		}
	}

	this->stageButtons[0] = new GButton(new GImage(Renderer(), "./Resource/actionStageButton.bmp"), r[0]);
	this->stageButtons[1] = new GButton(new GImage(Renderer(), "./Resource/barrageStageButton.bmp"), r[1]);
	this->stageButtons[2] = new GButton(new GImage(Renderer(), "./Resource/puzzleStageButton.bmp"), r[2]);
	this->stageButtons[3] = new GButton(new GImage(Renderer(), "./Resource/shootingStageButton.bmp"), r[3]);
}


GenreSelect::~GenreSelect()
{
	for (int i = 0; i < 4; i++) {
		if (this->stageButtons[i] != nullptr) delete stageButtons[i];
	}
}

void GenreSelect::OnUpdate(float dt)
{
	if (stageButtons[0]->getOn() || stageButtons[1]->getOn() || stageButtons[2]->getOn() || stageButtons[3])
		SetCursor(LoadCursor(NULL, IDC_HAND));
	else
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	if (IsMouseDown(0)) {
		if (stageButtons[0]->getClick()) {
			StateMgr()->SetState(new StageState(0), STAGE_STATE);
			StateMgr()->ChangeState(STAGE_STATE);
		}
		if (stageButtons[1]->getClick()) {
			StateMgr()->SetState(new StageState(1), STAGE_STATE);
			StateMgr()->ChangeState(STAGE_STATE);
		}
	}
}
void GenreSelect::OnDraw()
{
	for (int i = 0; i < 4; i++) {
		Renderer()->Draw(stageButtons[i]->getImage(), stageButtons[i]->getR('L'), stageButtons[i]->getR('T'));		
	}
}

void GenreSelect::OnDestroy()
{

}

void GenreSelect::OnInitialize()
{

}