
#pragma once
#include "Point.h"
#include "LTexture.h"
#include "Unit.h"
#include "Tongue.h"


class Frog : public Unit
{
    Tongue * tongue;
    float inx;
    int score;
    //bool die;

public:
    Frog();
    Frog(LTexture* image, float, float);
    ~Frog();
    void Move(int direction);
    void Move();
    void Render(long int& frame, SDL_Renderer* gRenderer);
    void tongueMove();
    void gettongue(LTexture*tongueimage);
    SDL_Rect returnt();
    void jump(int);
    int getscore();
    void addscore();
    void setscore(int);
    void seth(int h);




};

