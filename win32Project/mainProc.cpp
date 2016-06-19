#include <Windows.h>
#include "mainProc.h"
#include "GWindow.h"
#include "GImage.h"
#include "GState.h"
#include "LogoState.h"

//global variables
GRenderer * g_Renderer;
GStateManager * g_StateMgr;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE , LPSTR , int )
{	
	g_StateMgr = new GStateManager();
	GWindow window;
	GRenderer renderer(&window);
	g_Renderer = &renderer;

	window.messagePump();
	
	return 0;
	
}

GRenderer * Renderer() {
	return g_Renderer;
}

GStateManager * StateMgr() {
	return g_StateMgr;
}