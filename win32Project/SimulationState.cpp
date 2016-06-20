#include "SimulationState.h"
#include "mainProc.h"
#include "GRenderer.h"
#include "GImage.h"



SimulationState::SimulationState(bool Success)
{
	this->bImage = new GImage(Renderer(), "./Resource/LogoState.bmp");
}


SimulationState::~SimulationState()
{

}

void SimulationState::OnDraw()
{
	Renderer()->Draw(bImage, 0, 0);
}

void SimulationState::OnUpdate()
{
}

void SimulationState::OnInitailize()
{
}

void SimulationState::OnDestroy()
{
}

