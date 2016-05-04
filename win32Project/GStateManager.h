#pragma once
#define STATE_NUM 3 //STATE의 최대 개수를 여기서 지정
#define NOT_SET_STATE -1
#define LOGO_STATE 0	//set LogoState

class GState;

class GStateManager
{
public:
	GStateManager();
	~GStateManager();

public:
	void Initialize();
	void Destroy();
	void Update(float dt);
	void Draw();
	void ChangeState(int changeStateKey);

private:
	GState * m_states[STATE_NUM];
	int currentState;
};

