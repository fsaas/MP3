#include "mainProc.h"
#include "GRenderer.h"
#include "GState.h"
#include "GStateManager.h"
#include "LogoState.h"
#include "StageState.h"
#include "GenreSelect.h"
#include "ProblemState.h"


GStateManager::GStateManager()
{
	ZeroMemory(m_states, sizeof(m_states));
}


GStateManager::~GStateManager()
{

}

void GStateManager::Initialize() {
	m_states[LOGO_STATE] = new LogoState();
	m_states[GENRE_SCENE] = new GenreSelect();
	m_states[PROBLEM_STATE] = new ProblemState();

	currentState = LOGO_STATE;
}

void GStateManager::Destroy() {
	for (int i = 0; i < STATE_NUM; i++) {
		if (m_states[i] != nullptr) {
			m_states[i]->OnDestroy();
			delete m_states[i];
		}
	}
}

void GStateManager::Draw() {
	Renderer()->Clear();
	Renderer()->Begin();
	//TODO: Scene Draw 처리
	if (currentState != NOT_SET_STATE)
		m_states[currentState]->OnDraw();

	Renderer()->End();
	Renderer()->Present();
}

void GStateManager::Update(float dt) {
	//TODO: Scene Update 처리
	if (currentState != NOT_SET_STATE)
		m_states[currentState]->OnUpdate(dt);
}

void GStateManager::ChangeState(int changeStateKey) {
	//TODO: Scene 전환 처리
	m_states[currentState]->OnDestroy();

	currentState = changeStateKey;
}

void GStateManager::SetState(GState * state, int stateNum) {
	//m_states[stateNum]에 state 객체를 저장.
	//기존 객체가 존재할 경우, 기존 객체를 삭제 후 저장
	if (m_states[stateNum] != nullptr) {
		m_states[stateNum]->OnDestroy();
		delete m_states[stateNum];
	}

	m_states[stateNum] = state;
}