#include <iostream>
#include "Splash_Screen.h"

Splash::Splash()
{

}

Splash::Splash(float x, float y, SDL_Renderer* gRenderer,int* type, bool* quit):Screen(&splash,x,y)
{
	spriteClips[0].x = 0;
	spriteClips[0].y = 0;
	spriteClips[0].w = 1024;
	spriteClips[0].h = 700;

	delay = 0;
	//Loading splash screen
	if (!splash.LoadFromFile("Images/SplashScreen2.png", gRenderer))
	{
		printf("Failed to load Splash Screen!\n");
		*quit = true;
	}
}

Splash::~Splash()
{
	spriteSheetTexture = NULL;
}

void Splash::init(int* type)
{
	delay += 1;
	splash.SetAlpha(5); // setting value of alpha
	if (delay == 120) //delay between splash & menu screen
	{
		*type = 2; // changing type
	}
}
