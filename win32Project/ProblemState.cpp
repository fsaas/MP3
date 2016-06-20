#include "ProblemState.h"
#include "mainProc.h"
#include "SimulationState.h"
#include "Block.h"

#define BImage new GImage(Renderer(),"./Resource/ProblemImg/TempImage.bmp")

ProblemState::ProblemState() : GState()
{
	time = 0;
	this->ClickCool = 10;
	this->Click = false;
	this->stageNum = -1;
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");
	this->tempImage = new GImage(Renderer(), "./Resource/ProblemImg/TempImage.bmp");
	int x, y;
	char temp[100];
	for (int i = 0; i < 15; i++) {
		if (i >= 0 && i <= 7) {
			Blocks[i] = NILL;
			if (i >= 0 && i <= 3) {
				y = 100;
				x = 200 + ((i % 4) * 200);
			}
			if (i >= 4 && i <= 7) {
				y = 250;
				x = 200 + ((i % 4) * 200);
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
			y = 600;
			x = 1200;
			this->NButtons[i] = new GButton(new GImage(Renderer(), "./Resource/Button.png"), x, y);
		}
		if (i == 14) {
			y = 600;
			x = 30;
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

void ProblemState::setAnswer(int answer[4])
{
	for (int i = 0; i = 4; i++) {
		this->answer[i] = answer[i];
	}
}

bool ProblemState::isCorrect()
{
	if (this->Uanswer == this->answer)
		return true;
	return false;
}

void ProblemState::GOpen(char * filename)
{
	std::ifstream inFile(filename);
	char temp[100];
	int tempA[4];
	int i = 0;
	while (!inFile.eof()) {
		inFile.getline(temp, 100);
		if (i < 8) {
			setBlock(atoi(temp), i);
		}
		if (i > 7 && i < 12) {
			tempA[i - 8] = atoi(temp);
		}
		i++;
	}
	setAnswer(tempA);
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
}

void ProblemState::OnInitialize() {

}

void ProblemState::OnDraw() {
	Renderer()->Draw(bgImage, 0, 0);
	for (int i = 0; i < 15; i++) {
		Renderer()->Draw(NButtons[i]->getImage(), NButtons[i]->getR()->left, NButtons[i]->getR()->top);
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
				if (i == 13) {
					this->isCorrect();
					StateMgr()->SetState(new SimulationState(true), 4);
					StateMgr()->ChangeState(4);
				}
				if (i == 14) {
					StateMgr()->ChangeState(2);
				}
			}

		}
	}
	SetPrevMouseDown();
}

void ProblemState::OnDestroy() {

}