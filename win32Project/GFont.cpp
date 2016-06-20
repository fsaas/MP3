#include "GFont.h"
#include "GRenderer.h"
#include "mainProc.h"

GFont::GFont(char * fontname, int size)
{
	D3DXFONT_DESCA desc; ZeroMemory(&desc, sizeof(desc));
	desc.CharSet = DEFAULT_CHARSET;
	strcpy(desc.FaceName, fontname);
	desc.Width = (int)(size / 1.4);
	desc.Height = (int)(size * 1.4);
	HRESULT hResult = D3DXCreateFontIndirectA(Renderer()->getDevice(), &desc, &m_font);
}


GFont::~GFont()
{
	if (m_font)
		m_font->Release();
	m_font = NULL;
}

ID3DXFont * GFont::GetFont() {
	return m_font;
}