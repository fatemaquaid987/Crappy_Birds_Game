#pragma once
#include"Node.h"
#include <SDL_mixer.h>

class Queue
{
private:
    Node* head;
    Node* tail;
    bool play;
    bool collide;
public:
    Queue();
    ~Queue();
    void Enqueue(Unit*);
    void Update(long int& frame, SDL_Renderer* gRenderer, Unit*);
    void Hit(Unit*, Mix_Chunk*, Mix_Chunk* );
    bool collision(SDL_Rect a, SDL_Rect b);
    void Movex(int speedx);
    void SaveGame(FILE* fw);
    void switchcollision(bool);
    //void Dodge();
};

