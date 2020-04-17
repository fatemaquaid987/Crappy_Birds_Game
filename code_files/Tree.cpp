#include "Tree.h"
using namespace std;

Tree::Tree()
{
    cout<<"tree empty constructor"<<endl;
}

Tree::Tree(LTexture* image,float x, float y):Unit(image,x,y)
{
    visible= false;
    cout<<"tree custom constructor"<<endl;

    spriteClips[ 0 ].x = 79;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 436;
    spriteClips[ 0 ].h = 443;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;
    type=7;
}

Tree::~Tree()
{
    spriteSheetTexture = NULL;
    cout<<"tree destructor"<<endl;
}

void Tree:: Move(int x)
{
    speedx=x;
    x += speedx;
    speedx=speedx*friction;
}

void Tree::Move()
{
     speedx = speedx * friction;
     x = x + speedx;
}

void Tree::changeX (int x) { x+=x; }

void Tree::setspeedx (int s) { speedx=s; }

void Tree::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render(x, y - height, &spriteClips[0], rotation, NULL, SDL_FLIP_NONE, gRenderer );

}
