#pragma once
#define STATE_NUM 6 //STATE의 최대 개수를 여기서 지정
#define NOT_SET_STATE -1
#define LOGO_STATE 0	//set LogoState
#define GENRE_SCENE 1
#define ACTION_STAGE 2	//액션 스테이지를 선택했을 때
#define BARRAGEACTION_STAGE 3	//탄막 스테이지를 선택했을 때
#define STAGE_STATE 4 //set StageStage
#define PROBLEM_STATE 5	//set ProblemState

/* 
 * 제발 위 선언부에 state 추가하고, STATE_NUM 수정했으면, StateMgr Intialize부분에서 State 객체 하나씩 할당하세요.
 * 선언만 추가하고 빌드하면 오류납니다.
 * 그리고 자꾸 for문 비교식에 <= 쓰시는분 있는데, 쓰시는건 상관없는데 오버플로우만 안일어나게 해주세요 제발
 * 쓴 사람이야 어디가 문젠지 금방 찾아도, 다른사람이 찾으려면 코드에 중단점 몇개씩 걸고 일일히 다 뒤져야합니다.
 */

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

