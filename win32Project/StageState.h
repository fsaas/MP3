#pragma once
#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"
#include "GButton.h"
#include "BlockManager.h"

#define NILL new Block("","")

class GFont;

class StageState : public GState
{
private:
	GImage* bgImage;
	GImage* descImage;
	GButton* returnBtn;
	GButton* NButtons[10];
	Block* Blocks[10];
	GFont * m_font;
	int stageNum;
	int genreType;
	char descText[10][1024];
	
public:
	StageState(int type);
	~StageState();
	GImage* getImage() { return bgImage; }
	GImage* getButtonImage(int i) { return NButtons[i]->getImage(); }
	void OnUpdate(float dt);
	void OnDraw();
	void OnDestroy();
	void OnInitialize();
};

