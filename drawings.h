#include <graphics.h>
#include <iostream>
#include <cmath>

using namespace std;

int snkRect(int x,int y)
{
    x--;
    y--;
    rectangle(x*20,y*20,x*20+20,y*20+20);
}
int snkColor(int x,int y)
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


struct snake
{
    int lenght;
    cord poss[100];
    int drawIt()
    {
        for(int i=0; i<lenght; i++)
        {
            snkColor(poss[i].x,poss[i].y);
        }
    }



};

struct food {



};
