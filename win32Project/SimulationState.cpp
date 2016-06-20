#include "SimulationState.h"
#include "mainProc.h"



SimulationState::SimulationState(bool success)
{
	this->bImage = new GImage(Renderer(), "./Resource/background.jpg");
}


SimulationState::~SimulationState()
{
}

void SimulationState::OnUpdate(float dt)
{
}

void SimulationState::OnDraw()
{
}

void SimulationState::OnDestroy()
{
}

void SimulationState::OnInitialize()
{
}
