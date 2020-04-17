
#include <iostream>
#pragma once
#include "Frog.h"
#include "LTexture.h"
#include "Unit.h"

class Health
{
    float x;
    float y;
    float width;
    float height;
    SDL_Rect spriteClips[5];
    LTexture* spriteSheetTexture;

public:
    Health();
    Health(LTexture* image);
    ~Health();
    void Render(long int& frame, SDL_Renderer* gRenderer, Unit*);

};
