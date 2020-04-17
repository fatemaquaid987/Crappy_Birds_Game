#include "Healthbar.h"
#include <iostream>
using namespace std;

Health::Health()
{

}
Health::Health(LTexture* image)
{

            spriteSheetTexture=image;


            spriteClips[0].x=0;
            spriteClips[0].y=0;
            spriteClips[0].w=29;
            spriteClips[0].h=29;

            spriteClips[1].x=0;
            spriteClips[1].y=0;
            spriteClips[1].w=29;
            spriteClips[1].h=29;

            spriteClips[2].x=0;
            spriteClips[2].y=0;
            spriteClips[2].w=29;
            spriteClips[2].h=29;

            spriteClips[3].x=0;
            spriteClips[3].y=0;
            spriteClips[3].w=29;
            spriteClips[3].h=29;

            spriteClips[4].x=0;
            spriteClips[4].y=0;
            spriteClips[4].w=29;
            spriteClips[4].h=29;




}
Health::~Health()
{
    cout<<"health destructor called"<<endl;
    spriteSheetTexture=NULL;
    //delete frog;
}
void Health ::Render(long int& frame, SDL_Renderer* gRenderer, Unit* frog)
{
     if ((frog->gethealth()<=20) && (frog->gethealth()>16))    //if health is less than 16
                {
                    spriteSheetTexture->Render(5,5, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    spriteSheetTexture->Render(35,5, &spriteClips[ 1 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    spriteSheetTexture->Render(65,5, &spriteClips[ 2 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    spriteSheetTexture->Render(95,5, &spriteClips[ 3 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    spriteSheetTexture->Render(125,5, &spriteClips[ 4 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                }
                if ((frog->gethealth()<= 16) && (frog->gethealth() > 12))  //if health is greater than 16, less than 12
                {
                    spriteSheetTexture->Render(5,5, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                spriteSheetTexture->Render(35,5, &spriteClips[ 1 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                spriteSheetTexture->Render(65,5, &spriteClips[ 2 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                spriteSheetTexture->Render(95,5, &spriteClips[ 3 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                }
                if ((frog->gethealth()<= 12)&&(frog->gethealth() > 8))   //if health is greater than 12, less than 8
                {
                    spriteSheetTexture->Render(5,5, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    spriteSheetTexture->Render(35,5, &spriteClips[ 1 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    spriteSheetTexture->Render(65,5, &spriteClips[ 2 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                }
                if ((frog->gethealth()<= 8)&&(frog->gethealth() > 4))   //if health is greater than 8, less than 4
                {
                    spriteSheetTexture->Render(5,5, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                    spriteSheetTexture->Render(35,5, &spriteClips[ 1 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );

                }
                if ((frog->gethealth()<= 4)&&(frog->gethealth() > 0))  //if health is greater than 4, greater than  zero
                {
                    spriteSheetTexture->Render(5,5, &spriteClips[ 0 ], 0.0, NULL, SDL_FLIP_NONE, gRenderer );
                }
                if (frog->gethealth()<=0)                              //if health is less than equal to zero
                {
                    cout<<"game over"<<endl;
                    frog->SetAlive(false);                              //frog is not alive
                }

}
