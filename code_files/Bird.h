
#include <iostream>
#pragma once
#include "Enemy.h"
#include "Fruit.h"
#include "Rock.h"
#include "LTexture.h"

class Bird:public Enemy
{
    LTexture* fruitimage;
    bool powerupGenerated;

public:
    Bird();
    Bird(LTexture* image, LTexture* fruitimage, float, float);
    virtual ~Bird();
    void Move();
    Unit* generatePowerup();
    void Render(long int& frame, SDL_Renderer* gRenderer);

};






