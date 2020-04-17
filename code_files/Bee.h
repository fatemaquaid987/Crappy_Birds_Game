
#include <iostream>
#pragma once
#include "Enemy.h"
#include "LTexture.h"
#include "Point.h"
#include "Frog.h"

class Bee:public Enemy
{
private:
    Unit* target=NULL;

public:
    Bee();
    Bee(LTexture* image, float, float);
    ~Bee();
    void setTarget(Unit*);
    void Move();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void movey();
};
