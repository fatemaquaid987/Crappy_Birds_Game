#include <iostream>
#include "Menu_Screen.h"

Menu::Menu()
{

}

Menu::Menu(float x, float y,SDL_Renderer* gRenderer,int* type, bool* quit) :Screen(&background, x, y)
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
	if (!background.LoadFromFile("Images/menu.png",gRenderer))
	{
		printf("Failed to load Menu!\n");
		*quit = true;
	}
	if (*quit == false)
	{
		play_start = ((scr.get_width() / 2) - scr.get_length("NEW GAME")/2); // starting x point of play button
		inst_start = ((scr.get_width() / 2) - scr.get_length("INSTRUCTIONS")/2); // starting x point of instructions button
		quit_start = ((scr.get_width() / 2) - scr.get_length("QUIT")/2); // starting x point of quit button
		resume_start = ((scr.get_width() / 2) - scr.get_length("RESUME")/2); // starting x point of resume button
		play_button = new Button(&button, play_start, 269, "NEW GAME");
		resume_button = new Button(&button, resume_start, 385, "RESUME");
		inst_button = new Button(&button, inst_start, 501, "INSTRUCTIONS");
		quit_button = new Button(&button, quit_start, 617, "QUIT");

	}

}

Menu::~Menu()
{
	spriteSheetTexture = NULL;
	delete play_button;
	delete inst_button;
	delete resume_button;
	delete quit_button;
	play_button = NULL;
	resume_button = NULL;
	inst_button = NULL;
	quit_button = NULL;
}

void Menu::draw_buttons(SDL_Renderer* gRenderer)
{
	play_button->Render(gRenderer);
	inst_button->Render(gRenderer);
	resume_button->Render(gRenderer);
	quit_button->Render(gRenderer);
}

int Menu::get_inst()
{
	return inst_start;
}

int Menu::get_play()
{
	return play_start;
}

int Menu::get_quit()
{
	return quit_start;
}

int Menu::get_resume()
{
	return resume_start;
}
