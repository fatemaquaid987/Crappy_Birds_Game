#pragma once
#include "LTexture.h"
#include "Button.h"

class Screen: public Button
{
protected:
	float x;
	float y;
	int width;
	int height;
	SDL_Rect spriteClips[1];
	LTexture* spriteSheetTexture;
	LTexture button;
public:
	Screen(LTexture* image, float x, float y);
	Screen();
	virtual ~Screen();
	virtual void Render(SDL_Renderer* gRenderer);
	int get_width();
	int get_height();

};

