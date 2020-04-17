#pragma once
#include "Word.h"

class Button
{
private:
	int width;
	int height;
	int word_size;
	int button_length;
	Word* select;
	Point pos;
	SDL_Rect starting_button;
	SDL_Rect end_button;
	SDL_Rect mid_button;
	LTexture* spriteSheetTexture;

public:
	Button();
	Button(LTexture*, float, float, string word);
	~Button();
	void Render(SDL_Renderer* gRenderer);
	int get_length(string word);
};


