#pragma once

#include <d3d9.h>
#include <d3dx9.h>

class GRenderer;

class GImage
{
private:
	IDirect3DTexture9 * texture;				//텍스쳐를 사용하기 위한 객체
	int width, height;							//이미지의 가로, 세로 길이

public:
	GImage(GRenderer * renderer, const char * filename);
	~GImage();

public:
	IDirect3DTexture9 * getTexture(){
		return texture;
	}
	int getWidth() { return width; }
	int getHeight() { return height; }
};

