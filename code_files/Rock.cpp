#include"Rock.h"
#include <iostream>
using namespace std;


Rock::Rock()
{

}
Rock::Rock(LTexture* image, float x, float y):Powerup(image, x, y)  //inherits from powerup
{
    spriteClips[ 0 ].x = 584;
    spriteClips[ 0 ].y = 149;
    spriteClips[ 0 ].w = 68;
    spriteClips[ 0 ].h = 72;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    mcollider.x=x;
    mcollider.y=y;
    mcollider.w=width;
    mcollider.h=height;

    type=2;

}

void Rock:: Move()                                        //moves rock
{
    speedy=6;
    y += speedy;
    mcollider.y=y;
    rotation+= 10;
    if (y>700)                                            //if rock is out of screen
    {
        alive=false;                                      //rock is dead
    }
}
Rock::~Rock()
{
    cout<<"Rock destructor called"<<endl;
    spriteSheetTexture=NULL;
}
void Rock::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x, y, &spriteClips[0], rotation, NULL, SDL_FLIP_NONE, gRenderer );

}

