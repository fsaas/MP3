#pragma once

#include <Windows.h>


bool IsKeyDown(BYTE key);
int GetMouseX();
int GetMouseY();
bool IsMouseDown(int mouseButton);

class GStateManager;

class GWindow
{
private:
	HWND hWnd;
	WNDCLASS WndClass;
	GStateManager * m_stateMgr;

public:
	GWindow(GStateManager * stateMgr);
	~GWindow();
	WNDCLASS getWndC() { return WndClass; }

public:
	void messagePump();
private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

public:
	HWND getWindowHandle();

};
