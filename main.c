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

    bmpc_init(&Screen1,"Screen1",9,9);

    bmpc_draw_pixel(&Screen1,4,4,0x1f);
    printf("%04x",bmcp_read_pixel(&Screen1,4,4));

    bmpc_update(&Screen1);
}