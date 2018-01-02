#include <iostream>
#include <graphics.h>
#include "drawings.h"
using namespace std;
void showGrid()
{
    for(int i=0;i<46;i++)
    for(int j=0;j<31;j++)
        snkRect(i,j);
}
int main()
{
    initwindow(900,600,"Snake -by masecla22",100,100);
    while(true)
    {

    }
    getch();
    return 0;
}
