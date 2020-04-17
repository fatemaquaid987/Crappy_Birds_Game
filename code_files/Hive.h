#include <iostream>
#pragma once
#include "Enemy.h"

#include "Unit.h"
#include "Bee.h"

class Hive:public Unit
{
private:
    int destroyStage;
    bool visible;
    Unit* target;
    int chance;
public:
    Hive();
    Hive(LTexture* image, float x, float y);
    virtual ~Hive();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void Move();
    bool getVisibility();
    Unit* generateBees();
    void setTarget(Unit*);
    void getDestroyed();
};


