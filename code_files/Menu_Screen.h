#pragma once
#include "Screen.h"
//#include "Button.h"

class Menu: public Screen
{
public:
	Menu();
	Menu(float x, float y,SDL_Renderer* gRenderer,int* type, bool* quit);
	~Menu();
	void draw_buttons(SDL_Renderer* gRenderer);
	int get_inst();
	int get_play();
	int get_resume();
	int get_quit();

private:
	LTexture background;
	Button* play_button;
	Button* resume_button;
	Button* inst_button;
	Button* quit_button;
	int play_start;
	int inst_start;
	int quit_start;
	int resume_start;
	Screen scr;
};

