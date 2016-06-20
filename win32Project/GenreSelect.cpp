#include "GenreSelect.h"
#include "mainProc.h"
#include "StageState.h"
#include "GFont.h"

GenreSelect::GenreSelect()
{
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");	//장르 선택씬 배경화면
	
	this->stageButtons[0] = new GButton(new GImage(Renderer(), "./Resource/actionStageButton.bmp"), 100, 100);
	this->stageButtons[1] = new GButton(new GImage(Renderer(), "./Resource/barrageStageButton.bmp"), 350, 100);
	this->stageButtons[2] = new GButton(new GImage(Renderer(), "./Resource/puzzleStageButton.bmp"), 100, 275);
	this->stageButtons[3] = new GButton(new GImage(Renderer(), "./Resource/shootingStageButton.bmp"), 350, 275);
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
		if (stageButtons[2]->getClick()) {
			StateMgr()->SetState(new StageState(2), STAGE_STATE);
			StateMgr()->ChangeState(STAGE_STATE);
		}
		if (stageButtons[3]->getClick()) {
			StateMgr()->SetState(new StageState(3), STAGE_STATE);
			StateMgr()->ChangeState(STAGE_STATE);
		}
	}
}
void GenreSelect::OnDraw()
{
	for (int i = 0; i < 4; i++) {
		Renderer()->Draw(stageButtons[i]->getImage(), stageButtons[i]->getR()->left, stageButtons[i]->getR()->top);		
		Renderer()->FontDraw(new GFont("NanumGothic", 10), "테스트 출력입니다.", 10, 10, 100, 1000, 0xff000000);
	}
}

void GenreSelect::OnDestroy()
{

}

void GenreSelect::OnInitialize()
{

}