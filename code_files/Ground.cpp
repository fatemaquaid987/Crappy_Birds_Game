#include"Ground.h"

Ground::Ground()
{
    std::cout<<"ground empty constructor"<<std::endl;
}
Ground::Ground(LTexture* image, float x, float y):Unit(image, x,y)
{

    spriteClips[ 0 ].x = 0;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 1600;
    spriteClips[ 0 ].h = 700;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    std::cout<<"ground custom constructor"<<std::endl;
    type=6;
}

Ground::~Ground()
{
    spriteSheetTexture = NULL;
    std::cout<<"ground destructor"<<std::endl;
}


void Ground:: Move(int x)
{
    speedx=x;
    this->x += speedx;
    speedx=speedx*friction;
    //pos.x -= x;
}

void Ground::Move()
{
     speedx = speedx * friction;
     x = x + speedx;
}

void Ground:: changeX(int x)
{
    this->x+=x;
}

void Ground::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x, y - height, &spriteClips[0], rotation, NULL, SDL_FLIP_NONE, gRenderer );
}


