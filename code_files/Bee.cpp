
#include "Bee.h"
#include "SDL.h"

Bee::Bee()
{

}

Bee::Bee(LTexture* image, float x, float y):Enemy(image,x, y)
{
    type=400;

    //Frame 0
    spriteClips[ 0 ].x =  639;
    spriteClips[ 0 ].y =  0;
    spriteClips[ 0 ].w = 35;
    spriteClips[ 0 ].h = 52;

    //Frame 1
    spriteClips[ 1 ].x = 675;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w = 35;
    spriteClips[ 1 ].h = 52;

    //Frame 2
    spriteClips[ 2 ].x = 800;
    spriteClips[ 2 ].y =   0;
    spriteClips[ 2 ].w = 35;
    spriteClips[ 2 ].h = 52;

    mcollider.x=x;
    mcollider.y=y;
    mcollider.w=spriteClips[ 2 ].w;
    mcollider.h=spriteClips[ 2 ].h;

}

Bee::~Bee()
{
    spriteSheetTexture = NULL;
}
void Bee:: movey()
{
    speedy=8;
    y-=speedy;
}

void Bee::Move()
{

    speedx = 8;
    x-=speedx;
    speedy=8;
    mcollider.x=x;

    if (y==(target->gety()-50))
    {
        y = y - speedy;
        mcollider.y= y;
    }
    if ( x > (target->getx()+100)&&(y<(target->gety()-50)))
    {
        y = y + speedy;
        mcollider.y= y;
    }



}

void Bee::setTarget(Unit* frog)
{
    target=frog;
}


void Bee::Render(long int& frame, SDL_Renderer* gRenderer)
{

    spriteSheetTexture->Render( x, y, &spriteClips[ frame%2 ], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );


}


