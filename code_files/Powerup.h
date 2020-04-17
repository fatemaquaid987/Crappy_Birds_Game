#pragma once
#include "Unit.h"

class Powerup: public Unit
{
public:
    Powerup();
    Powerup(LTexture* image, float x, float y);
    ~Powerup();
};
