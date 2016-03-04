#include <Windows.h>
#include "mainProc.h"
#include "GWindow.h"
#include "GRenderer.h"
#include "GImage.h"
#include "GScene.h"
//global variables
GRenderer * g_Renderer;
//Scene Class
class MyScene : public GScene{

public:
	/*
	 * Override functions
	 */
	void OnInitialize(){
	}

	void OnDestroy(){
	}

	void OnDraw(){
		g_Renderer->End();
		g_Renderer->Present();
	}

	void OnUpdate() {

	}

};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE , LPSTR , int ){
	MyScene scene;
	GWindow window(&scene);
	GRenderer renderer(&window);
	g_Renderer = &renderer;

	window.messagePump();
	
	return 0;
	
}