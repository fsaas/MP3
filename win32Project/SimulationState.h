#pragma once
#include "GState.h"
class GImage;
class GRenderer;
class GButton;

class Player;
class Flag;
class subFlag;

class SimulationState : public GState
{
private:
	GImage* bImage;
	GImage* ground;
	Player* player;
	GButton* exit;
	Flag* flag;
	subFlag* subflag;
	int m_stageNum;
	GImage* m_failImg;
	bool m_succ;

public:
	SimulationState(bool Success, int stageNum);
	~SimulationState();
	void OnDraw();
	void OnUpdate(float dt);
	void OnInitailize();
	void OnDestroy();
	void StageEnd();
};

