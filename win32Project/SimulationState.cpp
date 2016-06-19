#include "SimulationState.h"
#include "mainProc.h"



SimulationState::SimulationState()
{
	this->bImage = new GImage(Renderer(), "./Resource/background.jpg");
}


SimulationState::~SimulationState()
{
}

void SimulationState::OnDraw()
{
	Renderer()->Draw(bImage, 0, 0);
}

void SimulationState::Update()
{
}

