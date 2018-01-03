#include <graphics.h>
#include <iostream>
#include <cmath>
#include <ctime>
#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4



using namespace std;
int random(int min, int max)
{
    if(min==max)
        return min;
    static bool first = true;
    if ( first )
    {
        srand(time(NULL));
        first = false;
    }
    return min + rand() % (max - min);
}
struct cord
{
    int x,y;
};
struct food
{
    cord pos;
    void init()
    {
        pos.x=random(0,44);
        pos.y=random(0,29);
    }
    void drawIt()
    {
        ellipse(pos.x*20+10,pos.y*20+10,360,360,10,10);
    }

};

///getPos - done
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

/// snkRect - done
void snkRect(int x,int y)
{
    x--;
    y--;
    rectangle(x*20,y*20,x*20+20,y*20+20);
}

///snkColor - done
void snkColor(int x,int y)
{
    x--;
    y--;
    for(int i=0; i<20; i++)
    {
        line(x*20,y*20+i,x*20+20,y*20+i);
    }
}

void moves(cord poss[100],int lenght, int direct)
{
    cord newArray[100];
    for(int i=0; i<lenght; i++)
        newArray[i+1]=poss[i];
    newArray[0]=getPos(poss[0],direct);
    for(int i=0; i<lenght; i++)
        poss[i]=newArray[i];
}

struct snake
{
    int lenght;
    cord poss[100];
    void drawIt()
    {
        for(int i=0; i<lenght; i++)
            snkRect(poss[i].x,poss[i].y);
    }
    void nextMove(int direction)
    {
        moves(poss,lenght,direction);
    }
    void init()
    {
        for(int i=5; i<(lenght+5); i++)
        {
            poss[i].x=(i+1);
            poss[i].y=3;
        }
    }
    cord getHead()
    {
        return poss[0];
    }
    void detectColision(food eat[100])
    {
        for(int i=0; i<lenght; i++)
        {
            if(getHead().x==eat[i].pos.x && getHead().y==eat[i].pos.y)
            {
                lenght++;
                eat[i].init();
                eat[i].drawIt();
            }
            if(getHead().x==poss[i].x&&getHead().y==poss[i].y)
            {
                cout<<"COLLISION IN SNAKE DETECT."<<endl;
            }
        }
        if(getHead().y<=0)
            poss[0].y=30;
    }
    void flip()
    {
        cord newArray[100];
        for(int i=(lenght-1); i>=0; i--)
            newArray[i]=poss[(lenght-i)];
        for(int i=0; i<lenght; i++)
            poss[i]=newArray[i];
    }
};

