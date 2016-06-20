#pragma once
#include "GState.h"
class GImage;
class GRenderer;
class Player;
class Flag;
class subFlag;

class SimulationState : public GState
{
private:
	GImage* bImage;
	GImage* ground;
	Player* player;
	Flag* flag;
	subFlag* subflag;
	int m_stageNum;

public:
	SimulationState(bool Success, int stageNum);
	~SimulationState();
	void OnDraw();
	void OnUpdate(float dt);
	void OnInitailize();
	void OnDestroy();
};

