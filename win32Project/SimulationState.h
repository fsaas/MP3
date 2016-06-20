#pragma once
#include "GState.h"
class GImage;
class GRenderer;
class Player;

class SimulationState : public GState
{
private:
	GImage* bImage;
	GImage* ground;
	Player* player;

public:
	SimulationState(bool Success);
	~SimulationState();
	void OnDraw();
	void OnUpdate(float dt);
	void OnInitailize();
	void OnDestroy();
};

