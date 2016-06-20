#pragma once
#include "GState.h"
class GImage;
class GRenderer;

class SimulationState : public GState
{
private:
	GImage* bImage;
	GImage* ground;
public:
	SimulationState(bool Success);
	~SimulationState();
	void OnDraw();
	void OnUpdate();
	void OnInitailize();
	void OnDestroy();
};

