#include "GStateManager.h"
#include "GWindow.h"

bool keyDown[256];
int mouseX, mouseY;
bool mouseButtonDown[3];
bool IsKeyDown(BYTE key){
	return keyDown[key];
}

int GetMouseX(){
	return mouseX;
}

int GetMouseY(){
	return mouseY;
}

bool IsMouseDown(int mouseButton){
	return mouseButtonDown[mouseButton];
}

LRESULT CALLBACK GWindow::WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam){
	HWND hWndButton;
	switch (iMsg){
	case WM_KEYDOWN:
		keyDown[wParam] = true;
		break;
	case WM_KEYUP:
		keyDown[wParam] = false;
		break;
	case WM_LBUTTONDOWN:
		mouseButtonDown[0] = true;
		break;
	case WM_RBUTTONDOWN:
		mouseButtonDown[1] = true;
		break;
	case WM_LBUTTONUP:
		mouseButtonDown[0] = false;
		break;
	case WM_RBUTTONUP:
		mouseButtonDown[1] = false;
		break;
	case WM_MOUSEMOVE:
		mouseX = LOWORD(lParam);
		mouseY = HIWORD(lParam);
		break;
	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hwnd, iMsg, wParam, lParam);
	}
	return 0;
}

GWindow::GWindow(GStateManager * stateMgr)
{
	this->WndClass = {
		0, WndProc, 0, 0, GetModuleHandle( NULL ) , 0, 0, 0, 0, L"MyWindow"
	};
	RegisterClass(&WndClass);
	RECT rect = { 0, 0, 1366, 768 };
	AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

	int width = rect.right - rect.left;
	int height = rect.bottom - rect.top;

	int x = GetSystemMetrics(SM_CXSCREEN) / 2 - width / 2;
	int y = GetSystemMetrics(SM_CYSCREEN) / 2 - height / 2;

	hWnd = CreateWindowEx(0,L"MyWindow", L"Window", WS_OVERLAPPEDWINDOW, x, y, width, height, 0, 0, WndClass.hInstance, 0);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	m_stateMgr = stateMgr;
}


GWindow::~GWindow()
{

}
void GWindow::messagePump(){
	m_stateMgr->Initialize();							//stateManager 초기화

	DWORD lastTick = GetTickCount(), dt = 0;			//타이머 변수 초기화

	MSG msg;

	while (1){
		if (PeekMessage(&msg, 0, 0, 0, PM_NOREMOVE)){
			if (!GetMessage(&msg, 0, 0, 0))
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else{
			DWORD now = GetTickCount();					//현재 시간 설정

			dt = now - lastTick;						//현재 프레임 - 이전 프레임 사이 시간 계산

			m_stateMgr->Update(dt / 10.0f);				//scene 갱신
			m_stateMgr->Draw();							//scene 출력

			lastTick = now;
			Sleep(1);
		}
	}

	m_stateMgr->Destroy();									//scene 객체 제거
}

HWND GWindow::getWindowHandle(){
	return hWnd;
}