#include "GRenderer.h"
#include "GImage.h"

GRenderer::GRenderer(GWindow * window)
{
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS pp = { 0, };
	pp.BackBufferWidth = 1366;
	pp.BackBufferHeight = 768;
	pp.BackBufferFormat = D3DFMT_A8R8G8B8;			//Alpha, Red, Green, Blue 8bit
	pp.BackBufferCount = 1;
	pp.EnableAutoDepthStencil = true;
	pp.AutoDepthStencilFormat = D3DFMT_D24S8;		//Depth 24bit, Stencil 8bit
	pp.hDeviceWindow = window->getWindowHandle();	//window handle
	pp.Windowed = true;								//window Mode?
	pp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	pp.PresentationInterval = D3DPRESENT_INTERVAL_ONE;

	/*
	 *	d3d 디바이스를 생성
	 *  생성 실패시 에러 발생
	 */
	if (FAILED(d3d9->CreateDevice(0, D3DDEVTYPE_HAL, window->getWindowHandle(), D3DCREATE_HARDWARE_VERTEXPROCESSING, &pp, &d3dDevice)))
		if (FAILED(d3d9->CreateDevice(0, D3DDEVTYPE_HAL, window->getWindowHandle(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &d3dDevice)))
			if (FAILED(d3d9->CreateDevice(0, D3DDEVTYPE_REF, window->getWindowHandle(), D3DCREATE_SOFTWARE_VERTEXPROCESSING, &pp, &d3dDevice)))
				throw 0;

	D3DXCreateSprite(d3dDevice, &d3dSprite);
}


GRenderer::~GRenderer()
{
	d3dSprite->Release();
	d3dDevice->Release();
	d3d9->Release();
}

void GRenderer::Clear(){
	d3dDevice->Clear(1, NULL, D3DCLEAR_TARGET, 0xffffffff, 1, 0);
}

void GRenderer::Present(){
	d3dDevice->Present(NULL, NULL, NULL, NULL);
}

void GRenderer::Draw(GImage * image, int x, int y){
	d3dSprite->Draw(image->getTexture(), NULL, NULL, &D3DXVECTOR3(x, y, 0), 0xfffffffff);
}

IDirect3DDevice9 * GRenderer::getDevice(){
	return d3dDevice;
}

void GRenderer::Begin(){
	d3dDevice->BeginScene();
	d3dSprite->Begin(D3DXSPRITE_ALPHABLEND);
}

void GRenderer::End(){
	d3dSprite->End();
	d3dDevice->EndScene();
}