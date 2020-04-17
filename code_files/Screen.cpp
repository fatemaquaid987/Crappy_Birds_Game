#include "Screen.h"

Screen::Screen()
{
	x = 0;
	y = 0;
	width = 1024;
	height = 700;

}

Screen::Screen(LTexture* image, float x, float y)
{
	spriteSheetTexture = image;
}

Screen::~Screen()
{
	spriteSheetTexture = NULL;
}

void Screen::Render(SDL_Renderer* gRenderer)
{
	spriteSheetTexture->Render(x, y, &spriteClips[0], 0.0, NULL, SDL_FLIP_NONE, gRenderer);
}

int Screen::get_width()
{
	return width;
}

int Screen::get_height()
{
	return height;
}
