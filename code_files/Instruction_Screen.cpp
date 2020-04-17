#include <iostream>
#include "Instruction_Screen.h"

Instructions::Instructions()
{

}

Instructions::Instructions(float x, float y, SDL_Renderer* gRenderer, bool* quit) :Screen(&instruc, x, y)
{
	spriteClips[0].x = 0;
	spriteClips[0].y = 0;
	spriteClips[0].w = 1024;
	spriteClips[0].h = 700;

	if (!button.LoadFromFile("Images/fontSprite.png", gRenderer))
	{
		printf("Failed to load Font Sprite!\n");
		*quit = true;
	}
	// loading instruction
	if (!instruc.LoadFromFile("Images/inst.png", gRenderer))
	{
		printf("Failed to load Instructions!\n");
		*quit = false;
	}
	if (*quit == false)
	{
		back_start = ((scr.get_width() / 2) - scr.get_length("BACK") / 2);
		back = new Button(&button, back_start, 617, "BACK");
	}
}

Instructions::~Instructions()
{
	spriteSheetTexture = NULL;
	delete back;
	back = NULL;
}

void Instructions::draw_button(SDL_Renderer* gRenderer)
{
	back->Render(gRenderer);
}

int Instructions::get_back()
{
	return back_start;
}
