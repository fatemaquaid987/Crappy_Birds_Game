#include "Thorn.h"
using namespace std;

Thorn::Thorn(LTexture* image,float x, float y):Obstacle(image,x, y)
{
    cout<<"Thorn custom constructor"<<endl;

    spriteClips[ 0 ].x = 37;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 132;
    spriteClips[ 0 ].h = 117;
    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    //this->x = x;
    //this->y = y;
    mcollider.x = x;
    mcollider.y= y;
    mcollider.w=width;
    mcollider.h=height;

    type=3;

}


