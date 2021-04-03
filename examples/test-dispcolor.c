#include <stdio.h>
#include <string.h>
#include <dispcolor.h>

int main()
{
    dispcolor_Init(240,240);
    dispcolor_ClearScreen();
    dispcolor_DrawCircle(120,120,100,RED,1);
    dispcolor_Update();
    return 0;
}