#pragma once
class GScene
{
public:
	GScene();
	~GScene();

public:
	virtual void OnInitialize();
	virtual void OnUpdate();
	virtual void OnDraw();
	virtual void OnDestroy();
};

