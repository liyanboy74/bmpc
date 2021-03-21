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

    bmpc_init(&Screen1,"Screen1",5,5);

    bmpc_fill_screen(&Screen1,0x0f8f);
    bmpc_fill_rect(&Screen1,1,1,3,3,0x4df5);

    bmpc_update(&Screen1);
}