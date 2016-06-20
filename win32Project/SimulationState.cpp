#include "SimulationState.h"
#include "mainProc.h"
#include "GRenderer.h"
#include "GImage.h"
#include "Player.h"


SimulationState::SimulationState(bool Success)
{
	this->bImage = new GImage(Renderer(), "./Resource/LogoState.png");
	this->ground = new GImage(Renderer(), "./Resource/Ground.png");

	this->player = new Player();
}


SimulationState::~SimulationState()
{

}


void SimulationState::OnInitailize()
{
}

void SimulationState::OnDraw()
{
	Renderer()->Draw(bImage, 0, 0);
	Renderer()->Draw(ground, 0, 668);
	player->Draw();
}

void SimulationState::OnUpdate(float dt)
{
	player->Update();
}

void SimulationState::OnDestroy()
{
}

