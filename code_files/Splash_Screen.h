#pragma once
#include "Screen.h"

class Splash: public Screen
{
public:
	Splash();
	Splash(float x, float y, SDL_Renderer* gRenderer, int* type, bool* quit);
	~Splash();
	void init(int* type);
private:
	LTexture splash;
	int delay;
};

