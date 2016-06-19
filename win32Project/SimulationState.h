#pragma once
#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"


class SimulationState
{
private:
	GImage* bImage;
public:
	SimulationState();
	~SimulationState();
	void OnDraw();
	void Update();
};

