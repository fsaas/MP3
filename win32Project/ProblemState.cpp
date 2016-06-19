#include "ProblemState.h"
#include "mainProc.h"

#define BImage new GImage(Renderer(),"./Resource/ProblemImg/TempImage.bmp")

ProblemState::ProblemState() : GState()
{
	time = 0;
	this->ClickCool = 10;
	this->Click = true;
	this->stageNum = -1;
	this->bgImage = new GImage(Renderer(), "./Resource/LogoState.bmp");
	int x, y;
	char temp[100];
	for (int i = 0; i < 13; i++) {
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
	}
}

void ProblemState::setButtonImage() {
	for (int i = 0; i < 4; i++) {
		if (this->Uanswer[i] == -1)
			this->NButtons[i + 8]->setImage(new GImage(Renderer(), "./Resource/ProblemImg/TempImage.bmp"));
		else
			this->NButtons[i + 8]->setImage(this->NButtons[this->Uanswer[i]]->getImage());
	}
}

ProblemState::~ProblemState()
{
	for (int i = 0; i < 13; i++) {
		if (this->NButtons[i] != nullptr) delete NButtons[i];
	}

}

void ProblemState::OnInitialize() {

}

void ProblemState::OnDraw() {
	Renderer()->Draw(bgImage, 0, 0);
	for (int i = 0; i < 13; i++) {
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
	for (int i = 0; i < 13; i++) {
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
		for (int i = 0; i < 13; i++) {
			if (NButtons[i]->getClick()) {
				if (i < 8) {
					this->insertAnswer(i);
				}
				if (i > 7 && i < 12) {
					this->deleteAnswer(i);
				}
				if (i == 12)
					this->refresh();
			}

		}
	}
}

void ProblemState::OnDestroy() {

}