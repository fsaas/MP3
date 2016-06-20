#pragma once
#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"


class SimulationState : public GState
{
private:
	GImage* bImage;
public:
	SimulationState(bool success);
	~SimulationState();
	void OnUpdate(float dt);
	void OnDraw();
	void OnDestroy();
	void OnInitialize();
};

