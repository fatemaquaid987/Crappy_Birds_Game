#pragma once
#include"Unit.h"
#include "Queue.h"
#include"LTexture.h"
#include"Cactus.h"
#include"Bird.h"
#include"Powerup.h"
#include"Frog.h"
#include"Ground.h"
#include "Unit.h"
#include<SDL_mixer.h>

#include "Fruit.h"

#include"Tree.h"

#include"Hive.h"
#include"Bee.h"
#include"Rock.h"

#include"Thorn.h"


class FileManager
{
public:
    FileManager();
    ~FileManager();

    Unit* LoadFile(Unit*, Unit*, LTexture* b, LTexture* f, LTexture* c, LTexture* t, LTexture* g,Queue& Q);
    void SaveFile( Queue&, Unit*);
    Unit* LoadPlayer(LTexture* f, Mix_Chunk*);
};


