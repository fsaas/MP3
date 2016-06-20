#pragma once
#define STATE_NUM 4 //STATE의 최대 개수를 여기서 지정
#define NOT_SET_STATE -1
#define LOGO_STATE 0	//set LogoState
#define GENRE_SCENE 1
#define STAGE_STATE 2	//액션 스테이지를 선택했을 때
#define PROBLEM_STATE 3	//set ProblemState

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
	void SetState(GState * state, int stateNum);

private:
	GState * m_states[STATE_NUM];
	int currentState;
};

