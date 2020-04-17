#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include"LTexture.h"
#include <SDL_mixer.h>


using namespace std;


enum MOTION {RIGHT, LEFT, UP, DOWN};

class Unit
{
    protected:
        bool alive;
        float x;
        float y;
        float speedx;
        float speedy;
        int width;
        int height;
        float friction; //lower speed means more friction
        int type;
        bool condition;
        int rotation;
        float acceleration;
        int screenheight;
        int health;
        bool die;
        int j;
        bool eat;

        enum ANIMATION_FRAMES {FLYING_FRAMES = 9};
        SDL_Rect spriteClips[ FLYING_FRAMES ];
        LTexture* spriteSheetTexture;
        SDL_Rect mcollider;

    public:
        Unit(LTexture* image, float x, float y);
        Unit();
        virtual ~Unit();
        virtual void Render(long int& frame, SDL_Renderer* gRenderer);
        virtual void Move(int);
        void setscreenheight(int);
        virtual void Move();
        void SetAlive(bool alive);
        bool GetAlive();
        int getx();
        virtual void jump(int);
        int gety();
        int getwidth();
        int getheight();
        void sethealth(int, Mix_Chunk*);
        int gethealth();
        int gettype();
        SDL_Rect getrect();
        virtual void changeX(int);
        void shift(int);
        virtual void tongueMove();
        virtual void gettongue(LTexture*tongueimage);
        virtual Unit* generatePowerup();
        virtual SDL_Rect getTonguerect();
        virtual int getTongueX();
        virtual bool getVisibility();
        virtual Unit* generateBees();
        virtual int getTongueWidth();
        virtual void setTarget(Unit*);
        virtual int getscore();
        virtual void addscore();
        virtual SDL_Rect returnt();
        virtual void getDestroyed();
        int getjump();
        void setjump(int j);
        bool getcondition();
        virtual void movey();
        void setcondition(bool);
        void seteat(bool e);
        bool geteat();
        void setxy(int x, int y);
        virtual void setscore(int);
        void seth(int h);





};
