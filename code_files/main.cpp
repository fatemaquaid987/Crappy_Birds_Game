#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LTexture.h"
#include "Unit.h"
#include "frog.h"
#include "Point.h"
#include "Powerup.h"
#include "Fruit.h"
#include "Rock.h"
#include "Bird.h"
#include "Enemy.h"
#include "Queue.h"
#include "Ground.h"
#include "Tree.h"
#include "Tongue.h"
#include "Obstacle.h"
#include "Cactus.h"
#include "Thorn.h"
#include "Healthbar.h"
#include "Hive.h"
#include "Bee.h"
#include "Chracter.h"
#include "Word.h"
#include "Filemanager.h"
#include <SDL_mixer.h>
#include "Splash_Screen.h"
#include "Button.h"
#include "Menu_Screen.h"
#include "Instruction_Screen.h"
#include "Won_Screen.h"
#include "Lose.h"
#include "Restart_Screen.h"

Screen scr;


//Pre defined screen width and height
const int SCREEN_WIDTH = scr.get_width();
const int SCREEN_HEIGHT = scr.get_height();

bool init();

bool loadMedia();

void close();

SDL_Window* gWindow = NULL;

SDL_Renderer* gRenderer = NULL;

LTexture gSpriteSheetTexture;                                             //all the sprites defined
LTexture gSpriteSheetTexture2;
LTexture gGroundTexture;
LTexture gTreeTexture;
LTexture gTongue;
LTexture gHealth;
LTexture gCactusTexture;
LTexture gThornTexture;
LTexture gWordTexture;
LTexture gHive;
Mix_Music *gMusic = NULL;                                                 //music and sounds
Mix_Chunk *geffect = NULL;
Mix_Chunk *geat = NULL;


bool init();
bool loadMedia();
void close();

int main( int argc, char* args[] )
{

	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{

			bool quit = false;                      //Main loop flag
			SDL_Event e;                            //Event handler
			long int frame = 0;
			bool load=false;
            /* initialize random seed: */
            srand (time(NULL));



            // store mouse position
			int mouse_x = 0;
			int mouse_y = 0;
			int screens = 1; // to keep check on screen type
			// initiating pointers
			Splash* scr = new Splash(0, 0, gRenderer, &screens, &quit);                 // initiating new screen pointer
			Menu* men = new Menu(0, 0, gRenderer, &screens, &quit);                     // initiating screen pointer for Menu
			Instructions* inst = new Instructions(0, 0,gRenderer,&quit);                // initiating screen pointer for Instructions
			Won* win = new Won(0, 0, gRenderer,&quit);                                  //initializing screen pointer for win screen
			Lose* lose = new Lose(0, 0, gRenderer, &quit);                               //initializing screen pointer for win screen
			Restart* re = new Restart(0,0,gRenderer,&screens,&quit);                     //initializing screen pointer for restart screen

			Queue que;                                                                    //initializing queue
            Unit*ground1= NULL;                                                           //ground 1 pointer
            Unit* ground2= NULL;                                                           //ground 2 pointer
            Unit* bird= NULL;                                                               //bird pointer
            Unit* frog= NULL;                                                               //frog pointer
            Unit* bee= NULL;
            Unit* tree= NULL;                                                              //tree pointer
            Unit* thorn= NULL;                                                              //thorn pointer
            Unit* cactus= NULL;                                                             //cactus pointer
            Unit* hive= NULL;                                                               //hive pointer
            Health health(&gHealth);                                                        //health bar
            char mybuff[50];                                                                //character array for score
            Word* score=NULL ;                                                               //score pointer
            bool once = false;                                                               //to initialize once
            bool time =false;                                                                 //timer
            bool hiveVisible;                                                                 //for hives visibility
            bool restart=false;
            int generateBird =0;
            ground1 = new Ground(&gGroundTexture,-SCREEN_WIDTH, SCREEN_HEIGHT);               //initializing ground
            que.Enqueue(ground1);                                                             //enqueue ground

            ground2 = new Ground(&gGroundTexture,ground1->getwidth()-SCREEN_WIDTH, SCREEN_HEIGHT);
            que.Enqueue(ground2);

            FileManager* FM;                                                                  //pointer for file manager



			while( !quit )                                                                    //While application is running
			{

				if (screens == 1)
				{
					scr->init(&screens);
					scr->Render(gRenderer);                                                  // drawing screen
					SDL_RenderPresent( gRenderer );
				}
				else if ((screens == 2) || (screens == 3))
				{
					if (screens == 2)                                                       //menu screen
					{
						men->Render(gRenderer);                                             // drawing menu screen
						men->draw_buttons(gRenderer);
						SDL_RenderPresent( gRenderer );
					}
					else if (screens == 3)                                                    //instructions screen
					{
						inst->Render(gRenderer);
						inst->draw_button(gRenderer);
						SDL_RenderPresent( gRenderer );
					}
					while (SDL_PollEvent(&e) != 0)
					{
						if (e.type == SDL_QUIT)
						{
							quit = true;
						}
						else
						{
							if ((e.type == SDL_MOUSEMOTION) || (e.type == SDL_MOUSEBUTTONDOWN))      //if mouse button pressed
							{
								if (e.type == SDL_MOUSEBUTTONDOWN)
								{
									SDL_GetMouseState(&mouse_x, &mouse_y);                            // getting position of cursor
									if (screens == 2)                                                 //if menu screen is on
									{
										if ((men->get_inst() < mouse_x) && (mouse_x < (men->get_length("INSTRUCTIONS") + men->get_inst()))) // limit of instruction button
										{
											if ((496 < mouse_y) && (mouse_y < (496 + 52)))
											{
												screens = 3;                                          //display instructions screen
											}
											else if ((men->get_play() < mouse_x) && (mouse_x < (men->get_length("NEW GsME") + men->get_inst())))//limit of play button
											{
												if ((269 < mouse_y) && (mouse_y < (269 + 47)))
												{
													std::cout << "Game" << std::endl;
													screens = 4;                                      //display game screen
												}
												else if ((men->get_resume() < mouse_x) && (mouse_x < (men->get_length("RESUME") + men->get_resume())))//limit of resume button
												{
													if ((385 < mouse_y) && (mouse_y < 385 + 52))
													{
														load = true;                                   //load variable set true
														screens = 4;                                  //display game screen

													}
													else if ((men->get_quit() < mouse_x) && (mouse_x < (men->get_length("QUIT") + men->get_quit())))//limit of quit button
													{
														if ((612 < mouse_y) && (mouse_y < 612 + 52))
														{
															quit = true;                                                  //quits game


														}
													}
												}
											}
										}
									}
									else if (screens == 3)                                                               //instructions screen
									{
										// checking for back button click
										if ((inst->get_back() < mouse_x) && (mouse_x < (242 + inst->get_back())))
										{
											if ((617 < mouse_y) && (mouse_y < 617 + 52))
											{
												screens = 2;                                                            //takes back to menu screen if back button pressed
											}
										}
									}
								}
							}
						}
					}
				}
				if (screens == 4)                                                      //game screen
				{cout<<"screen 4";
				    if (once==false)
                    {   cout<<"restarting";
                        if (restart == false)                                          //if a new game is to start
                        {

                            if(load==true)                                                 //if one wants to resume game
                            {
                                frog=FM->LoadPlayer(&gSpriteSheetTexture, geffect);        //loads players information
                                frog->SetAlive(true);
                                hive=FM->LoadFile(frog, tree,&gSpriteSheetTexture2, &gSpriteSheetTexture,&gCactusTexture, &gThornTexture, &gTreeTexture, que );//loads other objects
                                once = true;                                              //wont initialize again

                            }
                            else                                                          //new game
                            {

                                frog=new Frog(&gSpriteSheetTexture, (SCREEN_WIDTH/2)-46, SCREEN_HEIGHT-67 ); //initializing all the objects and pointers


                                tree = new Tree(&gTreeTexture,17000, SCREEN_HEIGHT);
                                que.Enqueue(tree);

                                thorn = new Thorn(&gThornTexture,15000, SCREEN_HEIGHT-117);
                                que.Enqueue(thorn);

                                cactus = new Cactus(&gCactusTexture,9000, SCREEN_HEIGHT-171);
                                que.Enqueue(cactus);

                                hive = new Hive(&gSpriteSheetTexture2, 17200, 500);
                                que.Enqueue(hive);
                                once = true;

                            }
                            frog->gettongue(&gTongue);                                               //initializes tongue
                            frog->setscreenheight(SCREEN_HEIGHT);

                            score = new Word(&gWordTexture,SCREEN_WIDTH/2,0,itoa(frog->getscore(),mybuff,10));

                            hive->setTarget(frog);
                            hiveVisible=hive->getVisibility();
                           }
                           else if (restart==true)                                              //if game restarted
                           {
                                frame = 0;                                                      //reseting all the attributes

                                frog->setxy((SCREEN_WIDTH/2)-46, SCREEN_HEIGHT-67);
                                frog->Render(frame, gRenderer);
                                frog->SetAlive(true);
                                frog->setjump(0);
                                frog->seth(20);
                                frog->setscreenheight(SCREEN_HEIGHT);
                                frog->setscore(0);
                                tree->setxy(17000, SCREEN_HEIGHT);
                                thorn-> setxy(15000, SCREEN_HEIGHT-117);
                                cactus->setxy(9000, SCREEN_HEIGHT-171);
                                hive->setxy(17200, 500);
                                hive->SetAlive(true);
                                hiveVisible=false;
                                once=true;
                                time =false;
                                lose->setDelay();
                                win->setDelay();

                           }
                    }

                    generateBird=(rand()%70)+55;                                     //to generate bird randomly
				    const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );
				    while (SDL_PollEvent(&e)!= 0)
                    {
                        if (e.type == SDL_QUIT)
                        {
                            quit = true;
                        }
                        if (currentKeyStates[ SDL_SCANCODE_ESCAPE ])
                        {
                            quit = true;
                        }
                        if ((frog->GetAlive()==true) && (hive->GetAlive()))             //if frog and hive are both alive
                        {
                                if ((frog->getx()<hive->getx()-10))                    //if frogs position is less than hive
                                {

                                    if(currentKeyStates[ SDL_SCANCODE_RIGHT ])         //if right key pressed
                                    {
                                            if(frog->getjump()==1)
                                            {
                                                if(frog->gety()>= SCREEN_HEIGHT-67)
                                                {
                                                    frog->Move(RIGHT);                 //jumps towards right
                                                    frog->setjump(0);
                                                }
                                            }
                                            else if (frog->getjump()==0)
                                            {
                                                if(frog->gety()>= SCREEN_HEIGHT-67)
                                                {
                                                    frog->jump(-15);                   //jumps in place

                                                }
                                                que.Movex(-10);                        //but moves other objects in que in the opposite direction

                                            }
                                    }
                                }


                                if(currentKeyStates[ SDL_SCANCODE_LEFT ])               //if left key pressed
                                {

                                    if (frog->getjump()==0)
                                    {
                                        if(frog->gety()>= SCREEN_HEIGHT-67)           //will move left only if frog i in centre
                                        {
                                            frog->Move(LEFT);
                                            frog->setjump(1);
                                            que.Movex(10);
                                        }
                                    }

                                }
                                if ((frog->getx()<hive->getx()-10))
                                {
                                    if(currentKeyStates[ SDL_SCANCODE_UP ])         //up key pressed to jump higher
                                    {
                                        if(frog->getjump()==1)
                                        {
                                            if(frog->gety()>= SCREEN_HEIGHT-67)
                                            {
                                                frog->Move(UP);
                                                frog->setjump(0);
                                            }
                                        }
                                        else if (frog->getjump()==0)
                                        {
                                            if(frog->gety()>= SCREEN_HEIGHT-67)
                                            {
                                                frog->jump(-30);
                                            }
                                            que.Movex(-10);
                                        }

                                    }
                                 }

                                if(currentKeyStates[ SDL_SCANCODE_SPACE ])                //space to get the tongue out
                                {
                                    frog->tongueMove();
                                    que.switchcollision(true);

                                }
                        }
                    }
                    if ((frog->GetAlive()) && (hive->GetAlive()))                   //renders stuff only if frog and hive are both alive
                    {
                        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );    //Clear screen
                        SDL_RenderClear( gRenderer );
                        if ((frame%generateBird)==0)                                    //generates bird
                        {
                            bird=new Bird(&gSpriteSheetTexture2, &gSpriteSheetTexture, -186, (120+rand()%30));
                            que.Enqueue(bird);
                        }
                        if (((frame%300)==0) && (hiveVisible==false))                   //generates bees
                        {
                            bee=new Bee(&gSpriteSheetTexture2, 1025, 350);
                            bee->setTarget(frog);
                            que.Enqueue(bee);

                        }
                        hiveVisible=hive->getVisibility();
                        que.Update(frame,gRenderer, frog);
                        score->Render(gRenderer);
                        frog->Render(frame, gRenderer);
                        frog->Move();
                        health.Render(frame, gRenderer,frog);
                        que.Hit(frog, geffect, geat);
                        if( Mix_PlayingMusic() == 0 )
                        {  //Play the music
                            Mix_PlayMusic( gMusic, -1 );
                        }



                        if (ground1->getx() <= -ground1->getwidth())
                        {
                            ground1->changeX( 2*ground1->getwidth() );
                        }
                        if (ground1->getx() >= SCREEN_WIDTH)
                        {
                            ground1->changeX( -2*ground1->getwidth() );
                        }
                        if (ground2->getx() <= -ground2->getwidth())
                        {
                            ground2->changeX( 2*ground1->getwidth() );
                        }
                        if (ground2->getx() >= SCREEN_WIDTH)
                        {
                            ground2->changeX( -2*ground1->getwidth() );
                        }
                        SDL_RenderPresent( gRenderer );

                        ++frame;                                                      //Go to next frame
                        delete score;
                        score = new Word(&gWordTexture,SCREEN_WIDTH/2,0,itoa(frog->getscore(),mybuff,10));
                    }
                    else if (!frog->GetAlive())                                          //if frog is dead
                    {

                        time=false;
                        screens=7;                                                      //loose screen will be on

                    }
                    else if (!hive->GetAlive())                                        //if hive is dead
                    {

                        time=false;
                        screens=6;                                                     //win screen will be on

                    }
				}
				if(screens ==6)                                                        //win screen
                {
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );     //Clear screen
                    SDL_RenderClear( gRenderer );
                    win->Render(gRenderer);
                    SDL_RenderPresent( gRenderer );
                    win->timer(&time);

                    if(time)
                    {
                        screens = 5;                                                  //restart screen will be on
                    }
                }
                if(screens==7)                                                        //lose screen
                {
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );     //Clear screen
                    SDL_RenderClear( gRenderer );
                    lose->Render(gRenderer);
                    SDL_RenderPresent( gRenderer );
                    cout<<"ajeeb";
                    lose->timer(&time);


                    if(time)
                    {
                        screens = 5;                                                 //restart screen will be on
                    }
                }
				if (screens==5)                                                     //restart screen
                {
                    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );     //Clear screen
                    SDL_RenderClear( gRenderer );
                    re->Render(gRenderer);
                    re->draw_buttons(gRenderer);
                    SDL_RenderPresent( gRenderer );

                     while (SDL_PollEvent(&e)!=0)
                     {
                        if ((e.type == SDL_MOUSEMOTION) || (e.type == SDL_MOUSEBUTTONDOWN))
                        {
                            if (e.type == SDL_MOUSEBUTTONDOWN)
                            {
                                SDL_GetMouseState(&mouse_x, &mouse_y);            // getting position of cursor
                                if ((men->get_play() < mouse_x) && (mouse_x < (men->get_length("NEW GsME") + men->get_inst())))//limit of newgame button
                                {
                                    if ((269 < mouse_y) && (mouse_y < (269 + 47)))
                                    {

                                        restart=true;                            //restart variable set true
                                        once=false;
                                        screens=4;                               //game screen will be on


                                    }
                                    else if ((men->get_quit() < mouse_x) && (mouse_x < (men->get_length("QUIT") + men->get_quit())))
                                    {
                                        if ((612 < mouse_y) && (mouse_y < 612 + 52))
                                        {
                                            quit = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
			if(frog!=NULL && hive!=NULL)
			{
			    FM->SaveFile(que,frog);                                      //saves game

            }
            delete score;                                                   //deallocating memory
            delete scr;
            delete men;
            delete inst;
            delete win;
            delete lose;
            delete re;
            score=NULL;
            scr = NULL;
            men=NULL;
            inst= NULL;
            win = NULL;
            lose = NULL;
            re = NULL;


		}
	}

	//Free resources and close SDL
	close();

	return 0;
}

bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO  | SDL_INIT_AUDIO) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "Crappy Bird", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_mage Error: %s\n", IMG_GetError() );
					success = false;
				}
				//Initialize SDL_mixer
				if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
                    success = false;
                }
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load sprite sheet texture
	if( (!gSpriteSheetTexture.LoadFromFile( "images/frogsprite.png", gRenderer  ) ) ||  ( !gSpriteSheetTexture2.LoadFromFile( "images/main.png", gRenderer  )))
	{
		printf( "Failed to load sprite sheet texture!\n" );
		success = false;
	}
	//load background
	if( !gGroundTexture.LoadFromFile( "images/ground.png",gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
    //Load tree texture
	if( !gTreeTexture.LoadFromFile( "images/Tree.png",gRenderer ) )
	{
		printf( "Failed to load Tree texture!\n" );
		success = false;
	}
	//load tongue
	if( !gTongue.LoadFromFile( "images/tongue7.png",gRenderer ) )
	{
		printf( "Failed to load Tree texture!\n" );
		success = false;
	}
	//load health
	if( !gHealth.LoadFromFile( "images/health2.png",gRenderer ) )
	{
		printf( "Failed to load Tree texture!\n" );
		success = false;
	}
	//Load thorn texture
	if( !gThornTexture.LoadFromFile( "images/Thorn3.png",gRenderer ) )
	{
		printf( "Failed to load Thorn texture!\n" );
		success = false;
	}
	//Load Cactus texture
	if ( !gCactusTexture.LoadFromFile("images/Cactus.png",gRenderer))
    {
        printf( "Failed to load Cactus texture!\n" );
		success = false;
    }
    //Load Word texture
	if ( !gWordTexture.LoadFromFile("images/fontSprite.png",gRenderer))
    {
        printf( "Failed to load Word texture!\n" );
		success = false;
    }
    //load birds, bees and hive
    if( !gHive.LoadFromFile( "images/main.png",gRenderer ) )
	{
		printf( "Failed to load Tree texture!\n" );
		success = false;
	}
    //load music
    gMusic = Mix_LoadMUS( "21_sound_effects_and_music/beat.wav" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;

    }
     //load sound effects
    geffect = Mix_LoadWAV( "21_sound_effects_and_music/crash.wav" );
    if( geffect == NULL )
    {
        printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

    geat = Mix_LoadWAV( "21_sound_effects_and_music/eat.wav" );
    if( geat == NULL )
    {
        printf( "Failed to load high sound effect! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }


	return success;
}

void close()
{
	//Free loaded images
	gSpriteSheetTexture.Free();
	gSpriteSheetTexture2.Free();
	gGroundTexture.Free();
	gTreeTexture.Free();
	gTongue.Free();
	gHealth.Free();
	gHive.Free();
	gTreeTexture.Free();
	gThornTexture.Free();
	gWordTexture.Free();
	Mix_FreeMusic( gMusic );
	gMusic = NULL;
	Mix_FreeChunk( geffect );
	geffect=NULL;
	Mix_FreeChunk( geat );
	geat=NULL;

	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	Mix_Quit();
}
