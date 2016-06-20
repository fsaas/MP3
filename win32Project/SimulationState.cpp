#include "SimulationState.h"
#include "GStateManager.h"
#include "mainProc.h"
#include "GRenderer.h"
#include "GImage.h"
#include "Player.h"
#include "Flag.h"
#include "GButton.h"
#include "GWindow.h"
#include <stdio.h>

SimulationState::SimulationState(bool Success, int stageNum)
{
	this->m_succ = Success;
	this->m_stageNum = stageNum;
	this->bImage = new GImage(Renderer(), "./Resource/background.png");
	this->ground = new GImage(Renderer(), "./Resource/Ground.png");
	this->exit = new GButton(new GImage(Renderer(), "./Resource/temp.png"), 30, 700);
	this->player = new Player(stageNum);
	this->flag = new Flag();
	this->subflag = new subFlag(player);
	this->m_failImg = new GImage(Renderer(), "./Resource/Action_img/fail.png");
}


SimulationState::~SimulationState()
{
}


void SimulationState::OnInitailize()
{
}

void SimulationState::OnDraw()
{
	if (m_succ) {
		//배경 & 그라운드 & 플레이어
		Renderer()->Draw(bImage, 0, 0);
		Renderer()->Draw(ground, 0, 668);
		Renderer()->Draw(exit->getImage(), exit->getR()->left, exit->getR()->top);
		player->Draw();


		//스테이지 9
		if (this->m_stageNum == 9)
		{
			flag->Draw();
			subflag->Draw();
		}
	}
	else {
		Renderer()->Draw(m_failImg, 0, 0);
		Renderer()->Draw(exit->getImage(), exit->getR()->left, exit->getR()->top);
	}
}

void SimulationState::OnUpdate(float dt)
{
	bool t = false;
	if (exit->getOn()) {
		t = true;
	}
	if (t) {
		SetCursor(LoadCursor(NULL, IDC_HAND));
	}
	else {
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	}

	if (IsMouseDown(0)) {
		if (exit->getClick())
			StateMgr()->ChangeState(2);
	}
	
	if (m_succ) {
		player->Update();

		//stage가 9일때 깃발 세움
		if (this->m_stageNum == 9)
		{
			flag->Update();
			subflag->Update();
		}
	}
	SetPrevMouseDown();
}

void SimulationState::OnDestroy()
{
}

void SimulationState::StageEnd()
{
}

