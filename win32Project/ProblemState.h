#pragma once
#include <fstream>
#include <stdlib.h>
#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"
#include "GButton.h"
#include "BlockManager.h"

#define NILL new Block("","")

class Block;


class ProblemState : public GState
{
private:
	bool Click;
	int ClickCool;
	int time;
	GImage* bgImage, *tempImage;
	GButton* NButtons[15];
	Block* Blocks[8];
	int stageNum;
	int answer[4] = { -1,-1,-1,-1 };
	int Uanswer[4] = { -1,-1,-1,-1 };
	BlockManager* BM = new BlockManager();
	void setBlock(int BlockNum, int BlockIndex);
	void setAnswer(int answer[4]);
	bool isCorrect();
	void GOpen(char* filename);
	void insertAnswer(int clickedIndex);
	void deleteAnswer(int clickedIndex);
	void refresh();
	void setButtonImage();
public:
	ProblemState();
	~ProblemState();
	void setStageNum(int StageNum) { this->stageNum = StageNum; }
	void OnUpdate(float dt);
	void OnDraw();
	void OnDestroy();
	void OnInitialize();

};