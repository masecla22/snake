#include <graphics.h>
#include <iostream>
#include <cmath>
#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4



using namespace std;


cord getPos(cord pos,int direct)
{
    if(direct==UP)
        pos.y--;
    if(direct==DOWN)
        pos.y++;
    if(direct==LEFT)
        pos.x--;
    if(direct==RIGHT)
        pos.x++;
    return pos;
}


void snkRect(int x,int y)
{
    x--;
    y--;
    rectangle(x*20,y*20,x*20+20,y*20+20);
}
void snkColor(int x,int y)
{
    x--;
    y--;
    for(int i=0; i<20; i++)
    {
        line(x*20,y*20+i,x*20+20,y*20+i);
    }
}


struct cord
{
    int x,y;
};
struct food
{
    cord pos;
    void drawIt()
    {
        ellipse(pos.x*20+10,pos.y*20+10,360,360,10,10);
    }

};
void moveUp(cord poss[100],int lenght)
{
    cord newArray[100];
    for(int i=0;i<lenght;i++)
    {
        newArray[i+1]=poss[i];
    }
    newArray[0]=getPos(poss[0],UP);
}









struct snake
{
    int lenght;
    cord poss[100];
    void drawIt()
    {
        for(int i=0; i<lenght; i++)
            snkColor(poss[i].x,poss[i].y);
    }
    void nextMove(int direction)
    {
        if(direction==1)
        {
            moveUp(poss,lenght);
        }
    }
};

