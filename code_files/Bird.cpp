

#include <time.h>
#include <stdlib.h>
#include "Bird.h"

Bird::Bird()
{

}

Bird::Bird(LTexture* image, LTexture* fruitimage, float x, float y):Enemy(image,x, y)
{
    type=4;
    this->fruitimage=fruitimage;
    srand(time(NULL));
    int random=rand()%2;
    if (random==0)
    {
        //Frame 0
        spriteClips[ 0 ].x =  843;
        spriteClips[ 0 ].y =  97;
        spriteClips[ 0 ].w = 156;
        spriteClips[ 0 ].h = 176;

        //Frame 1
        spriteClips[ 1 ].x = 677;
        spriteClips[ 1 ].y = 97;
        spriteClips[ 1 ].w = 156;
        spriteClips[ 1 ].h = 176;

        //Frame 2
        spriteClips[ 2 ].x = 511;
        spriteClips[ 2 ].y = 97;
        spriteClips[ 2 ].w = 156;
        spriteClips[ 2 ].h = 176;

        //Frame 3
        spriteClips[ 3 ].x = 345;
        spriteClips[ 3 ].y =  97;
        spriteClips[ 3 ].w = 156;
        spriteClips[ 3 ].h = 176;

        //Frame 4
        spriteClips[ 4 ].x = 177;
        spriteClips[ 4 ].y =  97;
        spriteClips[ 4 ].w = 156;
        spriteClips[ 4 ].h = 176;

        //Frame 5
        spriteClips[ 5 ].x = 8;
        spriteClips[ 5 ].y = 97;
        spriteClips[ 5 ].w = 156;
        spriteClips[ 5 ].h = 176;

        //Frame 6
        spriteClips[ 6 ].x = 505;
        spriteClips[ 6 ].y = 231;
        spriteClips[ 6 ].w = 156;
        spriteClips[ 6 ].h = 176;

        //Frame 7
        spriteClips[ 7 ].x = 339;
        spriteClips[ 7 ].y = 231;
        spriteClips[ 7 ].w = 156;
        spriteClips[ 7 ].h = 176;

        //Frame 8
        spriteClips[ 8 ].x = 339;
        spriteClips[ 8 ].y = 231;
        spriteClips[ 8 ].w = 156;
        spriteClips[ 8 ].h = 176;
    }
    else
    {
        //Frame 0
        spriteClips[ 0 ].x =  899;
        spriteClips[ 0 ].y =  321;
        spriteClips[ 0 ].w = 100;
        spriteClips[ 0 ].h = 100;

        //Frame 1
        spriteClips[ 1 ].x = 797;
        spriteClips[ 1 ].y = 321;
        spriteClips[ 1 ].w = 100;
        spriteClips[ 1 ].h = 100;

        //Frame 2
        spriteClips[ 2 ].x = 695;
        spriteClips[ 2 ].y = 321;
        spriteClips[ 2 ].w = 100;
        spriteClips[ 2 ].h = 100;

        //Frame 3
        spriteClips[ 3 ].x = 897;
        spriteClips[ 3 ].y =  419;
        spriteClips[ 3 ].w = 100;
        spriteClips[ 3 ].h = 100;

        //Frame 4
        spriteClips[ 4 ].x = 795;
        spriteClips[ 4 ].y =  419;
        spriteClips[ 4 ].w = 100;
        spriteClips[ 4 ].h = 100;

        //Frame 5
        spriteClips[ 5 ].x = 695;
        spriteClips[ 5 ].y = 419;
        spriteClips[ 5 ].w = 100;
        spriteClips[ 5 ].h = 100;

        //Frame 6
        spriteClips[ 6 ].x = 893;
        spriteClips[ 6 ].y = 533;
        spriteClips[ 6 ].w = 100;
        spriteClips[ 6 ].h = 100;

        //Frame 7
        spriteClips[ 7 ].x = 791;
        spriteClips[ 7 ].y = 533;
        spriteClips[ 7 ].w = 100;
        spriteClips[ 7 ].h = 100;

        //Frame 8
        spriteClips[ 8 ].x = 791;
        spriteClips[ 8 ].y = 533;
        spriteClips[ 8 ].w = 100;
        spriteClips[ 8 ].h = 100;

    }

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;

    this->x=x;
    this->y=y;

    mcollider.x=x;
    mcollider.y=y;
    mcollider.w=width;
    mcollider.h=height;

     powerupGenerated= false;



}

Bird::~Bird()
{
    spriteSheetTexture = NULL;
    std::cout<<"bird dequeueed"<<std::endl;

}

void Bird::Move()
{
    speedx = 15;
    x+=speedx;
    if (x>1224) alive=false;
}

Unit* Bird::generatePowerup()
{
    srand(time(NULL));
    int position=(rand()%900)+124;
    //int birdpos=x;
    int choosePowerup=rand()%2;
    if (powerupGenerated==false)
    {
        position=(rand()%1000);
        //birdpos=x;
        if ((position<x) && (position<1000))
        {
            if (choosePowerup==0)
            {
                Rock* rock=new Rock(fruitimage, x, y);
                powerupGenerated=true;
                return rock;
            }
            else
            {
                Fruit* fruit=new Fruit(fruitimage, x, y);
                powerupGenerated=true;
                return fruit;
            }
        }

    }
    return NULL;
}

void Bird::Render(long int& frame, SDL_Renderer* gRenderer)
{
    spriteSheetTexture->Render( x, y, &spriteClips[ frame%FLYING_FRAMES], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
}


