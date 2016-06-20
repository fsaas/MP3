#include "GenreSelect.h"
#include "mainProc.h"
#include "StageState.h"
#include "GFont.h"

GenreSelect::GenreSelect() : GState()
{
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.png");	//장르 선택씬 배경화면
	
	this->stageButtons[0] = new GButton(new GImage(Renderer(), "./Resource/actionStageButton.png"), 120, 90);
	this->stageButtons[1] = new GButton(new GImage(Renderer(), "./Resource/barrageStageButton.png"), 720, 90);
	this->stageButtons[2] = new GButton(new GImage(Renderer(), "./Resource/puzzleStageButton.png"), 120, 400);
	this->stageButtons[3] = new GButton(new GImage(Renderer(), "./Resource/shootingStageButton.png"), 720, 400);
}


GenreSelect::~GenreSelect()
{
	for (int i = 0; i < 4; i++) {
		if (this->stageButtons[i] != nullptr) delete stageButtons[i];
	}
	if (this->bgImage != nullptr) delete bgImage;
}

void GenreSelect::OnUpdate(float dt)
{
	if (stageButtons[0]->getOn() || stageButtons[1]->getOn() || stageButtons[2]->getOn() || stageButtons[3]->getOn())
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
		if (stageButtons[2]->getClick()) {
			StateMgr()->SetState(new StageState(2), STAGE_STATE);
			StateMgr()->ChangeState(STAGE_STATE);
		}
		if (stageButtons[3]->getClick()) {
			StateMgr()->SetState(new StageState(3), STAGE_STATE);
			StateMgr()->ChangeState(STAGE_STATE);
		}
	}
	SetPrevMouseDown();
}
void GenreSelect::OnDraw()
{
	Renderer()->Draw(this->bgImage, 0, 0);
	for (int i = 0; i < 4; i++) {
		Renderer()->Draw(stageButtons[i]->getImage(), stageButtons[i]->getR()->left, stageButtons[i]->getR()->top);
	}
}

void GenreSelect::OnDestroy()
{

}

void GenreSelect::OnInitialize()
{

}