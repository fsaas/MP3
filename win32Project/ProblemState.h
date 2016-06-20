#pragma once
#include <fstream>
#include <stdlib.h>
#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"
#include "GButton.h"
#include "Block.h"
#include "BlockManager.h"

#define NILL new Block("","")


class ProblemState : public GState
{
private:
	bool Click;
	int ClickCool;
	int time;
	GImage* bgImage;
	GButton* NButtons[15];
	Block* Blocks[8];
	int stageNum;
	int answer[4] = { -1,-1,-1,-1 };
	int Uanswer[4] = { -1,-1,-1,-1 };
	BlockManager* BM = new BlockManager();

	void setBlock(int BlockNum, int BlockIndex) {
		if (BlockNum == -1)
			this->Blocks[BlockIndex] = NILL;
		else
			this->Blocks[BlockIndex] = BM->getBlock(BlockNum);
	}

	void setAnswer(int answer[4])
	{
		for (int i = 0; i = 4; i++) {
			this->answer[i] = answer[i];
		}
	}

	bool isCorrect() {
		if (this->Uanswer == this->answer)
			return true;
		return false;
	}

	void GOpen(char* filename) {
		std::ifstream inFile(filename);
		char temp[100];
		int tempA[4];
		int i = 0;
		while (!inFile.eof()) {
			inFile.getline(temp, 100);
			if (i < 8) {
				setBlock(atoi(temp),i);
			}
			if (i > 7 && i < 12) {
				tempA[i - 8] = atoi(temp);
			}
			i++;
		}
		setAnswer(tempA);
	}

	void insertAnswer(int clickedIndex) {
		int i = 0;
			while (Uanswer[i] != -1) {
				i++;
				if (i > 4)
					return;
			}
			Uanswer[i] = clickedIndex;
	}

	void deleteAnswer(int clickedIndex) {
		if (Uanswer[clickedIndex-8] != -1) {
			Uanswer[clickedIndex-8] = -1;
		}
	}

	void refresh() {
		for (int i = 0; i < 4; i++)
			Uanswer[i] = -1;
	}

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