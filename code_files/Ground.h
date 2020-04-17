
#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include "Point.h"
#include "Unit.h"

using namespace std;

class Ground : public Unit
{
public:
    Ground();
    Ground(LTexture* image, float, float);
    ~Ground();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Move(int);

    void changeX(int);

    void Move();

};

