#include <iostream>
#include <graphics.h>
#include <winuser.h>
#include "drawings.h"
using namespace std;
void showGrid()
{
    for(int i=0; i<46; i++)
        for(int j=0; j<31; j++)
            snkRect(i,j);
}
int main()
{
    initwindow(900,600,"Snake -by masecla22",100,100);
    int drect=UP;
    snake player;
    player.lenght=9;
    player.init();
    food eats[10];
    for(int i=0; i<10; i++)
    {
        eats[i].init();
        eats[i].drawIt();

    }
    int a=2;
    player.flip();
    while(true)
    {
        //showGrid();
        if(GetAsyncKeyState(VK_UP)!=0 && drect!=DOWN)
            drect=UP;
        if(GetAsyncKeyState(VK_DOWN)!=0&& drect!=UP)
            drect=DOWN;
        if(GetAsyncKeyState(VK_LEFT)!=0&& drect!=RIGHT)
            drect=LEFT;
        if(GetAsyncKeyState(VK_RIGHT)!=0&& drect!=LEFT)
            drect=RIGHT;
        player.drawIt();
        Sleep(100);
        player.nextMove(drect);
        cleardevice();
        player.drawIt();
        player.detectColision(eats);
        for(int i=0; i<10; i++)
            eats[i].drawIt();
        a++;
    }
    getch();
    return 0;
}
