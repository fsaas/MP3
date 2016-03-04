#pragma once

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

#include "GWindow.h"

class GImage;

class GRenderer
{
private:
	IDirect3D9 * d3d9;
	IDirect3DDevice9 * d3dDevice;				//dx9 디바이스를 생성
	ID3DXSprite * d3dSprite;					//스프라이트를 사용하기 위한 객체

public:
	GRenderer(GWindow * window);
	~GRenderer();

public:
	void Clear();								//화면 초기화
	void Present();								
	void Draw(GImage * image, int x, int y);	//화면 출력

public:
	void Begin();
	void End();

public:
	IDirect3DDevice9 * getDevice();				//D3DDevice 반환
};

