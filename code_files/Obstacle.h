#pragma once
#include "Unit.h"
#include "SDL.h"

using namespace std;

class Obstacle:public Unit
{
protected:
    bool visible;

public:
	Obstacle();
	Obstacle(LTexture*,float, float);
    ~Obstacle();
    void Move(int);
    void Move();
    void changeX(int);
    void setspeedx(int);
    void Render(long int&, SDL_Renderer*);
};
