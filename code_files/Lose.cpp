#include <iostream>
#include "Lose.h"


Lose::Lose()
{

}

Lose::~Lose()
{
	spriteSheetTexture = NULL;
}

Lose::Lose(float x, float y, SDL_Renderer* gRenderer, bool* quit) : Screen(&won, x, y)
{
	spriteClips[0].x = 0;
	spriteClips[0].y = 0;
	spriteClips[0].w = 1024;
	spriteClips[0].h = 700;

	delay = 0;
	// loading won screen
	if (!won.LoadFromFile("Images/lose.png", gRenderer))
	{
		printf("Failed to load Lose Image");
		*quit = true;
	}
}

void Lose::timer(bool* time)
{
	delay += 1;
	if (delay == 100)
	{
		*time =  true;
	}
}
void Lose::setDelay()
{
    delay=0;
}
