

#include "Tongue.h"

Tongue::Tongue()
{

}
Tongue::~Tongue()
{

}
Tongue::Tongue(LTexture* image, float x, float y):Unit(image, x,y) //inherits from unit
{
     //Frame 0
    spriteClips[ 0 ].x = 895;
    spriteClips[ 0 ].y = 355;
    spriteClips[ 0 ].w = 0;
    spriteClips[ 0 ].h = 10;

    acceleration =-1;
    speedx = 0;
    speedt=0;


}
void Tongue::Move(bool condition)           //moves tongue
{
    this->right= condition;
    if (right == true)                      //only when frog is  facing right
    {
        spriteClips[0].x-=speedt;
        spriteClips[0].w+=speedx;
        speedx+=acceleration;
        speedt+=acceleration;
        mcollider.x=this->x;
        mcollider.y=this->y;
        mcollider.w=spriteClips[0].w;
        mcollider.h=10;

        if (spriteClips[0].w <=0 && spriteClips[0].x>=895)
        {
            speedx=0;
            speedt=0;
            mcollider.w=0;
            mcollider.h=0;
            ton= true;
        }

    }

}
void Tongue::Move(int s)                               //sets speed and starts moving
{
    speedx = s;
    speedt = s;
    mcollider.x=x;
    mcollider.y=y;
    mcollider.h=0;
    mcollider.w=0;

}
void Tongue::Render( SDL_Renderer* gRenderer)
{
    if (right == true)
    {
        spriteSheetTexture->Render( x , y , &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

    }

}
void Tongue :: setxy(int x, int y)
{
    this->x=x;
    this->y=y;
}

int  Tongue::getwidth()
{
    return mcollider.w;
}



