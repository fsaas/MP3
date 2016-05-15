#pragma once

#include "GRenderer.h"
#include "GState.h"
#include "GImage.h"
#include "GWindow.h"
#include "GButton.h"

class GenreSelect : public GState
{
private:
	GImage* bgImage;
	GButton* stageButtons[4];

	bool start = false;

public:
	GenreSelect();
	~GenreSelect();

	GImage* getImage() { return bgImage; }
	GImage* getButtonImage(int i) { return stageButtons[i]->getImage(); }

	void OnUpdate(float dt);
	void OnDraw();
	void OnDestroy();
	void OnInitialize();
};

