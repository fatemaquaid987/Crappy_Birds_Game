#pragma once
#include "Screen.h"

class Instructions: public Screen
{
public:
	Instructions();
	Instructions(float x, float y, SDL_Renderer* gRenderer, bool* quit);
	~Instructions();
	void draw_button(SDL_Renderer* gRenderer);
	int get_back();
private:
	int back_start;
	Button* back;
	Screen scr;
	LTexture instruc;

};
