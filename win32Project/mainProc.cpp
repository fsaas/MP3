#include <Windows.h>
#include "mainProc.h"
#include "GWindow.h"
#include "GRenderer.h"
#include "GImage.h"
#include "GScene.h"
#include "LogoState.h"
//global variables
GRenderer * g_Renderer;
//Scene Class
class MyScene : public GScene
{
	LogoState* Logo;
public:
	/*
	 * Override functions
	 */
	void OnInitialize()
	{
		Logo = new LogoState(new GImage(g_Renderer, "LogoState.bmp"));
		Logo->OnInitialize(g_Renderer);
	}

	void OnDestroy()
	{
	}

	void OnDraw()
	{
		g_Renderer->Clear();
		g_Renderer->Begin();
		Logo->OnDraw(g_Renderer);
		g_Renderer->End();
		g_Renderer->Present();
	}

	void OnUpdate()
	{
		Logo->OnUpdate();
	}

};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE , LPSTR , int )
{
	MyScene scene;
	GWindow window(&scene);
	GRenderer renderer(&window);
	g_Renderer = &renderer;

	window.messagePump();
	
	return 0;
	
}