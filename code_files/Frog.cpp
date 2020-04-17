
#include "frog.h"
#include <iostream>
using namespace std;

Frog::Frog()
{

}
Frog::Frog(LTexture* image, float x, float y): Unit(image, x,y)
{

     //Frame 0
    spriteClips[ 0 ].x =  29;                  //frog on ground
    spriteClips[ 0 ].y =   372;
    spriteClips[ 0 ].w = 92;
    spriteClips[ 0 ].h = 67;

    //Frame 2
    spriteClips[ 2 ].x = 459;                   //flying frog
    spriteClips[ 2 ].y = 327;
    spriteClips[ 2 ].w = 117;
    spriteClips[ 2 ].h = 73;


    //this->x = x;
    //this->y = y;

    if (y >= screenheight-106)                    //if on ground
    {
        this->width = spriteClips[ 0 ].w;
        this->height = spriteClips[ 0 ].h;
    }
    else if (y < screenheight-106)                 //if above ground
    {
        this->width = spriteClips[ 2 ].w;
        this->height = spriteClips[ 2 ].h;
    }

    mcollider.x=x;
    mcollider.y=y;
    mcollider.w=width;
    mcollider.h=height;
    inx=x;
    type=0;
    score=0;
    //health=20;


}
Frog ::~Frog()
{
    cout<<"Frog destructor called"<<endl;
    spriteSheetTexture==NULL;
    delete tongue;                                            //deallocates memory
    tongue=NULL;
}
void Frog::Move()                                             //moves frog
{
   speedx = speedx * friction;
    speedy = speedy * friction;
    x = x + speedx;
    mcollider.x= x;

    y = y + speedy;
    mcollider.y=y;

    speedy+= acceleration;



    if (y >= screenheight-67)                                    //if on ground speedy =0
    {
        speedy=0;
    }
}

void Frog::Move(int direction)                                 //moves frog forward, backward, or upward
{

    if(direction==LEFT)                                     //moves left
    {
        condition = false;
        speedy = -15;
        y+=speedy;
        mcollider.y = y;
        speedx=-15;
        x+=speedx;
        mcollider.x=x;
    }

    if(direction==RIGHT)                                    //moves right
    {
        condition = true;

            speedx=15;
            x+=speedx;
            mcollider.x=x;
            speedy = -15;
            y+=speedy;
            mcollider.y = y;
    }
    if (direction==UP)                                     //moves up
    {
        condition = true;
        speedx=15;
        x+=speedx;
        mcollider.x=x;
        speedy = -30;
        y+=speedy;
        mcollider.y = y;
    }

}
void Frog::jump(int s)                                          //jumps on ground
{
    condition = true;
     speedy = s;
     y+=speedy;
     mcollider.y = y;
}


void Frog::Render(long int& frame, SDL_Renderer* gRenderer)
{

    if (y >= screenheight-67)                                            //if on ground
    {

        this->width = spriteClips[ 0 ].w;
        this->height = spriteClips[ 0 ].h;
        mcollider.w=width;
        mcollider.h=height;


        if (condition == true)                                           //right position
        {
            spriteSheetTexture->Render( x , y , &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
            tongue->setxy(x+ width-5, y+ 16);
            tongue->Move(condition);
            tongue->Render(gRenderer);


        }
        else                                                            //left position
        {
            spriteSheetTexture->Render( x , y , &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );

        }

    }
    else if (y < screenheight-67)                                      //above ground
    {
        this->width = spriteClips[ 2 ].w;
        this->height = spriteClips[ 2 ].h;
        mcollider.w=width;
        mcollider.h=height;


        if (condition == true)                                          //right position
        {

            spriteSheetTexture->Render( x , y , &spriteClips[ 2 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

            tongue->setxy(x+ width-5, y+ 20);
            tongue->Move(condition);
            tongue->Render(gRenderer);

        }
        else                                                            //left position
        {
            spriteSheetTexture->Render( x , y , &spriteClips[ 2 ], 0.0, NULL, SDL_FLIP_HORIZONTAL, gRenderer );
        }

    }

}
void Frog :: tongueMove()                       //moves tongue
{
    if (tongue->getwidth()<=0)
    {

         tongue->Move(20);
    }
}

void Frog:: gettongue(LTexture* tongueimage)   //initializes tongue
{
    tongue = new Tongue(tongueimage, x+ width-5, y+16);
}

int Frog::getscore()                          //return score
{
    return score;
}
void Frog::addscore()                          //adds score
{
    score++;

}
SDL_Rect Frog :: returnt()                    //returns tongues mcollider
{
    return tongue->getrect();
}
void Frog::setscore(int s)
{
    this->score= s;
}
void Frog::seth(int h)
{
    this->health= h;
}
