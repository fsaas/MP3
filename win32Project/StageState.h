#pragma once
#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"
#include "GButton.h"
#include "BlockManager.h"

#define NILL new Block(NULL,NULL)

class StageState : public GState
{
private:
	GImage* bgImage;
	GButton* NButtons[15];
	Block* Blocks[8];
	int stageNum;
	
	
public:
	StageState();
	~StageState();
	GImage* getImage() { return bgImage; }
	GImage* getButtonImage(int i) { return NButtons[i]->getImage(); }
	void OnUpdate(float dt);
	void OnDraw();
	void OnDestroy();
	void OnInitialize();
};

