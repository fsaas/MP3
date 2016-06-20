#pragma once
#include <stdlib.h>
#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"
#include "GButton.h"
#include "BlockManager.h"

#define NILL new Block("","")

class Block; class GFont;

class ProblemState : public GState
{
private:
	bool Click;
	int ClickCool;
	int time;
	GImage* bgImage, *tempImage, *descImage;
	GFont * m_font, *m_titleFont;
	GButton* NButtons[15];
	Block* Blocks[8];
	int m_stageNum;
	int answer[4] = { -1,-1,-1,-1 };
	int Uanswer[4] = { -1,-1,-1,-1 };
	BlockManager* BM = new BlockManager();

	void setBlock(int BlockNum, int BlockIndex);
	void setAnswer(int blockNum, int index);
	bool isCorrect();
	void insertAnswer(int clickedIndex);
	void deleteAnswer(int clickedIndex);
	void refresh();
	void setButtonImage();
public:
	ProblemState();
	~ProblemState();
	void OnUpdate(float dt);
	void OnDraw();
	void OnDestroy();
	void OnInitialize();
	void GOpen(char* filename, int stageNum);

};