#include <iostream>
#include "Won_Screen.h"


Won::Won()
{

}

Won::~Won()
{
	spriteSheetTexture = NULL;
}

Won::Won(float x, float y, SDL_Renderer* gRenderer,bool* quit) : Screen(&won, x, y)
{
	spriteClips[0].x = 0;
	spriteClips[0].y = 0;
	spriteClips[0].w = 1024;
	spriteClips[0].h = 700;

	delay = 0;
	// loading won screen
	if (!won.LoadFromFile("Images/WON.png", gRenderer))
	{
		printf("Failed to load WON Image");
		*quit = true;
	}
}

void Won::timer(bool* time)
{
	delay += 1;
	if (delay == 100)
	{
		*time = true;
	}
}
void Won::setDelay()
{
    delay=0;
}
