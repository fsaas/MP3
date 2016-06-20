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
	SimulationState(bool Success);
	~SimulationState();
	void OnDraw();
	void OnUpdate();
	void OnInitailize();
	void OnDestroy();
};

