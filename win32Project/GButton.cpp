#include "GButton.h"
#include "GImage.h"
#include "GWindow.h"

bool mouseBtnDown[3] = { 0, };

GButton::GButton(GImage * image, int x, int y)
{
	this->image = image;
	m_rect = (RECT*)malloc(sizeof(RECT));
	m_rect->left = x;
	m_rect->right = x + image->getWidth();
	m_rect->top = y;
	m_rect->bottom = y + image->getHeight();
}

GButton::GButton(GImage * image, RECT * rect) {
	this->image = image;
	m_rect = rect;
}

GButton::~GButton()
{
	free(m_rect);
}

void GButton::setR(RECT * rect) {
	m_rect = rect;
}

RECT * GButton::getR()
{
	return m_rect;
}

bool GButton::getClick()
{
	if (GetMouseX() > m_rect->left && GetMouseX() < m_rect->right) {
		if (GetMouseY() < m_rect->bottom && GetMouseY() > m_rect->top) {
			return true;
		}
	}
	
	return false;
}

bool GButton::getOn()
{
	if (GetMouseX() > m_rect->left && GetMouseX() < m_rect->right) {
		if (GetMouseY() < m_rect->bottom && GetMouseY() > m_rect->top) {
				return true;
		}
	}
	return false;
}

void GButton::setImage(GImage * image) {
	this->image = image;
}

GImage * GButton::getImage() {
	return this->image;
}