#include "Unit.h"
#include <iostream>
using namespace std;


Unit::Unit()
{

}

Unit::Unit(LTexture* image, float x, float y)
{
    spriteSheetTexture = image;
    condition= true;

    this->x = x;
    this->y = y;

    this->width = spriteClips[ 0 ].w;
    this->height = spriteClips[ 0 ].h;


    friction = 0.95f;
    speedx = 0;
    speedy = 0;
    alive  = true;
    eat=false;
    rotation=0;
    acceleration = 0.5;
    health=20;
    condition = true;
    j=0;



}


Unit::~Unit()
{
    spriteSheetTexture = NULL;
    cout<<"unit destructor called"<<endl;
}

void Unit::SetAlive(bool alive)
{
    this->alive = alive;
}

bool Unit::GetAlive()
{
    return alive;
}

Unit* Unit::generatePowerup()
{
    return NULL;
}

void Unit::Move(int direction)
{

}

void Unit::Move()
{

}

void Unit:: setscreenheight(int h)
{
    this->screenheight= h;
}

void Unit::Render(long int& frame, SDL_Renderer* gRenderer)
{

    SDL_SetRenderDrawColor( gRenderer, 0x00, 0xFF, 0x00, 0xFF );
    SDL_RenderDrawRect( gRenderer, &mcollider );
}

int Unit ::getx()
{
    return x;
}
int Unit::gety()
{
    return y;
}
int Unit::gettype()
{
    return type;
}

int Unit :: getwidth()
{
    return width;
}
int Unit:: getheight()
{
    return height;
}
void Unit::shift(int speed)
{
    this->speedx = speed;
    x +=speedx;
    mcollider.x=x;
}

void Unit:: sethealth(int a, Mix_Chunk* geat)
{
    health+=a;
    cout<< "health is: "<< health<<endl;
    Mix_PlayChannel( -1, geat, 0 );
}
SDL_Rect Unit::getrect()
{
    return mcollider;
}
int Unit::gethealth()
{
    return health;
}

void Unit::changeX(int)
{

}

void Unit::tongueMove()
{

}
void Unit::gettongue(LTexture* tongueimage)
{

}
void Unit::jump(int s)
{

}
SDL_Rect Unit::getTonguerect()
{

}
void Unit::movey()
{

}

Unit* Unit::generateBees()
{

}

bool Unit::getVisibility()
{

}

int Unit::getTongueX()
{

}

int Unit::getTongueWidth()
{

}
void Unit::setTarget(Unit*)
{

}
int Unit::getscore()
{

}
void Unit::addscore()
{

}
SDL_Rect Unit:: returnt()
{
    return mcollider;
}
void Unit::getDestroyed()
{

}
int Unit::getjump()
{
    return j;
}
void Unit::setjump(int j)
{
    this->j= j;
}
bool Unit::getcondition()
{
    return condition;
}
void Unit::setcondition(bool c)
{
    this->condition=c;
}
void Unit:: seteat(bool e)
{
    this->eat= e;
}
bool Unit:: geteat()
{
    return eat;
}
void Unit:: setxy(int x, int y)
{
    this->x=x;
    this->y=y;
}
void Unit::setscore(int s)
{

}
void Unit::seth(int h)
{
    this->health= h;
    cout<<"health"<<endl;
}
