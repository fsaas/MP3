#pragma once
#include "GScene.h"

class LogoState : public GScene
{
public:
	LogoState();
	~LogoState();

public:
	void OnInitialize();
	void OnDestroy();
	void OnDraw();
	void OnUpdate();
};

