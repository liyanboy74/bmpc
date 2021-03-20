/*
 By Liyanboy74
 https://github.com/liyanboy74
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "bmpc.h"

bmpc_screen_s Screen1;

int main(int argc, char** argv)
{
    bmpc_init(&Screen1,"Screen1",10,10);

    bmpc_draw_pixel(&Screen1,0,0,0xf00f);

    bmpc_update(&Screen1);
}