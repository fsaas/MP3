#include "LogoState.h"



LogoState::LogoState(GImage* image)
{
	this->bgImage = image;
}


LogoState::~LogoState()
{
}

void LogoState::OnInitialize(GRenderer* gr) {

}
void LogoState::OnUpdate() {
}
void LogoState::OnDraw(GRenderer* gr) {
	gr->Draw(getImage(), 0, 0);
}
void LogoState::OnDestroy() {
}