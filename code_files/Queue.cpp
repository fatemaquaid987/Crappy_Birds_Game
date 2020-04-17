#include"Queue.h"
#include<iostream>
#include "stdlib.h"
#include "stdio.h"
#include<fstream>



using namespace std;

Queue::Queue()
{
    head=NULL;
    tail=NULL;
    play=true;
    collide=true;
}

Queue::~Queue()
{
    while(head != NULL)
    {
        Node* temp = head;
        head = head->next;
        cout<<"Deallocating value: "<<temp->unit<<endl;
        delete temp;                                      //deallocates memory
    }
}

void Queue::Enqueue(Unit* unit)
{
    if(head == NULL)                                       //if theres no other node
    {
        head = new Node;
        head->unit = unit;
        head->next = NULL;
        head->prev = NULL;
        tail = head;
    }
    else
    {
        tail->next = new Node;                           //if theres already a node
        tail->next->unit = unit;
        tail->next->next = NULL;
        tail->next->prev = tail;
        tail = tail->next;
    }
}

void Queue::Update(long int& frame, SDL_Renderer* gRenderer, Unit* frog)
{
    Node* temp=head;
    while(temp!=NULL)
    {


           if (temp->unit->GetAlive()==false)
           {


            Node* dlt = temp;
            temp=temp->next;
            if (dlt->prev != NULL)
            {
                dlt->prev->next = dlt->next;
            }
            else
            {
                head = temp;
            }
            if (dlt->next != NULL)
            {
                dlt->next->prev = dlt->prev;
            }
            else
            {
                tail = dlt->prev;
            }
            delete dlt;
            dlt=NULL;

        }
        else
        {
            if (temp->unit->gettype()==4)
            {
                Unit* powerup = temp->unit->generatePowerup();
                if(powerup!=NULL)
                {
                    Enqueue(powerup);
                }
            }
            else if (temp->unit->gettype()==10)
            {
                Unit* bee=NULL;
                bee=temp->unit->generateBees();
                if (bee!=NULL)
                {Enqueue(bee);}

            }
            temp->unit->Move();
            temp->unit->Render(frame, gRenderer);
            temp=temp->next;
        }
    }

}


bool Queue::collision(SDL_Rect a, SDL_Rect b)
{
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = a.x;
    rightA = a.x + a.w;
    topA = a.y;
    bottomA = a.y + a.h;
    leftB = b.x;
    rightB = b.x + b.w;
    topB = b.y;
    bottomB = b.y + b.h;

    if( bottomA <= topB ) { return false; }
    if( topA >= bottomB ) { return false; }
    if( rightA <= leftB ) { return false; }
    if( leftA >= rightB ) { return false; }

    //If none of the sides from A are outside B
    return true;
}

void Queue :: Hit(Unit*frog, Mix_Chunk *geffect, Mix_Chunk* geat)
{
    Node* temp = head;
    SDL_Rect a = frog->getrect();
    SDL_Rect c= frog->returnt();
    while (temp!= NULL)
    {
        if (temp->unit->GetAlive() == true)
        {
            SDL_Rect b = temp->unit->getrect();

                if (temp->unit->gettype()== 1)
                {
                    if (collision(a,b) == true)
                    {
                        frog->addscore();
                        frog->sethealth(0, geat);
                        temp->unit->SetAlive(false);
                    }
                }
                else if (temp->unit->gettype()==2)
                {
                   if (collision(a,b) == true)
                    {
                        frog->sethealth(-1, geffect);
                        temp->unit->SetAlive(false);
                    }
                }
                else if ((temp->unit->gettype()==3) || (temp->unit->gettype()==5))
                {
                    if (collision(a,b) == true)
                    {
                        frog->sethealth(-20, geffect);
                        //play=false;
                    }

                }
                else if (temp->unit->gettype()==400)
                {

                    if ((collision(a,b)==true )&&(temp->unit->geteat()==false))
                    {
                        frog->sethealth(-1, geffect);
                        temp->unit->movey();
                        temp->unit->seteat(true);

                    }
                    else if ((collision(c, b)==true) && (c.w>3))
                    {
                        temp->unit->SetAlive(false);
                        Mix_PlayChannel( -1, geat, 0 );
                    }
                }


                else if (temp->unit->gettype()==10)
                {
                    if ((collision(c, b)==true )&&(c.w>3)&&(collide==true))
                    {
                        temp->unit->getDestroyed();
                        Mix_PlayChannel( -1, geat, 0 );
                        collide=false;

                    }
                }
        }
        temp=temp->next;
    }
}
void Queue:: switchcollision(bool c)
{
    this->collide=c;
}

void Queue :: Movex(int speedx)
{
    Node* temp = head;
    while (temp!= NULL)
    {
        if (temp->unit->gettype()!= 400)
        {
            temp->unit->shift(speedx);
        }
        temp=temp->next;
    }
}

void Queue::SaveGame(FILE* fw)
{
    char buff[50];
    Node* t = head;
    //if (t==head)

    while (t!=NULL)
    {

        if (t->unit->gettype()>0)
        {


        fputs(itoa(t->unit->gettype(),buff,10),fw);fputs("\n",fw);
        fputs(itoa(t->unit->getx(), buff, 10 ),fw);fputs("\n",fw);
        fputs(itoa(t->unit->gety(), buff, 10), fw);fputs("\n",fw);
        fputs(itoa(t->unit->GetAlive(), buff, 10), fw);fputs("\n",fw);
        fputs("End",fw);fputs("\n",fw);
        }
        t=t->next;

    }
}

