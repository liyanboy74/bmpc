#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "bmpc.h"

bmpc_screen_s Screen;

int main(int argc, char** argv)
{
    int i;
    char Buf[32];

    for(i=1;i<=10;i++)
    {
        sprintf(Buf,"frame-%d",i);
        bmpc_init(&Screen,Buf,100,100);

        bmpc_fill_rect(&Screen,0,0,i*10,i*10,RED);

        bmpc_update(&Screen);
        bmpc_free(&Screen);
    }
}