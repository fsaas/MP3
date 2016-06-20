#include "SimulationState.h"
#include "mainProc.h"
#include "GRenderer.h"
#include "GImage.h"
#include "Player.h"
#include "Flag.h"

SimulationState::SimulationState(bool Success, int stageNum)
{
	this->m_stageNum = stageNum;
	this->bImage = new GImage(Renderer(), "./Resource/LogoState.png");
	this->ground = new GImage(Renderer(), "./Resource/Ground.png");

	this->player = new Player(stageNum);
	this->flag = new Flag();
	this->subflag = new subFlag(player);
}


SimulationState::~SimulationState()
{

}


void SimulationState::OnInitailize()
{
}

void SimulationState::OnDraw()
{
	//배경 & 그라운드 & 플레이어
	Renderer()->Draw(bImage, 0, 0);
	Renderer()->Draw(ground, 0, 668);
	player->Draw();


	//스테이지 9
	if (this->m_stageNum == 9)
	{
		flag->Draw();
		subflag->Draw();
	}
}

void SimulationState::OnUpdate(float dt)
{
	player->Update();
	if (this->m_stageNum == 9)
	{
		flag->Update();
		subflag->Update();
	}
}

void SimulationState::OnDestroy()
{
}

