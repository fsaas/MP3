#pragma once
#include "GState.h"
class GImage;
class GRenderer;
class Player;
class Flag;

class SimulationState : public GState
{
private:
	GImage* bImage;
	GImage* ground;
	Player* player;
	Flag* flag;

public:
	SimulationState(bool Success);
	~SimulationState();
	void OnDraw();
	void OnUpdate(float dt);
	void OnInitailize();
	void OnDestroy();
};

