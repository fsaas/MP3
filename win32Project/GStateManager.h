#pragma once
#define STATE_NUM 5 //STATE의 최대 개수를 여기서 지정
#define NOT_SET_STATE -1
#define LOGO_STATE 0	//set LogoState
#define GENRE_SCENE 1
#define ACTION_STAGE 2	//액션 스테이지를 선택했을 때
#define BARRAGEACTION_STAGE 3	//탄막 스테이지를 선택했을 때
#define STAGE_STATE 4 //set StageStage


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

