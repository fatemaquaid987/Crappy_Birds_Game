
#include"Fruit.h"
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;



Fruit::Fruit()
{

}
Fruit::Fruit(LTexture* image, float x, float y):Powerup(image, x, y)   //inherits from powerup
{
    num= rand()%3;                                                     //to generate 3 random fruits

     //Frame 0
    spriteClips[ 0 ].x = 107;
    spriteClips[ 0 ].y = 148;
    spriteClips[ 0 ].w = 43;
    spriteClips[ 0 ].h = 67;

    spriteClips[ 1 ].x = 225;
    spriteClips[ 1 ].y = 158;
    spriteClips[ 1 ].w = 49;
    spriteClips[ 1 ].h = 54;

    spriteClips[ 2 ].x = 338;
    spriteClips[ 2 ].y = 148;
    spriteClips[ 2 ].w = 76;
    spriteClips[ 2 ].h = 74;


    this->width = spriteClips[ num ].w;
    this->height = spriteClips[ num ].h;

    mcollider.x=x;
    mcollider.y=y;
    mcollider.w=width;
    mcollider.h=height;

    type=1;

}

Fruit::~Fruit()
{
    cout<<"fruit destructor called"<<endl;
}
void Fruit:: Move()                                      //moves fruits
{
    speedy=6;
    y += speedy;
    mcollider.y=y;
    rotation+= 10;

    if (y>700)                                          //if fruit is out of screen
    {
        alive=false;                                    //fruit is dead
    }
}


void Fruit::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x, y , &spriteClips[num], rotation, NULL, SDL_FLIP_NONE, gRenderer );

}




