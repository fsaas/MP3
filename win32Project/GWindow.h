#pragma once

#include <Windows.h>

#include "GState.h"

bool IsKeyDown(BYTE key);
int GetMouseX();
int GetMouseY();
bool IsMouseDown(int mouseButton);

class GWindow
{
private:
	HWND hWnd;
	GState * scene;
	WNDCLASS WndClass;
public:
	GWindow(GState * scene);
	~GWindow();
	WNDCLASS getWndC() { return WndClass; }

public:
	void messagePump();
private:
	static LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam);

public:
	HWND getWindowHandle();

};
