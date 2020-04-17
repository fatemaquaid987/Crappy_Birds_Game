
#pragma once
#include "Powerup.h"

class Rock: public Powerup
{public:

    Rock();
    Rock(LTexture* image, float, float);
    ~Rock();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Move();
};

