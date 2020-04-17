#include "Hive.h"
#include <iostream>
using namespace std;
Hive::Hive()
{
}

Hive::Hive(LTexture* image, float x, float y):Unit(image, x, y)
{
    type=10;

    //Frame 0
    spriteClips[ 0 ].x =  5;
    spriteClips[ 0 ].y =  0;
    spriteClips[ 0 ].w = 76;
    spriteClips[ 0 ].h = 86;

    //Frame 1
    spriteClips[ 1 ].x = 89;
    spriteClips[ 1 ].y =   0;
    spriteClips[ 1 ].w =76;
    spriteClips[ 1 ].h = 86;

    //Frame 2
    spriteClips[ 2 ].x = 187;
    spriteClips[ 2 ].y = 0;
    spriteClips[ 2 ].w = 76;
    spriteClips[ 2 ].h = 86;

    //Frame 3
    spriteClips[ 3 ].x = 285;
    spriteClips[ 3 ].y =   0;
    spriteClips[ 3 ].w = 64;
    spriteClips[ 3 ].h = 84;

    //Frame 4
    spriteClips[ 4 ].x = 375;
    spriteClips[ 4 ].y =   0;
    spriteClips[ 4 ].w = 62;
    spriteClips[ 4 ].h = 60;

    //Frame 5
    spriteClips[ 5 ].x = 465;
    spriteClips[ 5 ].y = 0;
    spriteClips[ 5 ].w = 64;
    spriteClips[ 5 ].h = 60;

    //Frame 5
    spriteClips[ 6 ].x = 551;
    spriteClips[ 6 ].y = 0;
    spriteClips[ 6 ].w = 64;
    spriteClips[ 6 ].h = 60;

    //Frame 6
    spriteClips[ 7 ].x = 793;
    spriteClips[ 7 ].y = 0;
    spriteClips[ 7 ].w = 90;
    spriteClips[ 7 ].h = 96;

    //this->x = x;
    //this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    mcollider.x=x;
    mcollider.y=y;
    mcollider.w=spriteClips[ 2 ].w;
    mcollider.h=spriteClips[ 2 ].h;
    destroyStage=0;
    chance=1;
    visible=false;
}

Hive::~Hive()
{
    spriteSheetTexture = NULL;
    cout<<"hive destructor"<<endl;
}



void Hive::Move()
{
    //getDestroyed();
    speedx = speedx * friction;
    x = x + speedx;
    mcollider.x=x;
    if (x<1024) visible=true;
}



bool Hive::getVisibility()
{
    return visible;
}

void Hive::Render(long int& frame, SDL_Renderer* gRenderer)
{
    chance=chance+1;
    spriteSheetTexture->Render( x, y, &spriteClips[ destroyStage ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

}

void Hive::setTarget(Unit* frog)
{
    std::cout<<"target set"<<target<<"   "<<frog<<std::endl;
    this->target=frog;
}

Unit* Hive::generateBees()
{
    if ((visible==true) && ((chance%50)==0))
    {
        std::cout<<target<<std::endl;
        Unit* bee=new Bee(spriteSheetTexture, x, y+6);
        bee->setTarget(target);
        return bee;
    }
    return NULL;
}
void Hive::getDestroyed()
{

        if (destroyStage>=6)
        {
            alive=false;

        }
        destroyStage=destroyStage+1;


}


