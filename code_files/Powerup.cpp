
#include "Powerup.h"
#include <iostream>
using namespace std;




Powerup::Powerup()
{

}
Powerup::Powerup(LTexture* image, float x, float y):Unit(image, x, y)  //inherits from unit
{

}
Powerup::~Powerup()
{
    cout<<"powerup destructor called"<<endl;

}



