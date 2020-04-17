#pragma once
#include "Screen.h"

class Lose :public Screen
{
public:
	Lose();
	Lose(float x, float y, SDL_Renderer* gRenderer, bool* quit);
	~Lose();
	void timer(bool*);
	void setDelay();
private:
	LTexture won;
	int delay;
};
