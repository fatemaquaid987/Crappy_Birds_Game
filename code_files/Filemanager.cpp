

#include "FileManager.h"
#include <SDL_mixer.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;


FileManager::FileManager()
{

}
Unit* FileManager::LoadFile(Unit* frog , Unit* tree, LTexture* b, LTexture* f, LTexture* c, LTexture* t, LTexture* g, Queue& Q)

{
    //initialize the counter integer, pointer to unit
    int counter=0;

    Unit* bird = NULL;
    Unit* cactus=NULL;
    Unit* fruit = NULL;
    Unit* rock = NULL;
    Unit* ground= NULL;
    Unit* bee=NULL;
    Unit* hive= NULL;
    Unit* thorn = NULL;


     FILE* fp;                     //Creating a file pointer, opening to read file
     char buff[50];
     fp=fopen("file.txt", "r");
     if (fp==NULL)               //if  file does not exist
     {
         perror("ERROR LOADING");
     }

    //initialize the variables
    int ty;
    float x;
    float y;
    int boolean;
    while(fgets(buff, 50, fp)!=NULL) //Loop until end of the file is reached
    {

        counter+=1;                   //counts the line in the file
        cout<<c<<endl;
    }
    fclose(fp);                       //close file
    fp=fopen("file.txt", "r");
     if (fp==NULL)
     {
         perror("ERROR LOADING");
     }

    for (int i=0; i<counter-7/5; i++ )        //Read the set of five lines for all the objects
    {


        fgets(buff, 50, (FILE*)fp);
        ty=atoi(buff);

        fgets(buff, 50, (FILE*)fp);
        x=atoi(buff);

        fgets(buff, 50, (FILE*)fp);
        y=atoi(buff);

        fgets(buff, 50, (FILE*)fp);
        boolean=atoi(buff);

        fgets(buff, 50, (FILE*)fp);
        //Getting each type and creating object according to type, using x, y information from the file
        //Enqueue each created object
         if (ty==1)
        {
            fruit=new Fruit(f, x, y);
            cout<<"fruit"<<endl;

            Q.Enqueue(fruit);
        }
         else if (ty==2)
        {
            rock=new Rock(f, x, y);
            cout<<"rock"<<endl;

            Q.Enqueue(rock);
        }
        else if (ty==3)
        {
            thorn=new Thorn(t, x, y);
            cout<<"bird"<<endl;

            Q.Enqueue(thorn);
        }


        else if (ty==4)
        {
            bird=new Bird(b, f, x, y);
            cout<<"bird"<<endl;

            Q.Enqueue(bird);
        }
        else if (ty==5)
        {
            cactus= new Cactus(c, x, y);
            cout<<"cac"<<endl;

            Q.Enqueue(cactus);
        }

         else if (ty==7)
        {
            tree=new Tree(g, x, y);
            cout<<"tree"<<endl;

            Q.Enqueue(tree);
        }
         else if (ty==10)
        {
            hive=new Hive(b, x, y);
            cout<<"hive"<<endl;
            hive->setTarget(frog);

            Q.Enqueue(hive);

        }
         else if (ty==400)
        {
            bee=new Bee(b, x, y);
            cout<<"bee"<<endl;
            bee->setTarget(frog);

            Q.Enqueue(bee);
        }


    }

    return hive;
}
void FileManager::SaveFile( Queue& Q, Unit* unit)
{

    FILE* fw;                 //Creating a file pointer, opening to write file
    char buff[50];
    fw=fopen("file.txt", "w");

    if (fw==NULL)              //File not created
    {
        perror("ERROR");

    }
    //Store information of objects from queue
    Q.SaveGame(fw);

    //Put information of player in a file
    fputs(itoa(unit->gettype(),buff,10), (FILE*)fw);fputs("\n",(FILE*)fw);
    fputs(itoa(unit->getx(),buff,10), (FILE*)fw);fputs("\n",(FILE*)fw);
    fputs(itoa(unit->gety(),buff,10), (FILE*)fw);fputs("\n", (FILE*)fw);
    fputs(itoa(unit->gethealth(), buff, 10), (FILE*)fw);fputs("\n", (FILE*)fw);
    fputs(itoa(unit->getcondition(), buff, 10), (FILE*)fw);fputs("\n", (FILE*)fw);
    fputs(itoa(unit->getjump(), buff, 10), (FILE*)fw);fputs("\n",(FILE*)fw);
    fputs(itoa(unit->getscore(), buff, 10), (FILE*)fw);fputs("\n", (FILE*)fw);

    fclose(fw); //closing the file


}
Unit* FileManager:: LoadPlayer(LTexture* f, Mix_Chunk* geffect)
{
    //Player information in the file
    int ty;
    float x1;
    float y1;
    int h;
    int con;
    int jump;
    int score;
    int counter=0;
    Unit* unit;

    FILE* fp;    //read the file through file pointer
     char buff[50];
     fp=fopen("file.txt", "r");   //open as read only mode
     if (fp==NULL)
     {
         perror("ERROR LOADING");
     }

     while(fgets(buff, 50, fp)!=NULL) //Loop until end of the file is reached
    {

        counter+=1;                   //counts the line in the file

    }
    fclose(fp);
    fp=fopen("file.txt", "r");

    for( int i=0; i<counter-7; i++)   //ignore the last seven lines
    {
        fgets(buff, 50, fp);
    }
    //read for last seven lines, information of the frog
    fgets(buff, 50 , fp);
    ty=atoi(buff);
    cout<<ty<<endl;

    fgets(buff, 50 , fp);
    x1=atoi(buff);
    cout<<x1<<endl;

    fgets(buff, 50 , fp);
    y1=atoi(buff);

    fgets(buff, 50, fp);
    h=atoi(buff);

    fgets(buff, 50, fp);
    con=atoi(buff);

    fgets(buff, 50, fp);
    jump=atoi(buff);

    fgets(buff, 50, fp);
    score=atoi(buff);

   // Mix_Chunk* gbee;
    Unit* frog= new Frog(f, x1, y1);
    frog->sethealth(h, geffect);
    frog->setcondition(con);
    frog->setjump(jump);
    frog->setscore(score);
    return frog;
}













