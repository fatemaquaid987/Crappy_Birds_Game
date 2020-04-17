

#include <iostream>
#pragma once
#include "LTexture.h"
#include "Unit.h"



class Enemy:public Unit
{
protected:
    //int width;
    //int height;

public:
    Enemy();
    Enemy(LTexture* image, float, float);
    ~Enemy();
    void Move()=0;
    void Render(long int& frame, SDL_Renderer* gRenderer)=0;
};
