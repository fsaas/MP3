#include "ProblemState.h"
#include "mainProc.h"
#include "Block.h"
#include "SimulationState.h"
#include "GFont.h"
#include <stdio.h>
#define BImage new GImage(Renderer(),"./Resource/ProblemImg/TempImage.bmp")

ProblemState::ProblemState() : GState()
{
	time = 0;
	this->ClickCool = 10;
	this->Click = false;
	this->m_stageNum = -1;
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.png");
	this->tempImage = new GImage(Renderer(), "./Resource/ProblemImg/TempImage.bmp");
	this->descImage = new GImage(Renderer(), "./Resource/Font/BlockRect.png");
	this->m_font = new GFont("NanumGothic", 10);
	this->m_titleFont = new GFont("NanumGothic", 25);

	int x, y;
	char temp[100];
	for (int i = 0; i < 15; i++) {
		if (i >= 0 && i <= 7) {
			Blocks[i] = NILL;
			if (i >= 0 && i <= 3) {
				y = 100;
				x = 200 + ((i % 4) * 150);
			}
			if (i >= 4 && i <= 7) {
				y = 250;
				x = 200 + ((i % 4) * 150);
			}
			sprintf(temp, "./Resource/ProblemImg/TempImage%d.bmp", i + 1);
			this->NButtons[i] = new GButton(new GImage(Renderer(), temp), x, y);
		}
		if (i >= 8 && i <= 11) {
			y = 500;
			x = 200 + ((i % 4) * 240);
			this->NButtons[i] = new GButton(new GImage(Renderer(), "./Resource/ProblemImg/TempImage.bmp"), x, y);
		}
		if (i == 12) {
			y = 470;
			x = 1030;
			this->NButtons[i] = new GButton(new GImage(Renderer(), "./Resource/ProblemImg/TempRefesh.png"), x, y);
		}
		if (i == 13) {
			y = 650;
			x = 1150;
			this->NButtons[i] = new GButton(new GImage(Renderer(), "./Resource/Button.png"), x, y);
		}
		if (i == 14) {
			y = 650;
			x = 50;
			this->NButtons[i] = new GButton(new GImage(Renderer(), "./Resource/Button.png"), x, y);
		}
	}
}

void ProblemState::setBlock(int BlockNum, int BlockIndex)
{
	if (BlockNum == -1)
		this->Blocks[BlockIndex] = NILL;
	else
		this->Blocks[BlockIndex] = BM->getBlock(BlockNum);

}

void ProblemState::setAnswer(int blockNum, int index)
{
	this->answer[index] = blockNum;
}

bool ProblemState::isCorrect()
{
	if (this->Uanswer == this->answer)
		return true;
	return false;
}

void ProblemState::GOpen(char * filename, int stageNum)
{
	this->m_stageNum = stageNum;
	FILE * stageInfo = NULL;
	stageInfo = fopen(filename, "r");
	int tempA[4];
	char blockType; int blockNum;
	int blockIndex = 0, answerIndex = 0;
	for (int i = 0; i < 12; i++) {
		fscanf(stageInfo, "%c %d ", &blockType, &blockNum);
		
		if (blockType == 'B') {
			setBlock(blockNum, blockIndex++);
		}
		else if (blockType == 'A') {
			setAnswer(blockNum, answerIndex++);
		}
	}
	fclose(stageInfo);
}

void ProblemState::insertAnswer(int clickedIndex)
{
	int i = 0;
	while (Uanswer[i] != -1) {
		i++;
		if (i > 4)
			return;
	}
	Uanswer[i] = clickedIndex;

}

void ProblemState::deleteAnswer(int clickedIndex)
{
	if (Uanswer[clickedIndex - 8] != -1) {
		Uanswer[clickedIndex - 8] = -1;
	}

}

void ProblemState::refresh()
{
	for (int i = 0; i < 4; i++)
		Uanswer[i] = -1;

}

void ProblemState::setButtonImage() {
	for (int i = 0; i < 4; i++) {
		if (this->Uanswer[i] == -1)
			this->NButtons[i + 8]->setImage(this->tempImage);
		else
			this->NButtons[i + 8]->setImage(this->NButtons[this->Uanswer[i]]->getImage());
	}
}

ProblemState::~ProblemState()
{
	for (int i = 0; i < 15; i++) {
		if (this->NButtons[i] != nullptr) delete NButtons[i];
	}
	if (bgImage != nullptr) delete bgImage;
	if (tempImage != nullptr) delete tempImage;
	if (m_font != nullptr) delete m_font;
	if (m_titleFont != nullptr) delete m_titleFont;
}

void ProblemState::OnInitialize() {

}

void ProblemState::OnDraw() {
	bool flag = true;
	Renderer()->Draw(bgImage, 0, 0);

	for (int i = 0; i < 15; i++) {
		Renderer()->Draw(NButtons[i]->getImage(), NButtons[i]->getR()->left, NButtons[i]->getR()->top);
	}

	Renderer()->Draw(this->descImage, 800, 100);
	
	for (int i = 0; i < 8; i++) {
		if (NButtons[i]->getOn()) {
			flag = false;
			break;
		}
	}

	if(flag){
		char temp[255];
		sprintf(temp, "%d번 스테이지", this->m_stageNum + 1);
		Renderer()->FontDraw(m_titleFont, temp, 805, 105, 390, 340, 0xff000000);
		for (int i = 0; i < 8; i++) {
			sprintf(temp, "%d번 - %s", i+1, this->Blocks[i]->getBrief());
			Renderer()->FontDraw(this->m_font, temp, 805, 155 + (i * 30), 390, 340, 0xff000000);
		}

	}
	else {
		for (int i = 0; i < 8; i++) {
			if (NButtons[i]->getOn()) {
				Renderer()->FontDraw(this->m_titleFont, "Brief", 805, 105, 390, 170, 0xff000000);
				Renderer()->FontDraw(this->m_font, this->Blocks[i]->getBrief(), 805, 155, 390, 170, 0xff000000);
				Renderer()->FontDraw(this->m_titleFont, "Actual", 805, 280, 190, 170, 0xff000000);
				Renderer()->FontDraw(this->m_font, this->Blocks[i]->getActual(), 805, 330, 390, 170, 0xff000000);
			}
		}
	}
}

void ProblemState::OnUpdate(float dt) {
	if (this->Click == false) {
		time++;
		if (time > ClickCool) {
		this->Click = true;
		time = 0;
		}
	}
	this->setButtonImage();
	bool flag = false;
	for (int i = 0; i < 15; i++) {
		if (NButtons[i]->getOn()) {
			flag = true;
			break;
		}
	}
	if (flag)
		SetCursor(LoadCursor(NULL, IDC_HAND));
	else
		SetCursor(LoadCursor(NULL, IDC_ARROW));
	if (IsMouseDown(0) && Click) {
		this->Click = false;
		for (int i = 0; i < 15; i++) {
			if (NButtons[i]->getClick()) {
				if (i < 8) {
					this->insertAnswer(i);
				}
				if (i > 7 && i < 12) {
					this->deleteAnswer(i);
				}
				if (i == 12)
					this->refresh();
				if (i == 13){
					if (this->isCorrect()) {
						StateMgr()->SetState(new SimulationState(true), 4);
						StateMgr()->ChangeState(4);
					}
					else {
						StateMgr()->SetState(new SimulationState(false), 4);
						StateMgr()->ChangeState(4);
					}
				}
				if (i == 14)
					StateMgr()->ChangeState(2);
			}

		}
	}
	SetPrevMouseDown();
}

void ProblemState::OnDestroy() {

}