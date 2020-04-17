#pragma once
#include "Unit.h"

using namespace std;

class Tree:public Unit
{
protected:
    bool visible;
public:

	Tree();
	Tree(LTexture*,float, float);
    ~Tree();

    void Move(int);
    void Move();
    void changeX(int);
    void setspeedx(int);
    void Render(long int&, SDL_Renderer*);

};
