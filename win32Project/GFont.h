#pragma once
#include <d3d9.h>
#include <d3dx9.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

class GFont
{
private:
	ID3DXFont * m_font;
public:
	GFont(char * fontname, int size);
	~GFont();

	ID3DXFont * GetFont();
};

