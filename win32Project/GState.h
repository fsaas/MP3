#pragma once
class GState
{
public:
	GState();
	~GState();

public:
	virtual void OnInitialize();
	virtual void OnUpdate(float dt);
	virtual void OnDraw();
	virtual void OnDestroy();
};

