#pragma once

#include <d3d9.h>
#include <d3dx9.h>

class GRenderer;

class GImage
{
private:
	IDirect3DTexture9 * texture;				//텍스쳐를 사용하기 위한 객체

public:
	int width, height;

public:
	GImage(GRenderer * renderer, const char * filename);
	~GImage();

public:
	IDirect3DTexture9 * getTexture(){
		return texture;
	}
};

