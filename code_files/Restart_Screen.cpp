#include <iostream>
#include "Restart_Screen.h"

Restart::Restart()
{

}

Restart::Restart(float x, float y, SDL_Renderer* gRenderer, int* type, bool* quit):Screen(&background,x,y)
{
	spriteClips[0].x = 0;
	spriteClips[0].y = 0;
	spriteClips[0].w = 1024;
	spriteClips[0].h = 700;

	if (!background.LoadFromFile("Images/background.png", gRenderer))
	{
		printf("Failed to game over screen!\n");
		*quit = true;
	}
	if (!button.LoadFromFile("Images/fontSprite.png", gRenderer))
	{
		printf("Failed to load Font Sprite!\n");
		*quit = true;
	}
	if (*quit == false)
	{
		play_start = ((scr.get_width() / 2) - scr.get_length("NEW GAME")/2); // starting x point of play button
		quit_start = ((scr.get_width() / 2) - scr.get_length("QUIT")/2); // starting x point of quit button
		play_button = new Button(&button, play_start, 269, "NEW GAME");
		quit_button = new Button(&button, quit_start, 617, "QUIT");

	}
}

Restart::~Restart()
{
	spriteSheetTexture = NULL;
	delete quit_button;
	delete play_button;
	quit_button = NULL;
	play_button = NULL;
}

void Restart::draw_buttons(SDL_Renderer* gRenderer)
{
	play_button->Render(gRenderer);
	quit_button->Render(gRenderer);
}
