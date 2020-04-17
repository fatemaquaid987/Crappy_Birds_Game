#include "Enemy.h"
#include<iostream>
using namespace std;

Enemy::Enemy()
{

}
Enemy::Enemy(LTexture* image, float x, float y): Unit(image, x, y)
{

}
Enemy::~Enemy()
{
    spriteSheetTexture = NULL;
    cout<<"enemy destructor called"<<endl;
}


