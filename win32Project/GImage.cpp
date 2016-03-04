#include "GImage.h"
#include "GRenderer.h"

//#include <atlconv.h>

GImage::GImage(GRenderer * renderer, const char * filename)
{
	//USES_CONVERSION;

	D3DXIMAGE_INFO info;
	D3DXGetImageInfoFromFileA(filename, &info);	//이미지 정보를 저장
	D3DXCreateTextureFromFileExA(renderer->getDevice(), filename, info.Width, info.Height, 1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED, -1, -1, 0xffff00ff, &info, NULL, &texture);
	width = info.Width;
	height = info.Height;
}


GImage::~GImage()
{
	texture->Release();
}
