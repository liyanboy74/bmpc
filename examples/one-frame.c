#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "bmpc.h"

bmpc_screen_s Screen;

int main(int argc, char** argv)
{
    bmpc_init(&Screen,"Screen",500,500);

    bmpc_fill_screen(&Screen,COLOR_GREEN);
    bmpc_fill_rect(&Screen,100,100,300,300,COLOR_BLUE);
    bmpc_draw_pixel(&Screen,250,250,COLOR_RED);
    bmpc_set_brightness(&Screen,80);

    bmpc_update(&Screen);
}