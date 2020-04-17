#include "Cactus.h"
using namespace std;

Cactus::Cactus(LTexture* image,float a, float b):Obstacle(image,a, b)
{
    cout<<"Cactus custom constructor"<<endl;

    spriteClips[ 0 ].x = 43;
    spriteClips[ 0 ].y = 0;
    spriteClips[ 0 ].w = 96;
    spriteClips[ 0 ].h = 171;

    //this->x = a;
    //this->y = b;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    mcollider.x =x;
    cout<<mcollider.x<<endl;

    mcollider.y=y;
    cout<< mcollider.y;

    mcollider.w=width;
    mcollider.h= height;

type=5;

}
