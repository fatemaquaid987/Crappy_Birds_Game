#pragma once
#include "Screen.h"

class Restart: public Screen
{
public:
	Restart();
	Restart(float x, float y, SDL_Renderer* gRenderer, int* type, bool* quit);
	~Restart();
	void draw_buttons(SDL_Renderer* gRenderer);

private:
	LTexture background;
	Button* quit_button;
	Button* play_button;
	int quit_start;
	int play_start;
	Screen scr;
};
