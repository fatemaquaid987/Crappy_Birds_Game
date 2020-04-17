
#pragma once
#include"LTexture.h"
#include"Point.h"

class Character
{

private:

	LTexture* image;
	Point pos;
	int starting;
	SDL_Rect spriteClips;
	LTexture* spriteSheetTexture;

public:

	Character();
	Character(LTexture*, float, float, int);
	~Character();
	void Render(SDL_Renderer* gRenderer);
};
