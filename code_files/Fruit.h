
#pragma once
#include "Powerup.h"



class Fruit: public Powerup
{
    int num;
public:

    Fruit();
    Fruit(LTexture* image, float x, float y);
    ~Fruit();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Move();

};
