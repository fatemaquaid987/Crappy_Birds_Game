#include "Obstacle.h"
using namespace std;

Obstacle::Obstacle()
{
    cout<<"Obstacle empty constructor"<<endl;
}

Obstacle::Obstacle(LTexture* image,float x, float y):Unit(image,x, y)
{
    visible= false;
    cout<<"Obstacle custom constructor"<<endl;

}

Obstacle::~Obstacle()
{
    spriteSheetTexture = NULL;
    cout<<"tree destructor"<<endl;
}


void Obstacle:: Move(int x)
{
    speedx=x;
    this->x += speedx;
    mcollider.x=this->x;
    speedx=speedx*friction;

}

void Obstacle::Move()
{
     speedx = speedx * friction;
     this->x += speedx;
     mcollider.x=this->x;
}

void Obstacle::changeX (int x)
{
    this->x+=x;
    mcollider.x=this->x;
}

void Obstacle::setspeedx (int s) { speedx=s; }

void Obstacle::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x, y, &spriteClips[0], rotation, NULL, SDL_FLIP_NONE, gRenderer );


}
