#pragma once
#include "Screen.h"

class Won:public Screen
{
public:
	Won();
	Won(float x, float y, SDL_Renderer* gRenderer, bool* quit);
	~Won();
	void timer(bool*);
	void setDelay();
private:
	LTexture won;
	int delay;
};
