#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#include "bmpc.h"

bmpc_screen_s Screen;

void delay(int milli_seconds)
{
    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int main(int argc, char** argv)
{
    int i;
    bmpc_init(&Screen,"Screen",100,100);

    for(i=1;i<=100;i++)
    {
        bmpc_fill_rect(&Screen,0,0,i,i,RED);
        bmpc_update(&Screen);
        delay(100);
    }
    bmpc_free(&Screen);
}