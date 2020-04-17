
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Unit.h"
#include "Point.h"

class Tongue:public Unit
{
    bool right;
    float acceleration;
    int screenheight;
    float speedt;
    int inpos;
    bool ton;

public:
    Tongue();
    ~Tongue();
    Tongue(LTexture* image, float, float);
    void Move(bool);
    void Move(int);
    void Render(SDL_Renderer* gRenderer);
    void setxy(int, int);
    int getwidth();
};
